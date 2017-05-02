/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 22:12:54 by bbauer            #+#    #+#             */
/*   Updated: 2017/03/09 22:12:56 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_append(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (!new || !alst)
		return ;
	tmp = *alst;
	if (!*alst)
		*alst = new;
	else
	{
		tmp = *alst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
