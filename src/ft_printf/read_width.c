/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 09:11:52 by bbauer            #+#    #+#             */
/*   Updated: 2017/03/03 22:09:33 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Read specified width, get va_arg if the width is a * (specified in arguments
** instead of in the format string).
*/

int			read_width(t_conversion *conversion, va_list ap, t_format *format)
{
	int		holder;

	if (format->str[format->index] == '*')
	{
		holder = va_arg(ap, int);
		if (holder < 0)
		{
			holder = -holder;
			conversion->flags.left_justify = 1;
		}
		conversion->width = holder;
		format->index++;
	}
	else if (ft_isdigit(format->str[format->index]))
	{
		conversion->width = ft_atoi(&format->str[format->index]);
		while (ft_isdigit(format->str[format->index]))
			format->index++;
	}
	return (GOOD);
}
