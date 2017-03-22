/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 16:42:11 by bbauer            #+#    #+#             */
/*   Updated: 2017/01/29 14:41:30 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int		test_for_flag(char c, t_flags *flags)
{
	if (c == '#')
		return (flags->hash = 1);
	if (c == ' ')
		return (flags->pos_values_begin_w_space = 1);
	if (c == '+')
		return (flags->show_sign = 1);
	if (c == '-')
		return (flags->left_justify = 1);
	if (c == '0')
		return (flags->pad_with_zeros = 1);
	return (0);
}

int				read_flags(t_conversion *conversion, t_format *format)
{
	char		c;

	while ((c = format->str[format->index])
			&& test_for_flag(c, &conversion->flags))
		format->index++;
	return (GOOD);
}
