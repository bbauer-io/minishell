/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_precision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 09:12:24 by bbauer            #+#    #+#             */
/*   Updated: 2017/03/13 08:16:01 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** The first char has tested as '-' so we skip past that and consecutive digits.
*/

static int		treat_negative_precision_as_none(t_conversion *conversion,
												t_format *format)
{
	conversion->precision = 0;
	format->index++;
	while (ft_isdigit(format->str[format->index]))
		format->index++;
	return (GOOD);
}

/*
** Gets star argument from wildcard
*/

static int		get_wildcard_precision(t_conversion *conversion, va_list ap,
												t_format *format)
{
	int		tmp;

	tmp = va_arg(ap, int);
	format->index++;
	if (tmp < 0)
		conversion->precision_set = 0;
	else
		conversion->precision = tmp;
	return (GOOD);
}

/*
** This function will look for a precision value in the format string and store
** it if present.
*/

int				read_precision(t_conversion *conversion, va_list ap,
												t_format *format)
{
	if (format->str[format->index] == '.')
	{
		format->index++;
		if (format->str[format->index] == '-')
			return (treat_negative_precision_as_none(conversion, format));
		conversion->precision_set = 1;
		if (format->str[format->index] == '*')
			return (get_wildcard_precision(conversion, ap, format));
		if (ft_isdigit(format->str[format->index]))
		{
			conversion->precision = ft_atoi(&format->str[format->index]);
			while (ft_isdigit(format->str[format->index]))
				format->index++;
			return (GOOD);
		}
	}
	return (GOOD);
}
