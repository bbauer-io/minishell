/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrnsize_utf8.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 02:38:04 by bbauer            #+#    #+#             */
/*   Updated: 2017/02/17 02:38:06 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the number of bytes needed to represent a string of up to 'n' unicode
** code points after it has been encoded to UTF-8.
*/

size_t			ft_wstrnsize_utf8(const wchar_t *wstr, size_t n)
{
	size_t		size;
	size_t		i;

	if (!wstr)
		return (0);
	i = 0;
	size = 0;
	while (wstr[i] != '\0' && i < n)
		size += ft_wcharsize_utf8(wstr[i++]);
	return (size);
}
