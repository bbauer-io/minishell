/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 09:12:10 by bbauer            #+#    #+#             */
/*   Updated: 2017/01/26 09:12:14 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** This function checks the current position in the format string for the
** characters relevant to the length specifier (h, hh, l, ll, z, j)
*/

int		read_length(t_conversion *conversion, t_format *format)
{
	if (format->str[format->index] && format->str[format->index + 1])
	{
		if (format->str[format->index] == 'h')
			conversion->length = H;
		if (format->str[format->index] == 'l')
			conversion->length = L;
		if (format->str[format->index] == 'z')
			conversion->length = Z;
		if (format->str[format->index] == 'j')
			conversion->length = J;
		if (format->str[format->index] == 'l'
		&& format->str[format->index + 1] == 'l')
			conversion->length = LL;
		if (format->str[format->index] == 'h'
		&& format->str[format->index + 1] == 'h')
			conversion->length = HH;
		if (conversion->length != DEFAULT)
			format->index++;
		if (conversion->length == LL || conversion->length == HH)
			format->index++;
	}
	return (GOOD);
}
