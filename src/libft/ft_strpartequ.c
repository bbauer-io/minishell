/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpartequ.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 11:51:43 by bbauer            #+#    #+#             */
/*   Updated: 2016/04/21 12:23:05 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns 1 if  s1 is exaclty the same as s2 (up to the length of s1 - s2 can
** be longer than s1)
*/

int		ft_strpartequ(char const *s1, char const *s2)
{
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	while (s1[i] == s2[i])
		i++;
	if (s1[i] == '\0')
		return (1);
	return (0);
}
