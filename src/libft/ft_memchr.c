/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 06:44:13 by bbauer            #+#    #+#             */
/*   Updated: 2016/11/14 07:07:10 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *s, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*sm;

	ch = ((unsigned char)c);
	sm = ((unsigned char *)s);
	while (n > 0)
	{
		if (*sm == ch)
			return (sm);
		sm++;
		n--;
	}
	return (NULL);
}
