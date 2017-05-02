/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_del.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 13:16:57 by bbauer            #+#    #+#             */
/*   Updated: 2016/04/13 13:19:39 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Erases and frees a table of strings, then sets the table's pointer to NULL.
*/

void		ft_tab_del(char ***tab)
{
	int		i;

	i = 0;
	if (tab && *tab)
	{
		while ((*tab)[i])
			ft_strdel(&(*tab)[i++]);
		free(*tab);
		*tab = NULL;
	}
	return ;
}
