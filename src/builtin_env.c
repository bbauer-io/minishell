/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
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
	char	**tmp_env;
	char	**tmp_args;
	int		status;

	if (args[1][0] == '-' && args[1][1] == 'u' && args[2])
	{
		tmp_env = ft_tab_dup(env);
		find_and_remove_env(args[2], &tmp_env);
		tmp_args = ft_tab_dup(&args[2]);
		status = minishell_launcher(tmp_args, tmp_env);
		cleanup(NULL, NULL, &tmp_args, &tmp_env);
		return (status);
	}
	else if (env && *env)
		ft_print_tab(env);
	else
		ft_putstr_fd("no environment defined\n", 2);
	return (MINISHELL_CONTINUE);
}
