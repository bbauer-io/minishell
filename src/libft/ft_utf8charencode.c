/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf8charencode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 11:06:40 by bbauer            #+#    #+#             */
/*   Updated: 2017/02/17 02:34:30 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Encodes a wchar_t unicode code point  to UTF-8 or returns the "substitute"
** character.
*/

wchar_t			ft_utf8charencode(wchar_t c)
{
	size_t				size;
	unsigned int		uc;

	uc = c;
	size = ft_wcharbits(c);
	if (size <= 7)
		return (c);
	if (size <= 11)
		return (((uc >> 6) << 8) | ((uc << 26) >> 26) | 0xC080);
	if (size <= 16)
	{
		return ((((uc >> 12) << 28) >> 12) | (((uc >> 6) << 26) >> 18)
			| ((uc << 26) >> 26) | 0xE08080);
	}
	if (size <= 21)
	{
		return ((((uc >> 18) << 29) >> 5) | (((uc >> 12) << 26) >> 10)
			| (((uc >> 6) << 26) >> 18) | ((uc << 26) >> 26) | 0xF0808080);
	}
	return (0x1A);
}
