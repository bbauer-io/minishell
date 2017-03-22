/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_width_wchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 23:25:46 by bbauer            #+#    #+#             */
/*   Updated: 2017/02/17 02:27:09 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			apply_width_wstr(t_conversion *conversion, wchar_t **draft)
{
	wchar_t		*temp;

	if (conversion->width > ft_wstrlen(*draft))
	{
		temp = *draft;
		*draft = (wchar_t *)ft_strnew(conversion->width * sizeof(wchar_t) + 3);
		if (conversion->flags.left_justify)
		{
			ft_wstrcpy(*draft, temp);
			ft_wchar_memset(&(*draft)[ft_wstrlen(temp)], ' ',
										conversion->width - ft_wstrlen(temp));
		}
		else
		{
			ft_wchar_memset(*draft, ' ', conversion->width - ft_wstrlen(temp));
			ft_wstrcpy(&(*draft)[conversion->width - ft_wstrlen(temp)], temp);
		}
		ft_memdel((void **)&temp);
	}
	return ;
}

/*
** ints and hex are padded with leading zeros if precision is larger than the
** number of digits needed to display the number, but a smaller precision will
** never truncate the number.
*/

static void			apply_width_wint(t_conversion *conversion, wchar_t **draft)
{
	wchar_t		*temp;

	if (ft_wstrlen(*draft) < conversion->width)
	{
		temp = *draft;
		*draft = (wchar_t *)ft_strnew(conversion->width * sizeof(wchar_t) + 3);
		if (conversion->flags.left_justify)
		{
			ft_wstrcpy(*draft, temp);
			ft_wchar_memset(&(*draft)[ft_wstrlen(*draft)], ' ',
										conversion->width - ft_wstrlen(*draft));
		}
		else
		{
			ft_wchar_memset(*draft,
								(conversion->flags.pad_with_zeros ? '0' : ' '),
										conversion->width - ft_wstrlen(temp));
			ft_wstrcpy(&(*draft)[conversion->width - ft_wstrlen(temp)], temp);
		}
		ft_memdel((void **)&temp);
	}
}

void				apply_width_wchar(t_conversion *conversion, wchar_t **draft)
{
	if (conversion->specifier == STRING)
		apply_width_wstr(conversion, draft);
	else
		apply_width_wint(conversion, draft);
	return ;
}
