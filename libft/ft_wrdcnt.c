/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wrdcnt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:18:29 by bbauer            #+#    #+#             */
/*   Updated: 2016/11/17 13:19:19 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WHITESPACE (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')

#include "libft.h"

int		ft_wrdcnt(char *s)
{
	int		i;
	int		flag;
	int		words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		while ((i == 0 && !WHITESPACE) || WHITESPACE)
		{
			i++;
			flag = 1;
		}
		while (!WHITESPACE && s[i] != '\0')
		{
			if (flag == 1)
				words++;
			flag = 0;
			i++;
		}
	}
	return (words);
}
