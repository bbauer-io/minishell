/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:44:49 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/01 21:35:45 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
** Removes pesky quotes from an otherwise perfectly good env variable kv pair.
*/

static int		fix_quote_env_var(char *str)
{
	char	*qstart;
	int		i;
	char	*end_quote;

	i = 0;
	if (!str || (!ft_isalpha(str[i++]) && !(str[0] == '_')))
		return (0);
	while (ft_isalnum(str[i]) || str[i] == '_')
		i++;
	if (str[i++] != '=')
		return (0);
	qstart = &str[i];
	if (*qstart == '\"')
		if ((end_quote = ft_strchr(qstart + 1, '\"')))
			if (end_quote[1] == '\0')
			{
				ft_memccpy(qstart, qstart + 1, '\"', end_quote - qstart);
				*end_quote = '\0';
				*(end_quote - 1) = '\0';
				return (1);
			}
	return (0);
}

/*
** Set an environment variable!
** If an env var specified is in the list, delete it first, then add the new
** key=value string.
*/

int				builtin_setenv(char **args, char ***env)
{
	int		i;
	char	*key;

	i = 1;
	while (args[i] && (is_valid_env_var(args[i]) || fix_quote_env_var(args[i])))
	{
		key = ft_strcdup(args[i], '=');
		find_and_remove_env(key, env);
		add_to_env(args[i], env);
		free(key);
		i++;
	}
	return (MINISHELL_CONTINUE);
}
