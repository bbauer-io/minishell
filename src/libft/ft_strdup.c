/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 07:07:44 by bbauer            #+#    #+#             */
/*   Updated: 2016/11/07 10:55:06 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft.h"

char	*ft_strdup(char *str)
{
	char	*new_str;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	new_str = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
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
