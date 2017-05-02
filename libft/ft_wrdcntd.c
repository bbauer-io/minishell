/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wrdcntd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 11:56:21 by bbauer            #+#    #+#             */
/*   Updated: 2016/11/14 15:43:56 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wrdcntd(char *str, char delimiter)
{
	int		i;
	int		flag;
	int		count;

	count = 0;
	flag = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == delimiter)
		{
			count += flag;
			flag = 0;
		}
		else
			flag = 1;
		i++;
	}
	count += flag;
	return (count);
}
