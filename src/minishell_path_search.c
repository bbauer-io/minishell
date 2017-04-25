
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

char				*search_paths_for_program(char ***env, char *prog_name)
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


