/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 18:28:58 by bbauer            #+#    #+#             */
/*   Updated: 2017/03/04 09:43:06 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			print_null_char(t_conversion *conversion, t_format *format,
														char *draft)
{
	ft_putchar('\0');
	format->chars_written++;
	if (ft_strlen(draft) + 1 < conversion->width)
	{
		ft_putstr(&draft[ft_strlen(draft) + 2]);
		format->chars_written += ft_strlen(&draft[ft_strlen(draft) + 2]);
	}
}

void				write_char(t_conversion *conversion, va_list ap,
															t_format *format)
{
	char		c;
	char		*draft;

	if (conversion->flags.hash)
		return ;
	c = va_arg(ap, int);
	draft = ft_strnew(1);
	*draft = c;
	if (!conversion->width && conversion->flags.pos_values_begin_w_space)
	{
		ft_putchar(' ');
		format->chars_written++;
	}
	apply_width(conversion, &draft);
	ft_putstr(draft);
	format->chars_written += ft_strlen(draft);
	if (c == '\0')
		print_null_char(conversion, format, draft);
	ft_memdel((void **)&draft);
}
