/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_var_expansion.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 18:44:49 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/01 22:32:26 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
** expands a '~' at str[0] into the user's home directory and concatenates the
** rest of the string. If an argument is passed in, the user's home directory
** alone will be returned.
*/

char			*expand_home_dir(char *str, char **env)
{
	char	*home;
	char	*expanded;

	home = lookup_env_value("HOME", env);
	if (str && str[0] == '~' && str[1] != '~')
	{
		if (home)
		{
			expanded = ft_strnew(ft_strlen(home) + ft_strlen(&str[1]) + 1);
			ft_strcpy(expanded, home);
			ft_strcat(expanded, &str[1]);
			ft_strdel(&home);
			return (expanded);
		}
		else
			ft_putstr_fd("Error! $HOME is undefined!\n", 2);
	}
	if (home)
		return (home);
	else
		return (ft_strdup(str));
}

static char		*matches_env_var(char *var, int vlen, char **env)
{
	int		i;
	char	*match_value;

	i = 0;
	vlen--;
	match_value = NULL;
	while (env[i] && !match_value)
	{
		if (ft_strbeginequ(env[i], var) && env[i][vlen] == '=')
			match_value = ft_strdup(&env[i][vlen + 1]);
		i++;
	}
	ft_strdel(&var);
	return (match_value);
}

static char		*expand_individual_var(char *str, char **env, int i)
{
	int		vlen;
	int		elen;
	char	*expanded;
	char	*match;

	vlen = i + 1;
	match = NULL;
	while (ft_isalnum(str[vlen]))
		vlen++;
	vlen = vlen - i;
	match = matches_env_var(ft_strndup(&str[i + 1], vlen - 1), vlen, env);
	elen = ft_strlen(str) - vlen + (match ? ft_strlen(match) : 0);
	expanded = ft_strnew(elen + 1);
	ft_strncpy(expanded, str, i);
	expanded[i] = '\0';
	if (match)
	{
		ft_strcat(expanded, match);
		ft_strdel(&match);
	}
	ft_strcat(expanded, &str[i + vlen]);
	return (expanded);
}

/*
** Tests for '~' at beginning of an argument and expands it to home directory.
** Then tests for $VARIABLES and expands those based on their value in the env.
*/

void			expand_shell_vars(char **args, char **env)
{
	int		i;
	char	*expanded;

	while (args && *args)
	{
		i = 0;
		if ((*args)[0] == '~' && (*args)[1] != '~')
		{
			expanded = expand_home_dir(*args, env);
			ft_strdel(args);
			*args = expanded;
		}
		while ((*args)[i] != '\0')
		{
			if ((*args)[i] == '$' && ft_isalpha((*args)[i + 1]))
			{
				expanded = expand_individual_var(*args, env, i);
				ft_strdel(args);
				*args = expanded;
			}
			i++;
		}
		args++;
	}
	return ;
}
