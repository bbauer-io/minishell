/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:44:49 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/13 19:23:45 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
** Set an environment variable!
** If an env var specified is in the list, delete it first, then add the new
** key=value string.
*/

int			builtin_setenv(char **args, char ***env)
{
	int		i;
	char	*key;

	i = 1;
	while (args[i])
	{
		key = ft_strcdup(args[i], '=');
		find_and_remove_env(key, env);
		add_to_env(args[i], env);
		free(key);
		i++;
	}
	return (MINISHELL_CONTINUE);
}
