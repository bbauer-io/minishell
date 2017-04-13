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

static void			cleanup(char *line, char ***args, char ***env)
{
	ft_strdel(&line);
	ft_tab_del(args);
	ft_tab_del(env);
	return ;
}

void				minishell_loop(char **env)
{
	int			status;
	char		*line;
	char		**args;

	status = 1;
	while (status)
	{
		args = NULL;
		line = NULL;
		// print prompt
		ft_putstr("===D~ ");
		// read command from std input
		get_next_line(0, &line);
		// break line into a program and args
		args = ft_strtok(line, " ");
		// execute program
		status = minishell_exec(args, env);
		// cleanup
		cleanup(line, &args, NULL);
	}
	cleanup(line, &args, &env);
	return ;
}

int					main(int argc, char **argv, char **envp)
{
	char		**env;

	env = ft_tab_dup(envp);
	minishell_loop(env);
	return (EXIT_SUCCESS);
}
