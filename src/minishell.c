/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:44:49 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/26 13:16:20 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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

static void			init_to_null(char **line, char ***com, char ***args)
{
	*line = NULL;
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
	char		*line;
	char		**args;
	char		**commands;
	char		**commands_begin;

	init_to_null(&line, &commands_begin, &args);
	status = MINISHELL_CONTINUE;
	while (status != MINISHELL_EXIT)
	{
		ft_putstr("Meh$H> ");
		get_next_line(0, &line);
		separate_multiple_commands(&commands, &line);
		commands_begin = commands;
		while (status != MINISHELL_EXIT && commands && *commands)
		{
			*commands = expand_shell_vars(*commands, env);
			args = ft_strtok(*(commands++), " ");
			status = minishell_launcher(args, &env);
			cleanup(NULL, NULL, &args, NULL);
		}
		cleanup(&line, &commands_begin, &args, NULL);
	}
	cleanup(&line, &commands_begin, &args, &env);
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
	signal(SIGINT, restart_minishell);
	env = ft_tab_dup(envp);
	minishell_loop(env);
	return (EXIT_SUCCESS);
}
