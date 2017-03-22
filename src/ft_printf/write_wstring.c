/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_wstring.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 00:05:48 by bbauer            #+#    #+#             */
/*   Updated: 2017/03/04 16:12:51 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				write_wstring(t_conversion *conversion, va_list ap,
															t_format *format)
{
	wchar_t			*draft;
	t_utf8			*utf8draft;

	draft = ft_wstrdup(va_arg(ap, wchar_t *));
	if (!draft)
		draft = ft_wstrdup(L"(null)");
	if (conversion->precision_set)
		apply_precision_wstr(conversion, &draft);
	if (conversion->width)
		apply_width_wchar(conversion, &draft);
	utf8draft = ft_utf8strencode(draft);
	ft_putstr(utf8draft);
	format->chars_written += ft_strlen((char *)utf8draft);
	ft_memdel((void **)&draft);
	ft_memdel((void **)&utf8draft);
	return ;
}
