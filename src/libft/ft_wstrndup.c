/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrndup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 18:49:32 by bbauer            #+#    #+#             */
/*   Updated: 2017/02/17 02:35:23 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies up to n chars to new str, always null terminates the new string.
*/

wchar_t		*ft_wstrndup(const wchar_t *str, size_t n)
{
	wchar_t			*new_str;
	unsigned int	i;

	i = 0;
	if ((unsigned int)ft_wstrlen(str) < n)
		new_str = (wchar_t *)malloc(sizeof(wchar_t) * ft_wstrlen(str) + 1);
	else
		new_str = (wchar_t *)malloc(sizeof(wchar_t) * (n + 1));
	if (!new_str)
		return (0);
	while (str[i] != '\0' && i < n)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
