/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 15:27:07 by bbauer            #+#    #+#             */
/*   Updated: 2017/06/22 15:39:55 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
** Updates the SHLVL env variable at launch.
*/

void			update_shell_level_env_var(char ***env)
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

/*
** Updates the SHELL env variable at launch.
*/

void			update_shell_env_var(char ***env)
{
	char	*kv_pair;

	kv_pair = ft_strdup("SHELL=meh$h");
	update_env_value(kv_pair, env);
	ft_strdel(&kv_pair);
}
