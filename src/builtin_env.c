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

/*
** Creates a new environment table from the consecutive valid key-value pairs
** at the beginning of **args (i pass this function args[2] so it can start
** at the beginning of the list here.
*/

static char		**build_new_env(char **args)
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
	new_env[i] = NULL;
	return (new_env);
}

/*
** Used to create a new table of args to use when launching a program from env
** (so that it will not include the env command and its options)
*/

static char		**build_new_args(char **args)
{
	char	**new_args;

	while (is_valid_env_var(*args))
		args++;
	new_args = ft_tab_dup(args);
	return (new_args);
}

/*
** The "env -i" command launches a program with an environment defined only
** by key=value pairs immediately following the -i. The first argument after the
** last valid key=value pair is assumed to be the program to launch.
*/

static int		env_i(char **args)
{
	char	**tmp_env;
	char	**tmp_args;
	int		status;
	int		i;

	if (!args[2])
	{
		ft_putstr_fd("usage: env -i [VAR1=ONE ...] program [args ...]\n", 2);
		return (MINISHELL_CONTINUE);
	}
	tmp_env = build_new_env(&args[2]);
	i = 2;
	while (is_valid_env_var(args[i]))
		i++;
	if (args[i] && args[i + 1])
		i++;
	tmp_args = build_new_args(&args[i]);
	status = minishell_launcher(tmp_args, &tmp_env);
	cleanup(NULL, NULL, &tmp_args, &tmp_env);
	return (status);
}

/*
** The "env -u" command launches a program with the normal environment, but
** without the keys that hte user specifies after -u. Keys must not contain the
** '=' character.
*/

static int		env_u(char **args, char **env)
{
	char	**tmp_env;
	char	**tmp_args;
	int		status;
	int		i;
	char	*ret;

	i = 2;
	ret = NULL;
	if (!args[i] || !lookup_env_value(args[i], env))
	{
		ft_putstr_fd("usage: env -u [OMIT NAMES ...] program [args ...]\n", 2);
		return (MINISHELL_CONTINUE);
	}
	ret ? ft_strdel(&ret) : NULL;
	tmp_env = ft_tab_dup(env);
	while ((ret = lookup_env_value(args[i], tmp_env)))
		find_and_remove_env(args[i++], &tmp_env);
	ret ? ft_strdel(&ret) : NULL;
	tmp_args = ft_tab_dup(&args[i]);
	status = minishell_launcher(tmp_args, &tmp_env);
	cleanup(NULL, NULL, &tmp_args, &tmp_env);
	return (status);
}

/*
** For launching programs with a modified environment.
*/

int			builtin_env(char **args, char ***env)
{
	int		status;

	status = MINISHELL_CONTINUE;
	if (args[1] && args[1][0] == '-' && args[1][1] == 'u')
		status = env_u(args, *env);
	else if (args[1] && args[1][0] == '-' && args[1][1] == 'i' && args[2])
		status = env_i(args);
	else if (env && *env && **env)
		ft_print_tab(*env);
	else
		ft_putstr_fd("no environment found! where am i!? heeeeeellp!\n", 2);
	return (status);
}
