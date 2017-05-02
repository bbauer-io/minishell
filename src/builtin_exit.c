/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 21:33:09 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/01 21:54:48 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void		minishell_exit(char **args)
{
	int		exit_code;

	exit_code = 0;
	if (args && *args && args[1])
		exit_code = ft_atoi(args[1]);
	exit(exit_code);
}
