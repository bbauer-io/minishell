/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 18:14:23 by bbauer            #+#    #+#             */
/*   Updated: 2017/03/03 20:24:07 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			apply_precision_str(t_conversion *conversion, char **draft)
{
	char	*temp;

	if (conversion->precision < ft_strlen(*draft))
	{
		temp = *draft;
		*draft = ft_strndup(*draft, conversion->precision);
		ft_memdel((void **)&temp);
	}
	return ;
}

/*
** ints and hex are padded with leading zeros if precision is larger than the
** number of digits needed to display the number, but a smaller precision will
** never truncate the number.
*/

static void			apply_precision_int(t_conversion *conversion, char **draft)
{
	char	*temp;
	size_t	i;

	if (ft_strlen(*draft) < conversion->precision + conversion->int_is_negative)
	{
		temp = *draft;
		*draft = ft_strnew(conversion->precision + 1 +
												conversion->int_is_negative);
		(*draft)[conversion->precision + conversion->int_is_negative] = '\0';
		i = 0;
		if (conversion->int_is_negative)
			(*draft)[i++] = '-';
		while (i - conversion->int_is_negative
		< conversion->precision - ft_strlen(temp) + conversion->int_is_negative)
			(*draft)[i++] = '0';
		ft_strcpy(&((*draft)[i]), temp + conversion->int_is_negative);
		ft_memdel((void **)&temp);
	}
	return ;
}

void				apply_precision_wstr(t_conversion *conversion,
															wchar_t **draft)
{
	wchar_t	*temp;

	if (conversion->precision < ft_wstrlen(*draft))
	{
		temp = *draft;
		*draft = ft_wstrndup(*draft, conversion->precision);
		ft_memdel((void **)&temp);
	}
	return ;
}

void				apply_precision(t_conversion *conversion, char **draft)
{
	if (conversion->specifier == STRING)
		apply_precision_str(conversion, draft);
	else if (conversion->specifier != POINTER)
		apply_precision_int(conversion, draft);
	return ;
}
