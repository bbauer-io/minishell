/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:44:48 by bbauer            #+#    #+#             */
/*   Updated: 2017/03/21 18:44:48 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "ft_printf.h"

# define MINISHELL_EXIT 0
# define MINISHELL_CONTINUE 1
# define NOT_BUILTIN 2

/*
** Minishell functions
*/

void			minishell_loop(char **env);
int				minishell_exec(char **args, char ***env);
int				minishell_launcher(char **args, char ***env);
char			*expand_shell_vars(char *str, char **env);
void			cleanup(char **line, char ***com, char ***args, char ***env);

/*
** Built-in programs for minishell
*/

int				builtin_echo(char **args);
int				builtin_cd(char **args, char ***env);
int				builtin_env(char **args, char ***env);
int				builtin_setenv(char **args, char ***env);
int				builtin_unsetenv(char **args, char ***env);

/*
** Helpers for env functions
*/

void			add_to_env(char *keyvalpair, char ***env);
void			find_and_remove_env(char *key, char ***env);
int				is_valid_env_var(char *str);
//char			*lookup_env_value(char *key, char **env);

#endif
