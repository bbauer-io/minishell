/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharbits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 11:24:21 by bbauer            #+#    #+#             */
/*   Updated: 2017/02/16 11:25:34 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Count number of bits needed to represent a unicode code point.
*/

size_t			ft_wcharbits(wchar_t c)
{
	size_t		i;

	i = 0;
	while (c > 0)
	{
		c = c >> 1;
		i++;
	}
	return (i);
}
