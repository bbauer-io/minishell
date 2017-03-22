/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:16:21 by bbauer            #+#    #+#             */
/*   Updated: 2017/03/13 07:34:44 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** %[flags][width][.precision][length]specifier
*/

static int		read_conversion_substr(t_conversion *conversion, va_list ap,
					t_format *format)
{
	if (read_flags(conversion, format) == GOOD
				&& read_width(conversion, ap, format) == GOOD
				&& read_precision(conversion, ap, format) == GOOD
				&& read_length(conversion, format) == GOOD
				&& read_specifier(conversion, format) == GOOD)
		return (GOOD);
	else
		return (ERROR);
}

/*
** Prints a '%' when "%%" has appeared in the format string.
*/

static int		double_percent(t_format *format)
{
	if (format->str[format->index] == '%')
	{
		ft_putchar('%');
		format->index++;
		format->chars_written++;
		return (1);
	}
	return (0);
}

static void		double_percent_followup(t_conversion *conversion,
					t_format *format)
{
	int		i;

	i = conversion->width;
	if (format->str[format->index] == '%')
	{
		if (conversion->flags.left_justify)
			ft_putchar('%');
		if (conversion->width)
			while (--i > 0)
				ft_putchar(' ');
		if (!conversion->flags.left_justify)
			ft_putchar('%');
		format->chars_written += (conversion->width ? conversion->width : 1);
		format->index++;
	}
	return ;
}

/*
** Calls function to check for "%%", if not that, then we go on to decipher the
** symbols and convert the variable into the specified formats for printing.
** double_percent() appears twice in case someone accidentally slips some flags
** in between the two percent signs.
*/

static void		print_var(t_format *format, va_list ap)
{
	t_conversion	conversion;

	if (double_percent(format))
		return ;
	ft_bzero(&conversion, sizeof(t_conversion));
	if (read_conversion_substr(&conversion, ap, format) == GOOD
			&& verify_flag_compatibility(&conversion, format) == GOOD)
	{
		if (conversion.specifier == CHARS_PRINTED)
			save_chars_printed(ap, format);
		else
			write_conversion_substr(&conversion, ap, format);
		return ;
	}
	else
		double_percent_followup(&conversion, format);
	return ;
}

/*
** Prints each character and calls functions to convert variables to printable
** strings and print them when '%' is encountered in the format string.
** Returns the number of chars printed.
*/

int				ft_vprintf(const char *format, va_list ap)
{
	t_format	format_tracker;

	if (!format)
		return (0);
	ft_bzero(&format_tracker, sizeof(t_format));
	format_tracker.str = format;
	while (format_tracker.str[format_tracker.index] != '\0')
	{
		if (format_tracker.str[format_tracker.index] == '%')
		{
			format_tracker.index++;
			print_var(&format_tracker, ap);
		}
		else
		{
			ft_putchar(format_tracker.str[format_tracker.index++]);
			format_tracker.chars_written++;
		}
	}
	return (format_tracker.chars_written);
}
