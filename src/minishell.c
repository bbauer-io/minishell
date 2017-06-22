/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:44:49 by bbauer            #+#    #+#             */
/*   Updated: 2017/06/22 15:37:10 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char			*g_line;

/*
** Frees the variables passed in and sets their values to NULL.
*/

void				cleanup(char **line, char ***com, char ***args, char ***env)
{
	if (line)
		ft_strdel(line);
	line = NULL;
	if (com)
		ft_tab_del(com);
	com = NULL;
	if (args)
		ft_tab_del(args);
	args = NULL;
	if (env)
		ft_tab_del(env);
	env = NULL;
	return ;
}

static void			init_to_null(char **line, char ***com, char ***com_beg,
																char ***args)
{
	*line = NULL;
	*com_beg = NULL;
	*com = NULL;
	*args = NULL;
}

/*
** The main control function for minishell. Should loop forever, and never leak.
** Each time a pointer is passed to cleanup() it's value is set to NULL.
*/

void				minishell_loop(char **env)
{
	int			status;
	char		**args;
	char		**commands;
	char		**commands_begin;

	status = MINISHELL_CONTINUE;
	while (status != MINISHELL_EXIT)
	{
		init_to_null(&g_line, &commands, &commands_begin, &args);
		status = minishell_prompt(&g_line);
		separate_multiple_commands(&commands, &g_line);
		commands_begin = commands;
		while (status != MINISHELL_EXIT && commands && *commands && **commands)
		{
			separate_multiple_args(&args, commands++);
			expand_shell_vars(args, env);
			status = minishell_launcher(args, &env);
			cleanup(NULL, NULL, &args, NULL);
		}
		cleanup(&g_line, &commands_begin, &args, NULL);
	}
	cleanup(&g_line, &commands_begin, &args, &env);
	return ;
}

/*
** Minishell entry point. Copies envp and that's about it.
*/

int					main(int argc, char **argv, char **envp)
{
	char		**env;

	if (argc && argv)
		argc++;
	env = ft_tab_dup(envp);
	update_shell_level_env_var(&env);
	update_shell_env_var(&env);
	signal(SIGINT, SIG_IGN);
	minishell_loop(env);
	return (EXIT_SUCCESS);
}
