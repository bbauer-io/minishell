/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fix_sign_placement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 21:40:24 by bbauer            #+#    #+#             */
/*   Updated: 2017/03/03 22:11:10 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		get_sign(t_conversion *conversion, char **draft)
{
	int			i;
	char		sign;

	i = 0;
	sign = '\0';
	while ((*draft)[i] != '\0')
	{
		if ((*draft)[i] == '-')
			sign = '-';
		else if ((*draft)[i] == '+')
			sign = '+';
		else if ((*draft)[i] == ' '
							&& conversion->flags.pos_values_begin_w_space)
			sign = ' ';
		i++;
	}
	return (sign);
}

void			fix_sign_placement(t_conversion *conversion, char **draft)
{
	int			i;
	char		sign;

	i = 0;
	if ((sign = get_sign(conversion, draft)))
	{
		while ((*draft)[i] != '\0' && (*draft)[i] != '0')
			i++;
		(*draft)[i++] = sign;
		while ((*draft)[i] != '\0' && (*draft)[i] != sign)
			i++;
		(*draft)[i] = '0';
	}
}
