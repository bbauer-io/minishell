/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 11:50:02 by bbauer            #+#    #+#             */
/*   Updated: 2017/03/04 18:27:59 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Apply precision, then prefix, then width(and justify from that function)
*/

#include "ft_printf.h"

static void			prefix_helper(t_conversion *conversion, char **draft)
{
	char	*temp;
	int		needed;

	needed = ft_ishex(*(*draft + 1)) && !ft_ishex(**draft) ? 1 : 2;
	temp = *draft;
	*draft = ft_strnew(ft_strlen(*draft) + needed);
	**draft = '0';
	*(*draft + 1) = 'X';
	ft_strncpy(*draft + 2, temp,
			conversion->width ? conversion->width - needed : ft_strlen(temp));
	ft_memdel((void **)&temp);
	return ;
}

static void			add_hex_prefix(t_conversion *conversion, char **draft)
{
	int		i;

	if (**draft == '0' && (*draft)[1] == '0')
		(*draft)[1] = 'X';
	else if ((ft_ishex(**draft) || ft_ishex(*(*draft + 1))))
		prefix_helper(conversion, draft);
	else
	{
		i = 0;
		while (!ft_ishex((*draft)[i]) || (*draft)[i] == '0')
			if ((*draft)[i++] == '\0')
				return ;
		i -= 2;
		(*draft)[i] = '0';
		(*draft)[++i] = 'X';
	}
}

void				write_hex(t_conversion *conversion, va_list ap,
															t_format *format)
{
	char		*draft;
	uintmax_t	value;

	value = get_unsigned_int_arg(conversion, ap);
	if (!value && conversion->precision_set)
		draft = ft_strdup("");
	else
		draft = ft_itoa_base_uintmax(value, 16);
	if (conversion->precision_set && conversion->specifier != POINTER)
		apply_precision(conversion, &draft);
	if (conversion->width)
		apply_width(conversion, &draft);
	if (conversion->flags.pos_values_begin_w_space
										|| conversion->flags.show_sign)
		apply_prefix(conversion, &draft);
	if ((conversion->flags.hash && value)
										|| conversion->specifier == POINTER)
		add_hex_prefix(conversion, &draft);
	if (conversion->specifier == HEX_LOWER || conversion->specifier == POINTER)
		ft_tolower_str(draft);
	ft_putstr(draft);
	format->chars_written += ft_strlen(draft);
	ft_memdel((void **)&draft);
}
