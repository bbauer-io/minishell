/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_free_contents.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 22:12:30 by bbauer            #+#    #+#             */
/*   Updated: 2017/03/09 22:12:31 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lst_free_contents(void *content, size_t content_size)
{
	if (content)
		free(content);
	return (content_size);
}
