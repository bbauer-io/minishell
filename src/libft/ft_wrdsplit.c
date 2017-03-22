/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wrdsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:03:39 by bbauer            #+#    #+#             */
/*   Updated: 2016/11/17 13:16:51 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_wrdsplit(char const *s)
{
	int		i;
	int		word_begin;
	char	**word_list;
	int		k;

	word_list = (char **)malloc(sizeof(char *) * (ft_wrdcnt((char *)s) + 1));
	if (!word_list)
		return (NULL);
	i = 0;
	k = 0;
	while (k < ft_wrdcnt((char *)s))
	{
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		word_begin = i;
		while (s[i] != ' ' && s[i] != '\t' && s[i] != '\n' && s[i] != '\0')
			i++;
		word_list[k] = ft_strnew(i - word_begin);
		ft_strncpy(word_list[k], &s[word_begin], (i - word_begin));
		k++;
	}
	word_list[k] = NULL;
	return (word_list);
}
