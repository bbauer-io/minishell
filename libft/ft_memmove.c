/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 18:56:44 by bbauer            #+#    #+#             */
/*   Updated: 2016/11/14 15:30:05 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void const *src, size_t len)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (s < d && d < s + len)
	{
		d += len;
		s += len;
		while (len > 0)
		{
			*--d = *--s;
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			*d++ = *s++;
			len--;
		}
	}
	return (dst);
}
