/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 18:49:32 by bbauer            #+#    #+#             */
/*   Updated: 2016/11/15 15:04:01 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies up to n chars to new str, always null terminates the new string.
*/

char	*ft_strndup(const char *str, size_t n)
{
	char			*new_str;
	unsigned int	i;

	i = 0;
	if ((unsigned int)ft_strlen(str) < n)
		new_str = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	else
		new_str = (char *)malloc(sizeof(char) * (n + 1));
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
