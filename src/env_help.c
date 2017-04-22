/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 18:44:49 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/17 19:23:45 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
** Returns the value string that occurs after the end of "VALUE=" in env table.
*/

char		*lookup_env_value(char *key, char **env)
{
	char	*value;
	int		key_len;
	int		i;

	i = 0;
	value = NULL;
	key_len = ft_strlen(key);
	while (env[i] && !value)
	{
		if (ft_strbeginequ(env[i], key) && env[i][key_len] == '=')
			value = ft_strdup(&env[i][key_len + 1]);
		i++;
	}
	return (value);
}

/*
** Checks that a proposed env var (including key and value) contains only valid
** characters and is in the valid format (KEY=VALUE).
*/

int			is_valid_env_var(char *str)
{
	int		i;
	int		has_value;

	i = 0;
	has_value = 0;
	if (!str || !ft_isalpha(str[i++]) || !(str[0] == '_'))
		return (0);
	while (ft_isalnum(str[i]) || str[i] == '_')
		i++;
	if (str[i++] != '=')
		return (0);
	while (ft_isalnum(str[i]) || str[i] == '_')
	{
		i++;
		has_value = 1;
	}
	if (has_value && str[i] == '\0')
		return (1);
	else
		return (0);
}

/*
** If the specified key is found in the environment table, a new table will be
** created without that key. env's pointer will be changed to point to the new
** table and the old will be freed.
*/

void		find_and_remove_env(char *key, char ***env)
{
	int		i;
	int		tab_len;
	char	**new_env;

	new_env = NULL;
	tab_len = 0;
	while ((*env)[tab_len])
		tab_len++;
	i = 0;
	while ((*env)[i])
	{
		if (ft_strbeginequ((*env)[i], key) && (*env)[i][ft_strlen(key)] == '=')
		{
			new_env = ft_tab_rem_one(*env, i);
			if (new_env)
				*env = new_env;
			return ;
		}
		i++;
	}
	return ;
}

/*
** Adds a single entry to the env var table.
*/

void		add_to_env(char *keyvalpair, char ***env)
{
	char	**new_env;

	new_env = NULL;
	new_env = ft_tab_add_one(*env, keyvalpair);
	if (new_env)
		*env = new_env;
	return ;
}
