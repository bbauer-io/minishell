/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 22:06:39 by bbauer            #+#    #+#             */
/*   Updated: 2016/11/14 15:40:33 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Splits a string into an array of words based on the specified delimiter (c)
** which would usually be specificied as ' ', but could be anything needed.
*/

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		k;
	char	**wl;

	if (!s ||
	!(wl = (char **)malloc(sizeof(char *) * (ft_wrdcntd((char *)s, c) + 1))))
		return (NULL);
	i = 0;
	k = 0;
	while (k < ft_wrdcntd((char *)s, c))
	{
		while (s[i] == c)
			i++;
		wl[k] =
			(char *)malloc(sizeof(char) * (ft_wrdlen((char *)&s[i], c) + 1));
		if (!wl[k])
			return (NULL);
		ft_strncpy(wl[k], &s[i], ft_wrdlen((char *)&s[i], c));
		wl[k][ft_wrdlen((char *)&s[i], c)] = '\0';
		while (s[i] != c && s[i] != '\0')
			i++;
		k++;
	}
	wl[k] = NULL;
	return (wl);
}
