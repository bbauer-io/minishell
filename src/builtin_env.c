/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:44:49 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/01 23:25:18 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
	if (!args[i])
		ft_print_tab(tmp_env);
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

	i = 2;
	if (!args[i] || !env_var_is_set(args[i], env))
	{
		ft_putstr_fd("usage: env -u [OMIT NAMES ...] program [args ...]\n", 2);
		return (MINISHELL_CONTINUE);
	}
	tmp_env = ft_tab_dup(env);
	while (env_var_is_set(args[i], tmp_env))
		find_and_remove_env(args[i++], &tmp_env);
	tmp_args = ft_tab_dup(&args[i]);
	status = minishell_launcher(tmp_args, &tmp_env);
	cleanup(NULL, NULL, &tmp_args, &tmp_env);
	return (status);
}

/*
** Launches a program with additional temporary env variables (or just prints
** the temporary environment if no program is specified)
*/

static int		env_standard(char **args, char **env)
{
	int		status;
	char	**tmp_env;
	char	**tmp_args;

	status = MINISHELL_CONTINUE;
	tmp_args = NULL;
	tmp_env = ft_tab_dup(env);
	while (is_valid_env_var(*(++args)))
		add_to_env(*args, &tmp_env);
	if (*args)
	{
		tmp_args = ft_tab_dup(args);
		status = minishell_launcher(tmp_args, &tmp_env);
	}
	else if (tmp_env && *tmp_env)
		ft_print_tab(tmp_env);
	else
		ft_putstr_fd("no environment found! where am i!? heeeeeellp!\n", 2);
	cleanup(NULL, NULL, &tmp_args, &tmp_env);
	return (status);
}

/*
** For launching programs with a modified environment.
*/

int				builtin_env(char **args, char ***env)
{
	int		status;

	status = MINISHELL_CONTINUE;
	if (args[1] && args[1][0] == '-' && args[1][1] == 'u')
		status = env_u(args, *env);
	else if (args[1] && args[1][0] == '-' && args[1][1] == 'i' && args[2])
		status = env_i(args);
	else if (args[1])
		status = env_standard(args, *env);
	else if (env && *env && **env)
		ft_print_tab(*env);
	else
		ft_putstr_fd("no environment found! where am i!? heeeeeellp!\n", 2);
	return (status);
}
