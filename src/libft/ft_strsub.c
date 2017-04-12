/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:00:19 by bbauer            #+#    #+#             */
/*   Updated: 2016/11/14 15:26:20 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies a substring of len characters from s (+ start) to a new string and
** returns a pointer to it.
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*sub;

	if (!s || !(sub = ft_strnew(len)))
		return (NULL);
	ft_strncpy(sub, s + start, len);
	return (sub);
}
