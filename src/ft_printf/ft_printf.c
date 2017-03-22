/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:42:45 by bbauer            #+#    #+#             */
/*   Updated: 2017/01/15 15:48:44 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Return number of chars printed
*/

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			chars_printed;

	if (!format)
		return (0);
	va_start(ap, format);
	chars_printed = ft_vprintf(format, ap);
	va_end(ap);
	return (chars_printed);
}
