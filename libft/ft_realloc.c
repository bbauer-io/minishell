/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 14:10:22 by bbauer            #+#    #+#             */
/*   Updated: 2017/01/03 14:10:25 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size_original, size_t size_add)
{
	void	*new;

	if (!size_original && !size_add)
		size_add = 1;
	if (!(new = malloc(size_original + size_add)))
		return (NULL);
	if (ptr)
	{
		ft_memcpy(new, ptr, size_original);
		ft_memdel(&ptr);
	}
	return (new);
}
