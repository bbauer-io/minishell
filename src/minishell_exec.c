/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 18:44:49 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/25 15:27:50 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
** Checks if the command issued was a builtin function and, if so, will launch
** the corresponding function.
*/

static int			minishell_builtin(char **args, char ***env)
{
	if (ft_strequ(args[0], "cd"))
		return (builtin_cd(args, env));
	else if (ft_strequ(args[0], "exit"))
		return (MINISHELL_EXIT);
	else if (ft_strequ(args[0], "env"))
		return (builtin_env(args, env));
	else if (ft_strequ(args[0], "setenv"))
		return (builtin_setenv(args, env));
	else if (ft_strequ(args[0], "unsetenv"))
		return (builtin_unsetenv(args, env));
	else if (ft_strequ(args[0], "echo"))
		return (builtin_echo(args));
	else if (ft_strequ(args[0], "dickbutt"))
		return (builtin_db());
	else if (ft_strequ(args[0], "clear"))
		return (builtin_clear());
	else if (ft_strequ(args[0], "pwd"))
		return (builtin_pwd());
	else
		return (NOT_BUILTIN);
}

/*
** First checks that a command is present, then calls the tests for builtin
** commands. If it is not a builtin command we try to match the command to a
** program located in the env specified $PATH. Then we call minishell_exec()
** or return with an error message if the program can't be found.
*/

int					minishell_launcher(char **args, char ***env)
{
	int			status;
	char		*confirmed_path;

	confirmed_path = NULL;
	if (args[0] == NULL || *(args[0]) == '\0')
		return (MINISHELL_CONTINUE);
	if ((status = minishell_builtin(args, env)) == NOT_BUILTIN)
	{
		confirmed_path = verify_program_exists(args, env);
		if (confirmed_path)
		{
			status = minishell_exec(args, env, confirmed_path);
			ft_strdel(&confirmed_path);
		}
		else
		{
			ft_putstr_fd("minishell: program not found!: ", 2);
			ft_putendl_fd(args[0], 2);
		}
		return (status != 2 ? status : MINISHELL_CONTINUE);
	}
	return (status);
}

/*
** Will attempt to find the program file specified before forking and execve().
** The parent will wait for the child to exit before returning to the main loop
** to wait for another command.
*/

int					minishell_exec(char **args, char ***env, char *path)
{
	pid_t		pid;
	int			status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(path, args, *env) == -1)
			ft_putstr_fd("minishell: execve() failed!\n", 2);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		ft_putstr_fd("minishell: fork() error!\n", 2);
	else
	{
		waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			waitpid(pid, &status, WUNTRACED);
	}
	return (MINISHELL_CONTINUE);
}
