/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctomb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 11:26:24 by bbauer            #+#    #+#             */
/*   Updated: 2017/02/16 11:26:36 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_wctomb(char *s, wchar_t wc)
{
	int			len;
	size_t		i;

	i = 0;
	len = ft_utf8charsize(wc);
	if (len >= 4)
		s[i++] = (0xFF000000 & wc) >> 24;
	if (len >= 3)
		s[i++] = (0xFF0000 & wc) >> 16;
	if (len >= 2)
		s[i++] = (0xFF00 & wc) >> 8;
	if (len >= 1)
		s[i++] = 0xFF & wc;
	return (len);
}
