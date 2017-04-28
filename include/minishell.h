/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:44:48 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/28 13:54:14 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <sys/dir.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <dirent.h>
# include <signal.h>

# define MINISHELL_EXIT 0
# define MINISHELL_CONTINUE 1
# define NOT_BUILTIN 2

/*
** Minishell functions
*/

void			cleanup(char **line, char ***com, char ***args, char ***env);
void			expand_shell_vars(char **args, char **env);
void			minishell_loop(char **env);
int				minishell_exec(char **args, char ***env, char *path);
int				minishell_launcher(char **args, char ***env);
void			separate_multiple_commands(char ***commands, char **line);
void			separate_multiple_args(char ***args, char **line);
char			*verify_program_exists(char **args, char ***env);

/*
** Built-in programs for minishell
*/

int				builtin_echo(char **args);
int				builtin_cd(char **args, char ***env);
int				builtin_env(char **args, char ***env);
int				builtin_setenv(char **args, char ***env);
int				builtin_unsetenv(char **args, char ***env);
int				builtin_db(void);
int				builtin_clear(void);
int				builtin_pwd(void);

/*
** Helpers for env functions
*/

void			add_to_env(char *keyvalpair, char ***env);
void			find_and_remove_env(char *key, char ***env);
int				is_valid_env_var(char *str);
char			*lookup_env_value(char *key, char **env);
void			update_env_value(char *new_kv_pair, char ***env);
char			*build_kv_pair_string(char *key, char *value);

/*
** Helpers for command and argument parsing.
*/

void			copy_to_args_lst(char ***args, char **line, int i, int l_begin);
void			copy_to_list(char ***commands, char **line, int i, int l_begin);
void			trim_and_free(char **str);

/*
** Signal catchers
*/

void			restart_minishell(int sig);

#endif
