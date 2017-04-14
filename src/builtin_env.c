/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:44:49 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/13 19:23:45 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int			builtin_env(char **args, char **env)
{
	// temporary if statement to appease compiler options until I actually use args
	if (args)
		ft_print_tab(env);
	return (MINISHELL_CONTINUE);
}

int			builtin_setenv(char **args, char **env)
{
	//	If env var is present
	//		change it
	//	Else
	//		Add it
	return (MINISHELL_CONTINUE);
}

int			builtin_unsetenv(char **args, char **env)
{
	//	If env var is present
	//		Remove it
	return (MINISHELL_CONTINUE);
}

