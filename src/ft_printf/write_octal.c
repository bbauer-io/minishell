/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_octal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 11:53:29 by bbauer            #+#    #+#             */
/*   Updated: 2017/03/04 08:52:01 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			add_octal_prefix(char **draft)
{
	char		*temp;

	temp = *draft;
	*draft = ft_strnew(ft_strlen(*draft) + 1);
	**draft = '0';
	ft_strcpy(*draft + 1, temp);
	ft_memdel((void **)&temp);
	return ;
}

void				write_octal(t_conversion *conversion, va_list ap,
															t_format *format)
{
	char		*draft;
	uintmax_t	value;

	value = get_unsigned_int_arg(conversion, ap);
	if (!value && conversion->precision_set)
		draft = ft_strdup("");
	else
		draft = ft_itoa_base_uintmax(value, 8);
	if ((conversion->flags.hash && value)
			|| (!value && conversion->precision_set && conversion->flags.hash))
		add_octal_prefix(&draft);
	if (conversion->precision_set)
		apply_precision(conversion, &draft);
	if (conversion->width)
		apply_width(conversion, &draft);
	if (conversion->flags.pos_values_begin_w_space
										|| conversion->flags.show_sign)
		apply_prefix(conversion, &draft);
	format->chars_written += ft_strlen(draft);
	ft_putstr(draft);
	ft_memdel((void **)&draft);
}
