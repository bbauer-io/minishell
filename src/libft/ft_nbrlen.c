/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 15:24:38 by bbauer            #+#    #+#             */
/*   Updated: 2017/03/09 21:58:23 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns the number of digits stored in a number. Useful for preparing an
** array of chars to hold a number, particulary when other formatting may be
** involved (I created this functionfor for use within ft_printf).
** NOTE: Accounts for a '-' with negative numbers.
*/

size_t		ft_nbrlen(int nbr)
{
	int			len;
	int			is_negative;

	is_negative = nbr < 0 ? 1 : 0;
	if (nbr == 0)
		return (1);
	len = 1;
	while (nbr /= 10)
		len++;
	if (is_negative)
		len++;
	return (len);
}
