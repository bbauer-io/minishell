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

/*
** Checks if the command issued was a builtin function and, if so, will launch
** the corresponding function.
*/

int					minishell_builtin(char **args, char ***env)
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
** Lookup the $PATH env var and split it into a table of strings.
*/

char				**path_lookup(char ***env)
{
	char		**path_tab;
	char		*path_str;

	path_tab = NULL;
	path_str = NULL;
	path_str = lookup_env_value("PATH", *env);
	if (!path_str)
		return (NULL);
	path_tab = ft_strsplit(path_str, ':');
	ft_strdel(&path_str);
	return (path_tab);
}

/*
** Checks all the paths in the PATH env var for an executable file with then
** specified name and returns the first one it finds.
*/

static char			*search_paths_for_program(char ***env, char *prog_name)
{
	char		*path_str;
	char		**path_tab;
	int			found;
	int			i;

	path_tab = path_lookup(env);
	i = 0;
	found = 0;
	while (path_tab[i] && !found)
	{
		path_str = ft_strnew(ft_strlen(path_tab[i]) + ft_strlen(prog_name) + 2);
		ft_strcpy(path_str, path_tab[i]);
		ft_strcat(path_str, "/");
		ft_strcat(path_str, prog_name);
		if (access(path_str, X_OK) == 0)
			found = 1;
		if (found)
		{
			ft_tab_del(&path_tab);
			return (path_str);
		}
		ft_strdel(&path_str);
		i++;
	}
	return (NULL);
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
		if (args[0][0] != '.' && args[0][0] != '/')
			confirmed_path = search_paths_for_program(env, args[0]);
		else if (access(args[0], X_OK) == 0)
			confirmed_path = ft_strdup(args[0]);
		else
		{
			ft_putstr_fd("minishell: program not found!: ", 2);
			ft_putendl_fd(args[0], 2);
		}
		if (confirmed_path)
		{
			status = minishell_exec(args, env, confirmed_path);
			ft_strdel(&confirmed_path);
		}
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
	pid_t		wpid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		// Child process
		if (execve(path, args, *env) == -1)
			ft_putstr_fd("minishell: execve() failed!\n", 2);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		ft_putstr_fd("minishell: fork() error!\n", 2);
	else
	{
		// Parent process
		wpid = waitpid(pid, &status, WUNTRACED);
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			wpid = waitpid(pid, &status, WUNTRACED);
	}
	return (MINISHELL_CONTINUE);
}
