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

static void			cleanup(char *line, char **args, char **envp)
{
	int		i;

	if (line)
		free(line);
	i = 0;
	if (args)
	{
		while (args[i])
			free(args[i++]);
		free(args);
	}
	i = 0;
	if (envp)
	{
		while (envp[i])
			free(envp[i++]);
		free(envp);
	}
	return ;
}

static t_builtin	*populate_builtin_functions(void)
{
	t_builtin		*builtins;

	builtins = (t_builtin *)malloc(sizeof(t_builtin) * 6);
	builtins[0].name = "cd";
	builtins[0].function = &minishell_cd;
	builtins[1].name = "exit";
	builtins[1].function = &minishell_exit;
	builtins[2].name = "env";
	builtins[2].function = &minishell_env;
	builtins[3].name = "setenv";
	builtins[3].function = &minishell_setenv;
	builtins[4].name = "unsetenv";
	builtins[4].function = &minishell_unsetenv;
	builtins[5].name = "echo";
	builtins[5].function = &minishell_echo;
	return (builtins);
}

void				minishell_loop(t_builtin *builtins, char **envp)
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
		status = minishell_exec(args, builtins, envp);
		// cleanup
		cleanup(line, args, NULL);
	}
	cleanup(line, args, envp);
	return ;
}

int					main(int argc, char **argv)
{
	char		**envp;
	t_builtin	*builtins;

	envp = observe_environment();
	builtins = populate_builtin_functions();
	minishell_loop(builtins, envp);
	return (EXIT_SUCCESS);
}
