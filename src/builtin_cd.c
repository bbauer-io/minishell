/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 12:22:20 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/26 18:20:57 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
		new_pwd = build_kv_pair_string("PWD", cwd);
		update_env_value(new_pwd, env);
		ft_strdel(&new_pwd);
	}
	else
		ft_putstr_fd("Error! Directory does not exist!\n", 2);
}

/*
** Retrieves the current working directory from the system and updates our PWD
** env var to reflect the result.
*/

static void		update_oldpwd_env_var(char ***env)
{
	char	*new_oldpwd;
	char	*tmp_value;

	tmp_value = lookup_env_value("PWD", *env);
	new_oldpwd = build_kv_pair_string("OLDPWD", tmp_value);
	update_env_value(new_oldpwd, env);
	ft_strdel(&tmp_value);
	ft_strdel(&new_oldpwd);
	return ;
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
		update_oldpwd_env_var(env);
		update_pwd_env_var(env);
	}
}

/*
** Changes the shell's working directory.
*/

int				builtin_cd(char **args, char ***env)
{
	char	*path;
	DIR		*dir;

	dir = NULL;
	path = NULL;
	if (args[1][0] == '-' && args[1][1] == '\0')
		path = lookup_env_value("OLDPWD", *env);
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
