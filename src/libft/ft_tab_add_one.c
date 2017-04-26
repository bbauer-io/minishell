/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_add_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/17 13:16:57 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/26 10:53:30 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_tab_add_one copies src_tab to a new table with space for one more entry,
** then copies that entry and adds a pointer to it in the new table.
** Returns the new (char **) table.
*/

char		**ft_tab_add_one(char **src_tab, char *new_item)
{
	int		tab_len;
	char	**new_tab;

	tab_len = 0;
	while (src_tab && src_tab[tab_len])
		tab_len++;
	new_tab = (char **)malloc(sizeof(char *) * (tab_len + 2));
	ft_bzero(new_tab, sizeof(char *) * (tab_len + 2));
	ft_memcpy(new_tab, src_tab, sizeof(char *) * tab_len);
	new_tab[tab_len] = ft_strdup(new_item);
	new_tab[++tab_len] = NULL;
	return (new_tab);
}
