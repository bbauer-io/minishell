/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:10:57 by bbauer            #+#    #+#             */
/*   Updated: 2016/11/17 11:39:49 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Trims leading and trailing spaces, tabs, and newlines from a given string.
** Leaves the original string in tact, returning a pointer to a trimmed copy.
*/

char	*ft_strtrim(char const *s)
{
	char	*trimmed;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (ft_strnew(0));
	j = ft_strlen((char *)s) - 1;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	trimmed = (char *)malloc(sizeof(char) * (j - i + 2));
	if (!trimmed)
		return (trimmed);
	ft_strncpy(trimmed, &s[i], (j - i + 1));
	trimmed[j - i + 1] = '\0';
	return (trimmed);
}
