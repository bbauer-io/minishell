/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 19:14:44 by bbauer            #+#    #+#             */
/*   Updated: 2016/11/11 19:19:04 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char const *str, char const *to_find)
{
	int		i;
	int		j;
	int		k;

	if (!*to_find)
		return ((char *)str);
	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			k = i;
			while (str[k] == to_find[j])
			{
				j++;
				if (to_find[j] == '\0')
					return ((char *)&str[i]);
				k++;
			}
		}
		i++;
	}
	return (0);
}
