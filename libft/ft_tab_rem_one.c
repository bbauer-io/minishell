/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_rem_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 13:16:57 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/25 12:19:43 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_tab_rem_one copies src to a new table without the specified index (rem)
** The item at "rem" will be freed. The src table will also be freed after its
** replacement is created.
*/

char		**ft_tab_rem_one(char **src, size_t rem)
{
	size_t		tab_len;
	char		**new_tab;

	tab_len = 0;
	while (src[tab_len])
		tab_len++;
	if (rem > tab_len)
		return (NULL);
	new_tab = ft_tab_new(tab_len);
	ft_memcpy(new_tab, src, sizeof(char *) * rem);
	if (rem < tab_len)
		ft_memcpy(&new_tab[rem], &src[rem + 1],
										sizeof(char *) * (tab_len - rem - 1));
	new_tab[tab_len] = NULL;
	ft_strdel(&src[rem]);
	free(src);
	return (new_tab);
}
