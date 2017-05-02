/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:29:59 by bbauer            #+#    #+#             */
/*   Updated: 2016/11/15 14:30:03 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst != NULL && del != NULL)
	{
		(*del)((*alst)->content, (*alst)->content_size);
		ft_memdel((void **)alst);
	}
}
