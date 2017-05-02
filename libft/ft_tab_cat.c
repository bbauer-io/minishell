/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_cat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 13:16:57 by bbauer            #+#    #+#             */
/*   Updated: 2016/04/15 13:19:39 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** For combining two tables (char ** arrays) into one.
** 'dst' must have enough space allocated to store entirety of 'src' and NULL
** terminator.
** src will be copied directly to location specified by dst.
** (will NOT search for the end of dst before copying!)
*/

void		ft_tab_cat(char **dst, char **src)
{
	int		i;

	i = 0;
	if (!dst || !src)
		return ;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	return ;
}
