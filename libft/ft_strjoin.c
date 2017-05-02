/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 19:12:18 by bbauer            #+#    #+#             */
/*   Updated: 2016/11/10 15:34:00 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;

	if (!s1 || !s2)
		return (0);
	s3 = ft_strnew(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!s3)
		return (NULL);
	ft_strcpy(s3, s1);
	ft_strcpy(&s3[ft_strlen((char *)s1)], s2);
	return (s3);
}
