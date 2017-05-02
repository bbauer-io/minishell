/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:16:57 by bbauer            #+#    #+#             */
/*   Updated: 2016/11/07 13:19:39 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tab_dup(char **tab)
{
	char	**dup;
	int		i;

	i = 0;
	while (tab[i])
		i++;
	dup = (char **)malloc(sizeof(char *) * (i + 1));
	dup[i] = NULL;
	while (--i >= 0)
	{
		dup[i] = (char *)malloc(sizeof(char) * (ft_strlen(tab[i]) + 1));
		ft_strcpy(dup[i], tab[i]);
	}
	return (dup);
}
