/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_flag_compatibility_continued.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 09:05:27 by bbauer            #+#    #+#             */
/*   Updated: 2017/03/02 12:57:58 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** flag '#' cannot be used with 'x' 'X' 'o' 'O' (HEX || OCTAL)
*/

static int			hashtag_compatibility(t_conversion *conversion)
{
	if (conversion->flags.hash)
		if (!(conversion->specifier == HEX_LOWER
				|| conversion->specifier == HEX_UPPER
				|| conversion->specifier == OCTAL))
			return (ERROR);
	return (GOOD);
}

/*
** pad with zeros flag '0' is not compatible with specifier 'c' 'C' 's' 'S' 'p'
** (CHAR, STRING, POINTER)
*/

static int			zero_flag_compatibility(t_conversion *conversion)
{
	if (conversion->flags.pad_with_zeros)
		if (conversion->specifier == CHAR
				|| conversion->specifier == STRING
				|| conversion->specifier == POINTER)
			return (ERROR);
	return (GOOD);
}

/*
** '+' and ' ' flags are ONLY compatible with 'd' 'i' 'D' (S_DECIMAL)
*/

static int			show_pos_flag_compatibility(t_conversion *conversion)
{
	if (conversion->flags.pos_values_begin_w_space
				|| conversion->flags.show_sign)
		if (conversion->specifier == U_DECIMAL || conversion->specifier == CHAR)
		{
			conversion->flags.pos_values_begin_w_space = 0;
			conversion->flags.show_sign = 0;
		}
	return (GOOD);
}

int					verify_flag_compatibility_continued(t_conversion
																*conversion)
{
	if (hashtag_compatibility(conversion) == ERROR)
		return (ERROR);
	if (zero_flag_compatibility(conversion) == ERROR)
		return (ERROR);
	if (show_pos_flag_compatibility(conversion) == ERROR)
		return (ERROR);
	return (GOOD);
}
