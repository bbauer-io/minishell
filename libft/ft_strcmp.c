/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 07:52:29 by bbauer            #+#    #+#             */
/*   Updated: 2016/11/07 09:30:16 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char const *s1, char const *s2)
{
	int		i;

	i = 0;
	while ((unsigned char)s1[i] == (unsigned char)s2[i])
	{
		if ((unsigned char)s1[i] == '\0')
			return (0);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
