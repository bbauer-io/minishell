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

void		find_and_remove_env(char *key, char ***env)
{
	int		i;
	int		tab_len;
	char	**new_env;

	tab_len = 0;
	while ((*env)[tab_len])
		tab_len++;
	i = 0;
	while ((*env)[i])
	{
		if (ft_strequ((*env)[i], key) && (*env)[i][ft_strlen(key)])
		{
			new_env = ft_tab_rem_one(*env, i);
			ft_tab_del(env);
			*env = new_env;
			return ;
		}
		i++;
	}
	return ;
}

void		add_to_env(char *keyvalpair, char ***env)
{
	char	**new_env;

	new_env = ft_tab_add_one(*env, keyvalpair);
	ft_tab_del(env);
	*env = new_env;
	return ;
}
