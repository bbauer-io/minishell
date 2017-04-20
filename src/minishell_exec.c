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

int					minishell_builtin(char **args, char ***env)
{
	if (ft_strequ(args[0], "cd") && args[0][3] == '\0')
		return (builtin_cd(args, env));
	else if (ft_strequ(args[0], "exit") && args[0][5] == '\0')
		return (MINISHELL_EXIT);
	else if (ft_strequ(args[0], "env") && args[0][4] == '\0')
		return (builtin_env(args, env));
	else if (ft_strequ(args[0], "setenv") && args[0][7] == '\0')
		return (builtin_setenv(args, env));
	else if (ft_strequ(args[0], "unsetenv") && args[0][9] == '\0')
		return (builtin_unsetenv(args, env));
	else if (ft_strequ(args[0], "echo") && args[0][5] == '\0')
		return (builtin_echo(args));
	else if (ft_strequ(args[0], "dickbutt") && args[0][9] == '\0')
		return (builtin_db());
	else
		return (NOT_BUILTIN);
}

int					minishell_launcher(char **args, char ***env)
{
	int			status;

	// If empty command was issued...
	if (args[0] == NULL || *(args[0]) == '\0')
		return (MINISHELL_CONTINUE);
	// Check if command is a builtin function
	if ((status = minishell_builtin(args, env)) == NOT_BUILTIN)
		return (minishell_exec(args, env));
	else
		return (status);
}

int					minishell_exec(char **args, char ***env)
{
	pid_t	pid;
	pid_t	wpid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		// Child process
		// CHANGE PROCESS NAME HERE? -- (args[0] ???)
		if (execve(args[0], args, *env) == -1)
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
