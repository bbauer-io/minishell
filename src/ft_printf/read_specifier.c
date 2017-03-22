/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_specifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 09:11:36 by bbauer            #+#    #+#             */
/*   Updated: 2017/03/13 07:19:49 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Does the actual comparison of characters and returns the corresponding enum
*/

static t_specifier		compare_specifiers(char c)
{
	if (c == 'd' || c == 'i' || c == 'D')
		return (S_DECIMAL);
	if (c == 'u' || c == 'U')
		return (U_DECIMAL);
	if (c == 'o' || c == 'O')
		return (OCTAL);
	if (c == 'x')
		return (HEX_LOWER);
	if (c == 'X')
		return (HEX_UPPER);
	if (c == 'c' || c == 'C')
		return (CHAR);
	if (c == 's' || c == 'S')
		return (STRING);
	if (c == 'p')
		return (POINTER);
	if (c == 'n')
		return (CHARS_PRINTED);
	return (INVALID_SPECIFIER);
}

/*
** This function's purpose is to determine the specifier provided by the user in
** the format string which will tell us how to cast the argument we get from
** va_args as well as how to print it.
*/

int						read_specifier(t_conversion *conversion,
													t_format *format)
{
	char	c;

	if (!format->str[format->index])
		return (ERROR);
	c = format->str[format->index];
	conversion->specifier = compare_specifiers(format->str[format->index]);
	if (conversion->specifier == INVALID_SPECIFIER)
		return (ERROR);
	if (c == 'D' || c == 'U' || c == 'O' || c == 'C' || c == 'S')
		conversion->length = L;
	format->index++;
	return (GOOD);
}
