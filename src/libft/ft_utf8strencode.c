/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utf8strencode.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 16:56:28 by bbauer            #+#    #+#             */
/*   Updated: 2017/03/04 16:01:31 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Encodes a string of wchar unicode code points in utf8.
*/

t_utf8			*ft_utf8strencode(const wchar_t *wstr)
{
	size_t		i;
	size_t		len;
	wchar_t		c;
	t_utf8		*utf8;

	if (!wstr || !*wstr)
		return (ft_strdup(""));
	len = ft_wstrsize_utf8(wstr);
	if (len > 0)
		if ((utf8 = (t_utf8 *)malloc(sizeof(t_utf8) * (len + 1))))
		{
			i = 0;
			while (i < len)
			{
				c = ft_utf8charencode(*wstr);
				i += ft_wctomb(&utf8[i], c);
				wstr++;
			}
			utf8[i] = '\0';
			return (utf8);
		}
	return (NULL);
}
