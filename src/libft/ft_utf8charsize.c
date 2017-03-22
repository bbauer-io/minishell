/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf8charsize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 11:07:07 by bbauer            #+#    #+#             */
/*   Updated: 2017/02/16 11:25:44 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** returns the number of bytes being used to represent a UTF-8 character which
** is stored in a wchar_t.
*/

size_t		ft_utf8charsize(wchar_t c)
{
	unsigned int	f;

	f = c;
	if (f <= 0xFF)
		return (1);
	if (f <= 0xFFFF)
		return (2);
	if (f <= 0xFFFFFF)
		return (3);
	if (f <= 0xFFFFFFFF)
		return (4);
	return (0);
}
