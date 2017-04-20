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

void				minishell_loop(char **env)
{
	int			status;
	char		*line;
	char		**args;
	char		**commands;
	char		**commands_begin;

	status = MINISHELL_CONTINUE;
	while (status != MINISHELL_EXIT)
	{
		commands = NULL;
		args = NULL;
		line = NULL;
		// print prompt
		ft_putstr("===D~ ");
		// read command from std input
		get_next_line(0, &line);
		// split line into multiple commands seperated by a semicolon
		commands = ft_strtok(line, ";");
		while (status != MINISHELL_EXIT && commands && *commands)
		{
			*commands = expand_shell_vars(*commands, env);
			commands_begin = commands;
			// break command into a program and args - not sure about that * syntax
			args = ft_strtok(*(commands++), " ");
			// execute program
			status = minishell_launcher(args, &env);
			// cleanup
			cleanup(NULL, NULL, &args, NULL);
		}
		cleanup(&line, &commands_begin, &args, NULL);
	}
	cleanup(NULL, NULL, NULL, &env);
	return ;
}

int					main(int argc, char **argv, char **envp)
{
	char		**env;

	if (argc && argv)
		argc++;

	env = ft_tab_dup(envp);
	minishell_loop(env);
	return (EXIT_SUCCESS);
}
