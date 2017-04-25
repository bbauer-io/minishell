/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_ncat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 13:16:57 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/25 12:21:07 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** For combining two tables (char ** arrays) into one.
** 'dst' must have enough space allocated to store n (char *) of 'src' and NULL
** terminator.
** src will be copied directly to location specified by dst.
** (will NOT search for the end of dst before copying!)
*/

void		ft_tab_ncat(char **dst, char **src, size_t n)
{
	size_t		i;

	i = 0;
	if (!dst || !src)
		return ;
	while (src[i] && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return ;
}
