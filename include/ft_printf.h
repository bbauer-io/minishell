/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 14:43:11 by bbauer            #+#    #+#             */
/*   Updated: 2017/03/13 08:21:48 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <wchar.h>

# define ERROR		1
# define GOOD		0

typedef enum		e_bool
{
	FALSE, TRUE
}					t_bool;

typedef struct		s_flags
{
	t_bool		hash;
	t_bool		left_justify;
	t_bool		pad_with_zeros;
	t_bool		pos_values_begin_w_space;
	t_bool		show_sign;
}					t_flags;

typedef struct		s_format
{
	const char		*str;
	size_t			index;
	size_t			chars_written;
}					t_format;

typedef enum		e_length
{
	DEFAULT, HH, H, L, LL, J, Z
}					t_length;

typedef enum		e_specifier
{
	S_DECIMAL, U_DECIMAL, OCTAL, HEX_LOWER, HEX_UPPER, CHAR, STRING, POINTER,
	CHARS_PRINTED, INVALID_SPECIFIER
}					t_specifier;

typedef struct		s_conversion
{
	t_flags			flags;
	unsigned int	width;
	unsigned int	precision;
	t_bool			int_is_negative;
	t_bool			precision_set;
	t_length		length;
	t_specifier		specifier;
}					t_conversion;

/*
** These are the main functions that might be used within a larger program.
*/

int					ft_printf(const char *format, ...);
int					ft_vprintf(const char *format, va_list arg);

/*
** Functions for reading the various flags of each conversion. (Each time a '%'
** flag is encountered, all of these functions will be called to read The
** various specifiers.
*/

int					read_flags(t_conversion *conversion, t_format *format);
int					read_width(t_conversion *conversion, va_list ap,
											t_format *format);
int					read_precision(t_conversion *conversion, va_list ap,
											t_format *format);
int					read_length(t_conversion *conversion, t_format *format);
int					read_specifier(t_conversion *conversion, t_format *format);

/*
** Next these two functions will be called to make sure there aren't any
** conflicting flags.
*/

int					verify_flag_compatibility(t_conversion *conversion,
											t_format *format);
int					verify_flag_compatibility_continued(t_conversion
											*conversion);

/*
** The following functions will print the stored data in the format specified
** by the stored flags. A pointer would be printed by write_hex.
*/

void				write_conversion_substr(t_conversion *conversion,
											va_list ap, t_format *format);
void				write_signed_int(t_conversion *conversion, va_list ap,
											t_format *format);
void				write_unsigned_int(t_conversion *conversion, va_list ap,
											t_format *format);
void				write_hex(t_conversion *conversion, va_list ap,
											t_format *format);
void				write_octal(t_conversion *conversion, va_list ap,
											t_format *format);
void				write_string(t_conversion *conversion, va_list ap,
											t_format *format);
void				write_char(t_conversion *conversion, va_list ap,
											t_format *format);
void				write_wchar(t_conversion *conversion, va_list ap,
											t_format *format);
void				write_wstring(t_conversion *conversion, va_list ap,
											t_format *format);

/*
** Here are a couple reusable helper functions for the write functions
*/

void				apply_precision(t_conversion *conversion, char **draft);
void				apply_width(t_conversion *conversion, char **draft);
void				apply_width_wchar(t_conversion *conversion,
											wchar_t **draft);
void				apply_precision_wstr(t_conversion *conversion,
											wchar_t **draft);
void				apply_prefix(t_conversion *conversion, char **draft);
uintmax_t			get_unsigned_int_arg(t_conversion *conversion, va_list ap);
void				fix_sign_placement(t_conversion *conversion, char **draft);

/*
** Saves the number of chars written so far ('n' specifier)
*/

void				save_chars_printed(va_list ap, t_format *format);

#endif
