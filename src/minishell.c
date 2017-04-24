/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:44:49 by bbauer            #+#    #+#             */
/*   Updated: 2017/03/21 19:23:45 by bbauer           ###   ########.fr       */
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

void				init_to_null(char **line, char ***com, char ***env)
{
	*line = NULL;
	*com = NULL;
	*env = NULL;
}

/*
** The main control function for minishell. Should loop forever.
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
		commands = ft_strtok(line, ";");
		while (status != MINISHELL_EXIT && commands && *commands)
		{
			*commands = expand_shell_vars(*commands, env);
			commands_begin = commands;
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

	env = ft_tab_dup(envp);
	minishell_loop(env);
	return (EXIT_SUCCESS);
}
