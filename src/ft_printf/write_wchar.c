/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_wchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 22:39:43 by bbauer            #+#    #+#             */
/*   Updated: 2017/03/05 14:58:16 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			cleanup_memory(wchar_t **draft, char **utf8_draft)
{
	ft_memdel((void **)draft);
	ft_memdel((void **)utf8_draft);
}

static void			print_null_wchar(t_conversion *conversion, t_format *format,
																wchar_t *draft)
{
	char		*utf8_draft_post_null;

	utf8_draft_post_null = ft_utf8strencode(draft + ft_wstrlen(draft) + 1);
	ft_putchar('\0');
	format->chars_written++;
	if (ft_wstrlen(draft) + 1 < conversion->width)
	{
		ft_putstr(utf8_draft_post_null);
		format->chars_written += ft_strlen((char *)&utf8_draft_post_null);
	}
	ft_memdel((void **)&utf8_draft_post_null);
}

void				write_wchar(t_conversion *conversion, va_list ap,
															t_format *format)
{
	wchar_t		*draft;
	char		*utf8_draft;

	if (conversion->flags.hash)
		return ;
	else
	{
		draft = (wchar_t *)malloc(sizeof(wchar_t) * 2);
		*draft = va_arg(ap, wint_t);
		draft[1] = '\0';
		if (!conversion->width & conversion->flags.pos_values_begin_w_space)
		{
			ft_putchar(' ');
			format->chars_written++;
		}
		apply_width_wchar(conversion, &draft);
		utf8_draft = ft_utf8strencode(draft);
		ft_putstr(utf8_draft);
		format->chars_written += ft_strlen(utf8_draft);
		if (*draft == '\0')
			print_null_wchar(conversion, format, draft);
		cleanup_memory(&draft, &utf8_draft);
	}
}
