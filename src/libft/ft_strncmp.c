/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:40:31 by bbauer            #+#    #+#             */
/*   Updated: 2016/11/14 16:56:19 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(char const *s1, char const *s2, size_t n)
{
	while (n > 0)
	{
		if (*s1 != *s2)
			return (*(unsigned char *)s1 - (*(unsigned char *)s2));
		else if (*s1 == '\0')
			return (0);
		++s1;
		++s2;
		n--;
	}
	return (0);
}
