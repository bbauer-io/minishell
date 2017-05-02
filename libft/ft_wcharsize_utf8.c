/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharsize_utf8.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 11:25:08 by bbauer            #+#    #+#             */
/*   Updated: 2017/02/16 11:25:28 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the number of bytes that will be needed to represent a unicode code
** point in UTF-8 format.
*/

size_t			ft_wcharsize_utf8(wchar_t c)
{
	size_t		bits;

	bits = ft_wcharbits(c);
	if (bits <= 7)
		return (1);
	if (bits <= 11)
		return (2);
	if (bits <= 16)
		return (3);
	if (bits <= 21)
		return (4);
	else
		return (0);
}
