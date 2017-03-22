/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrsize_utf8.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 11:27:07 by bbauer            #+#    #+#             */
/*   Updated: 2017/02/16 11:27:20 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the number of bytes needed to represent a string of unicode code
** points after it has been encoded to UTF-8.
*/

size_t			ft_wstrsize_utf8(const wchar_t *wstr)
{
	size_t		size;

	if (!wstr)
		return (0);
	size = 0;
	while (*wstr != '\0')
	{
		size += ft_wcharsize_utf8(*wstr);
		wstr++;
	}
	return (size);
}
