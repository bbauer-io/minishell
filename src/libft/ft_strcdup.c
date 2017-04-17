/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/16 07:07:44 by bbauer            #+#    #+#             */
/*   Updated: 2016/04/16 10:55:06 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcdup(char *str, char c)
{
	char	*new_str;
	int		i;

	if (!str)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * (ft_wrdlen(str, c) + 1));
	if (!new_str)
		return (0);
	i = 0;
	while (str[i] != '\0' && str[i] != c)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
