/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:14:50 by bbauer            #+#    #+#             */
/*   Updated: 2016/11/09 17:40:10 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*fresh;

	fresh = malloc(size);
	if (fresh == 0)
		return (fresh);
	ft_bzero(fresh, size);
	return (fresh);
}
