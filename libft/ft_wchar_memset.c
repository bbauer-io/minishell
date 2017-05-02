/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_memset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 23:50:17 by bbauer            #+#    #+#             */
/*   Updated: 2017/02/17 00:14:24 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_wchar_memset(void *b, wchar_t c, size_t len)
{
	unsigned int	i;
	wchar_t			*b2;

	b2 = b;
	i = 0;
	while (i < len)
	{
		b2[i] = (wchar_t)c;
		i++;
	}
	return (b);
}
