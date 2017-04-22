/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:44:49 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/13 19:23:45 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
** Clears the screen.
*/

int			builtin_clear(void)
{
	ft_putstr("\e[1;1H\e[2J");
	return (MINISHELL_CONTINUE);
}
