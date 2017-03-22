/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_chars_printed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 07:25:26 by bbauer            #+#    #+#             */
/*   Updated: 2017/03/13 07:32:45 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		save_chars_printed(va_list ap, t_format *format)
{
	int		*ptr;

	ptr = va_arg(ap, int *);
	*ptr = format->chars_written;
	return ;
}
