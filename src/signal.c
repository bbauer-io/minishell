/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:25:07 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/26 12:52:26 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void		restart_minishell(int sig)
{
	if (sig)
		ft_putendl_fd("SIG CAPTURED!!!", 2);
		//		if (execve(path, args, *env) == -1)
//			ft_putstr_fd("meh$h: reset failed! Has my executable moved?\n", 2);
//		exit(EXIT_FAILURE);
}
