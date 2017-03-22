/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 00:48:43 by bbauer            #+#    #+#             */
/*   Updated: 2017/02/17 00:49:48 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t		*ft_wstrdup(wchar_t *str)
{
	wchar_t		*new_str;
	int			i;

	if (!str)
		return (NULL);
	i = 0;
	new_str = (wchar_t *)malloc(sizeof(wchar_t) * ft_wstrlen(str) + 1);
	if (!new_str)
		return (0);
	while (str[i] != '\0')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
