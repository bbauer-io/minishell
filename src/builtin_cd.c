/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:44:49 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/13 19:23:45 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
** expands a '~' at str[0] into the user's home directory and concatenates the
** rest of the string. If an argument is passed in, the user's home directory
** alone will be returned.
*/

char		*expand_home_dir(char *str, char ***env)
{
	char	*home;
	char	*expanded;

	home = lookup_env_value("HOME", *env);
	if (str && str[0] == '~' && str[1] != '~')
	{
		if (home)
		{
			expanded = ft_strnew(ft_strlen(home) + ft_strlen(&str[1]) + 1);
			ft_strcpy(expanded, home);
			ft_strcat(expanded, &str[1]);
			ft_strdel(&home);
			return (expanded);
		}
		else
				ft_putstr_fd("Error! $HOME is undefined!\n", 2);
	}
	if (home)
		return (home);
	else
		return (ft_strdup(str));
}

/*
** Retrieves the current working directory from the system and updates our PWD
** env var to reflect the result.
*/

static void		update_pwd_env_var(char ***env)
{
	char	cwd[PATH_MAX];
	char	*new_pwd;

	ft_bzero(cwd, PATH_MAX);
	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		find_and_remove_env("PWD", env);
		new_pwd = ft_strnew(ft_strlen(cwd) + 5);
		ft_strcpy(new_pwd, "PWD=");
		ft_strcat(new_pwd, cwd);
		add_to_env(new_pwd, env);
		ft_strdel(&new_pwd);
	}
	else
		ft_putstr_fd("Error! Directory does not exist!\n", 2);
}

/*
** Checks first that the argument is a valid file or directory (can call stat).
** Then checks that the argument specifies a directory.
** Then checks that we can access the directory.
** Then if all checks are successful, changes the working directory and updates
** our env var specifying the cwd.
*/

static void		change_directory(char *path, char ***env)
{
	struct stat		st;

	if (stat(path, &st) == -1)
	{
		ft_putstr_fd("cd: No such directory: ", 2);
		ft_putendl_fd(path, 2);
	}
	else if (!(S_ISDIR(st.st_mode)))
	{
		ft_putstr_fd("cd: Is not a directory: ", 2);
		ft_putendl_fd(path, 2);
	}
	else if (access(path, X_OK) == -1)
	{
		ft_putstr_fd("cd: Permission denied: ", 2);
		ft_putendl_fd(path, 2);
	}
	else
	{
		chdir(path);
		update_pwd_env_var(env);
	}
}

/*
** Changes the shell's working directory.
*/

int			builtin_cd(char **args, char ***env)
{
	char	*path;
	DIR		*dir;

	dir = NULL;
	path = NULL;
	if (!args[1] || (args[1][0] == '~' && args[1][1] != '~'))
		path = expand_home_dir(args[1], env);
	else
		path = ft_strdup(args[1]);
	if (path)
	{
		dir = opendir(path);
		change_directory(path, env);
		if (dir)
			closedir(dir);
		ft_strdel(&path);
	}
	else
		ft_putstr_fd("cd failed! Couln't parse a valid path!\n", 2);
	return (MINISHELL_CONTINUE);
}
