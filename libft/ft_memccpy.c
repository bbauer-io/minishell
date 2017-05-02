/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 20:00:04 by bbauer            #+#    #+#             */
/*   Updated: 2016/11/13 18:42:07 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void const *src, int c, size_t n)
{
	unsigned int	i;
	char			*d;
	const char		*s;

	i = 0;
	d = dst;
	s = src;
	while (i < n)
	{
		if (s[i] == c)
		{
			((unsigned char *)d)[i] = s[i];
			return (d + 1 + i);
		}
		((unsigned char *)d)[i] = s[i];
		i++;
	}
	return (NULL);
}
