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

// Linked list of t_builtin structs would be most flexible for adding more?
// If not, just use the enum coee instead.

typedef struct		s_builtin
{
	char		*name;
	int			(*function)(char **args, char **envp);
}					t_builtin;

// Need to figure out what goes in here...
typedef struct		s_environ
{
	char		*cwd;
}					t_environ;

typedef enum
{
	NOT_BUILTIN, CH_DIR, EXIT_MINISHELL, ENV, SETENV, UNSETENV, ECHO
}					e_builtins;

void				minishell_loop(t_builtin *builtins, char **envp);
int					minishell_exec(char **args, t_builtin *builtins,
															char **envp);
int					minishell_launcher(char **args, char **envp);

#endif
