/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_path_search.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:25:14 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/25 12:24:58 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
** Lookup the $PATH env var and split it into a table of strings.
*/

static char			**path_lookup(char ***env)
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
** Builds a full program path by combing a path string and a program name with
** some formatting.
*/

static char			*build_path_str(char *path, char *prog_name)
{
	char		*path_str;

	path_str = ft_strnew(ft_strlen(path) + ft_strlen(prog_name) + 2);
	ft_strcpy(path_str, path);
	ft_strcat(path_str, "/");
	ft_strcat(path_str, prog_name);
	return (path_str);
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

	i = 0;
	found = 0;
	path_str = NULL;
	path_tab = path_lookup(env);
	while (path_tab && path_tab[i] && !found)
	{
		path_str = build_path_str(path_tab[i], prog_name);
		if (access(path_str, X_OK) == 0)
			found = 1;
		else
			ft_strdel(&path_str);
		i++;
	}
	if (path_tab)
		ft_tab_del(&path_tab);
	return (path_str ? path_str : NULL);
}

/*
** Tests that the an argument specifies a program that we have access to. Can
** be a relative path, or a full path. relative paths must start with "./" only
** if the specified executable is in the current working directory.
*/

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
	if (args[0][0] != '.' && args[0][0] != '/' && !ft_strchr(args[0], '/'))
		confirmed_path = search_paths_for_program(env, args[0]);
	else if (access(args[0], X_OK) == 0)
		confirmed_path = ft_strdup(args[0]);
	else if (relative_path && access(relative_path, X_OK) == 0)
		confirmed_path = ft_strdup(args[0]);
	if (relative_path)
		ft_strdel(&relative_path);
	return (confirmed_path);
}
