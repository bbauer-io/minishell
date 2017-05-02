/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_env_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 21:35:49 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/01 23:32:39 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
** Adds a single entry to the env var table.
*/

void			add_to_env(char *keyvalpair, char ***env)
{
	char	**new_env;

	new_env = NULL;
	new_env = ft_tab_add_one(*env, keyvalpair);
	if (new_env)
	{
		free(*env);
		*env = new_env;
	}
	return ;
}

/*
** Tests if a variable is present in the environment.
*/

int				env_var_is_set(char *key, char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strbeginequ(env[i], key) && env[i][ft_strlen(key)] == '=')
			return (1);
		i++;
	}
	return (0);
}

/*
** Creates a new environment table from the consecutive valid key-value pairs
** at the beginning of **args (i pass this function args[2] so it can start
** at the beginning of the list here.
*/

char			**build_new_env(char **args)
{
	int		i;
	int		len;
	char	**new_env;

	i = 0;
	len = 0;
	while (is_valid_env_var(args[len]))
		len++;
	new_env = (char **)malloc(sizeof(char *) * (len + 1));
	ft_bzero(new_env, sizeof(char *) * (len + 1));
	while (is_valid_env_var(args[i]))
	{
		new_env[i] = ft_strdup(args[i]);
		i++;
	}
	new_env[i] = NULL;
	return (new_env);
}

/*
** Used to create a new table of args to use when launching a program from env
** (so that it will not include the env command and its options)
*/

char			**build_new_args(char **args)
{
	char	**new_args;

	while (is_valid_env_var(*args))
		args++;
	new_args = ft_tab_dup(args);
	return (new_args);
}

/*
** Updates the SHLVL env variable at launch.
*/

void			update_shell_level(char ***env)
{
	char	*lvl_str;
	char	*tmp;
	char	*kv_pair;
	int		level;

	lvl_str = NULL;
	lvl_str = lookup_env_value("SHLVL", *env);
	if (lvl_str)
	{
		level = ft_atoi(lvl_str);
		level++;
		tmp = ft_itoa(level);
		if (tmp)
		{
			kv_pair = build_kv_pair_string("SHLVL", tmp);
			ft_strdel(&tmp);
			update_env_value(kv_pair, env);
			ft_strdel(&kv_pair);
		}
		ft_strdel(&lvl_str);
	}
}
