/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:44:49 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/13 19:23:45 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void		find_and_remove_env(char *key, char ***env)
{
	int		i;
	int		tab_len;
	char	**new_env;

	tab_len = 0;
	while ((*env)[i++])
		tab_len++;
	i = 0;
	while ((*env)[i])
	{
		if (ft_strequ((*env)[i], key) && (*env)[i][ft_strlen(key)])
		{
			new_env = ft_tab_rem_one(*env, i);
			ft_tab_del(env);
			*env = new_env;
			return ;
		}
		i++;
	}
	return ;
}

void		add_to_env(char *keyvalpair, char ***env)
{
	char	**new_env;

	new_env = ft_tab_add_one(*env, keyvalpair);
	ft_tab_del(env);
	*env = new_env;
	return ;
}

int			builtin_env(char **args, char **env)
{
	char	**tmp_env;
	char	**tmp_args;
	int		ret;

	if (args[1][0] == '-' && args[1][1] == 'u' && args[2])
	{
		tmp_env = ft_tab_dup(env);
		find_and_remove_env(args[2], &tmp_env);
		tmp_args = ft_tab_dup(&args[2]);
		ret = minishell_launcher(tmp_args, tmp_env);
		ft_tab_del(&tmp_env);
		ft_tab_del(&tmp_args);
		return (ret);
	}
	else
		ft_print_tab(env);
	return (MINISHELL_CONTINUE);
}

/*
** Set an environment variable!
** If an env var specified is in the list, delete it first, then add the new
** key=value string.
*/

int			builtin_setenv(char **args, char **env)
{
	int		i;
	int		k;
	int		vlen;
	char	*key;

	i = 0;
	vlen = 0;
	while (args[i])
	{
		k = 0;
		key = ft_strcdup(args[i], '=');
		find_and_remove_env(key, &env);
		add_to_env(args[i], &env);
		free(key);
		i++;
	}
	return (MINISHELL_CONTINUE);
}

/*
** Deletes a stored environment variable
*/

int			builtin_unsetenv(char **args, char **env)
{
	int		i;

	i = 0;
	while (args[++i])
		find_and_remove_env(args[i], &env);
	return (MINISHELL_CONTINUE);
}
