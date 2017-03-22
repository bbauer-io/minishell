/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_flag_harmony.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 20:03:25 by bbauer            #+#    #+#             */
/*   Updated: 2017/03/05 14:57:22 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Flag ' ' is ignored when flag '+' is present
*/

static void			pos_values_begin_space_correction(t_conversion *conversion)
{
	if (conversion->flags.pos_values_begin_w_space
				&& conversion->flags.show_sign)
		conversion->flags.pos_values_begin_w_space = 0;
	return ;
}

/*
** flag '0' is ignored when flag '-' is present"
** flag '0' is ignored when precision is used
*/

static void			pad_zeros_flag_correction(t_conversion *conversion)
{
	if (conversion->flags.pad_with_zeros)
		if (conversion->flags.left_justify || conversion->precision_set)
			conversion->flags.pad_with_zeros = 0;
	return ;
}

/*
** precision is not a valid option with specifier 'c' 'C' 'p'
** precision not valid when specifier is 'c' and length is 'l'
*/

static int			precision_is_settable(t_conversion *conversion)
{
	if (conversion->precision_set)
		if ((conversion->specifier == CHAR && conversion->length >= L)
				|| conversion->specifier == POINTER)
			conversion->precision_set = 0;
	return (GOOD);
}

/*
** Can't specify length for a pointer!!
*/

static int			pointer_size_specified(t_conversion *conversion)
{
	if (conversion->specifier == POINTER && conversion->length != DEFAULT)
		return (ERROR);
	return (GOOD);
}

int					verify_flag_compatibility(t_conversion *conversion,
														t_format *format)
{
	format->index--;
	pos_values_begin_space_correction(conversion);
	pad_zeros_flag_correction(conversion);
	if (precision_is_settable(conversion) == ERROR)
		return (ERROR);
	if (pointer_size_specified(conversion) == ERROR)
		return (ERROR);
	if (verify_flag_compatibility_continued(conversion) == ERROR)
		return (ERROR);
	format->index++;
	return (GOOD);
}
