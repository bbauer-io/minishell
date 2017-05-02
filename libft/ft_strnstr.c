/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 18:01:50 by bbauer            #+#    #+#             */
/*   Updated: 2016/11/11 19:00:36 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *str, char const *to_find, size_t len)
{
	int		i;
	int		j;
	int		k;
	char	*s3;

	if (!*to_find)
		return ((char *)str);
	s3 = ft_strndup((char *)str, len);
	i = 0;
	while (s3[i] != '\0')
	{
		j = 0;
		k = i;
		if (s3[i] == to_find[j])
			while (s3[k] == to_find[j])
			{
				j++;
				if (to_find[j] == '\0')
					return ((char *)&str[i]);
				k++;
			}
		i++;
	}
	return (0);
}
