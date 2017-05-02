/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 12:43:19 by bbauer            #+#    #+#             */
/*   Updated: 2016/11/15 14:59:52 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_itoa_is_neg(int *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}

char			*ft_itoa(int n)
{
	int		temp;
	int		len;
	int		is_neg;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	temp = n;
	len = 2;
	is_neg = 0;
	ft_itoa_is_neg(&n, &is_neg);
	while (temp /= 10)
		len++;
	len += is_neg;
	if ((str = (char *)malloc(sizeof(char) * len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (is_neg)
		str[0] = '-';
	return (str);
}
