/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 07:08:00 by bbauer            #+#    #+#             */
/*   Updated: 2016/11/14 07:10:44 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(void const *s1, void const *s2, size_t n)
{
	unsigned char const		*su1;
	unsigned char const		*su2;

	su1 = s1;
	su2 = s2;
	while (n > 0)
	{
		if (*su1 != *su2)
			return (*su1 - *su2);
		su1++;
		su2++;
		n--;
	}
	return (0);
}
