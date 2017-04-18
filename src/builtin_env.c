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

char		**build_new_env(char **args, char **env)
{
	int		i;
	int		len;
	char	**new_env;

	i = 0;
	len = 0;
	while (is_valid_env_var(args[len]))
		len++;
	new_env = (char **)malloc(sizeof(char *) * (len + 1));
	ft_bzero(new_env, sizeof(char *) * (len + 1));
	while (is_valid_env_var(args[i]))
	{
		new_env[i] = ft_strdup(args[i]);
		i++;
	}
	return (new_env);
}

char		**build_new_args(char **args)
{
	char	**new_args;

	while (is_valid_env_var(*args))
		args++;
	new_args = ft_tab_dup(args);
	return (args);
}

int			env_i(char **args, char **env)
{
	char	**tmp_env;
	char	**tmp_args;
	int		status;

	if (!args[2] || !is_valid_env_var(args[2]))
	{
		ft_putstr_fd("usage: env -i var1=new_var ...", 2);
		return (MINISHELL_CONTINUE);
	}
	tmp_env = build_new_env(&args[2], env);
	tmp_args = build_new_args(&args[2]);
	status = minishell_launcher(tmp_args, tmp_env);
	cleanup(NULL, NULL, &tmp_args, &tmp_env);
	return (status);
}

int			env_u(char **args, char **env)
{
	char	**tmp_env;
	char	**tmp_args;
	int		status;

	if (!args[2] || !is_valid_env_var(args[2]))
	{
		ft_putstr_fd("usage: env -u env-var-to-omit ...", 2);
		return (MINISHELL_CONTINUE);
	}
	tmp_env = ft_tab_dup(env);
	find_and_remove_env(args[2], &tmp_env);
	tmp_args = ft_tab_dup(&args[2]);
	status = minishell_launcher(tmp_args, tmp_env);
	cleanup(NULL, NULL, &tmp_args, &tmp_env);
	return (status);
}

int			builtin_env(char **args, char **env)
{
	char	**tmp_env;
	char	**tmp_args;
	int		status;

	if (args[1][0] == '-' && args[1][1] == 'u')
		status = env_u(args, env);
	else if (args[1][0] == '-' && args[1][1] == 'i' && args[2])
		status = env_i(args, env);
	else if (env && *env)
		ft_print_tab(env);
	else
		ft_putstr_fd("no environment defined\n", 2);
	return (MINISHELL_CONTINUE);
}
