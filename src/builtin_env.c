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

void		find_and_remove_key(char *key, char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strequ(env[i], key) && env[i][ft_strlen(key)])
			free(env[i]);
		i++;
	}
	return ;
}

int			builtin_env(char **args, char **env)
{
	int		i;

	i = 0;
	while (args[i])
	{
		if (args[i][0] == '-')
			if (args[i][1] == 'u')
				builtin_unsetenv(
		i++;
	}
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
		while (env[k] && !ft_strequ(env[k], key))
			k++;
		if (ft_strequ(env[k], key))
			free(env[k]);
		env[k] = ft_strdup(args[i]);
		free(key);
		i++;
	}
	return (MINISHELL_CONTINUE);
}

int			builtin_unsetenv(char **args, char **env)
{
	//	If env var is present
	//		Remove it
	return (MINISHELL_CONTINUE);
}

