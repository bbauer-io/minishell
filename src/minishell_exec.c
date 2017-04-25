/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 18:44:49 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/24 15:25:03 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char				*verify_program_exists(char **args, char ***env)
{
	char		*confirmed_path;
	char		*relative_path;

	relative_path = NULL;
	confirmed_path = NULL;
	if (args[0][0] != '.' && args[0][0] != '/' && ft_strchr(args[0], '/'))
	{
		relative_path = ft_strnew(ft_strlen(args[0] + 2));
		ft_strcpy(relative_path, "./");
		ft_strcat(relative_path, args[0]);
	}
	if (args[0][0] != '.' && args[0][0] != '/')
		confirmed_path = search_paths_for_program(env, args[0]);
	else if (access(args[0], X_OK) == 0)
		confirmed_path = ft_strdup(args[0]);
	else if (relative_path && access(relative_path, X_OK) == 0)
		confirmed_path = ft_strdup(args[0]);
	if (relative_path)
		ft_strdel(&relative_path);
	return (confirmed_path);
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
	//	if (args[0][0] != '.' && args[0][0] != '/')
	//		confirmed_path = search_paths_for_program(env, args[0]);
	//	else if (access(args[0], X_OK) == 0 || access(args[0])
	//		confirmed_path = ft_strdup(args[0]);
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
	int status;

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
