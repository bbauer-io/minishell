/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 13:16:57 by bbauer            #+#    #+#             */
/*   Updated: 2016/04/15 13:19:39 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tab_new(size_t tab_len)
{
	char	**new_tab;

	new_tab = (char **)malloc(sizeof(char *) * (tab_len + 1));
	ft_bzero(new_tab, sizeof(char *) * (tab_len + 1));
	return (new_tab);
}
