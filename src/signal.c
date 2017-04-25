/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:25:07 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/25 15:23:23 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void				interrupt_child_process(int sig)
{
	if (g_child_pid > 0 && sig)
		ft_putstr("WOOHPEE!");
}
