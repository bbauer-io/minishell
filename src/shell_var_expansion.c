/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_var_expansion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 18:44:49 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/16 19:23:45 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static char		*matches_env_var(char *var, int vlen, char **env)
{
	int		i;
	char	*match_value;

	i = 0;
	match_value = NULL;
	while (env[i++])
		if (ft_strequ(env[i], var) && env[i][vlen] == '=')
			match_value = ft_strdup(&env[i][vlen + 1]);
	free(var);
	return (match_value);
}

static char		*expand_individual_var(char *str, char **env, int i)
{
	int		vlen;
	int		elen;
	char	*expanded;
	char	*match;

	vlen = i;
	match = NULL;
	while (ft_isalnum(str[vlen]))
		vlen++;
	vlen = vlen - i;
	match = matches_env_var(ft_strndup(&str[i + 1], vlen), vlen, env);
	elen = ft_strlen(str) - vlen + (match ? ft_strlen(match) : 0);
	expanded = (char *)malloc(sizeof(char) * (elen + 1));
	ft_strncpy(expanded, str, i);
	if (match)
	{
		ft_strcat(expanded, match);
		free(match);
	}
	ft_strcat(expanded, &str[i + vlen]);
	free(str);
	return (expanded);
}

char			*expand_shell_vars(char *str, char **env)
{
	int		i;
	char	*expanded;

	i = 0;
	expanded = NULL;
	while (str[i++] != '\0')
		if (str[i] == '$' && ft_isalnum(str[i + 1]))
			str = expand_individual_var(str, env, i);
	return (expanded);
}
