/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 18:44:49 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/11 19:23:45 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int					minishell_exec(char **args, t_builtin *builtins, char **envp)
{
	int			i;
	int			num_of_builtins;
	int			is_builtin;

	// If empty command was issued...
	if (args[0] == NULL)
		return (MINISHELL_CONTINUE);

	// Check if command is a builtin function
	i = 0;
	num_of_builtins = N_ELEMS(builtins);
	while (i < num_of_builtins)
	//	if (is_builtin(argv[1]))
	//		return (execute_builtin(argv, envp));
		if (ft_strequ(args[1], builtins[i].name))
			return (builtins[i].function(args, envp));

	// Else fork and launch the specified program!
	return (minishell_launcher(args, envp));
}

int					minishell_launcher(char **args, char **envp)
{
	pid_t	pid;
	pid_t	wpid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		// Child process
		// CHANGE PROCESS NAME HERE -- (args[0] ???)
		if (execve(args[0], args, envp) == -1)
			ft_putstr_fd("minishell: execve() failed!", 2);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		ft_putstr_fd("minishell: fork() error!", 2);
	else
	{
		// Parent process
		wpid = waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			wpid = waitpid(pid, &status, WUNTRACED);
	}
	return (MINISHELL_CONTINUE);
}
