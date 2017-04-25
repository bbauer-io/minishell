/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 13:16:57 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/25 12:20:38 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_sep(char c, char *sep)
{
	while (*sep)
	{
		if (c == *sep)
			return (1);
		sep++;
	}
	return (0);
}

static int	ft_tokcnt(char *str, char *sep)
{
	int		i;
	int		flag;
	int		count;

	count = 0;
	flag = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_is_sep(str[i], sep))
		{
			count += flag;
			flag = 0;
		}
		else
			flag = 1;
		i++;
	}
	count += flag;
	return (count);
}

static int	ft_toklen(char *str, char *sep)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && !ft_is_sep(str[i], sep))
		i++;
	return (i);
}

char		**ft_strtok(char *str, char *sep)
{
	int		i;
	int		k;
	int		tok_len;
	char	**tok;

	if (!str ||
		!(tok = (char **)malloc(sizeof(char *) * (ft_tokcnt(str, sep) + 1))))
		return (NULL);
	i = 0;
	k = 0;
	while (k < ft_tokcnt(str, sep))
	{
		while (ft_is_sep(str[i], sep))
			i++;
		tok_len = ft_toklen(&str[i], sep);
		if (!(tok[k] = (char *)malloc(sizeof(char) * (tok_len + 1))))
			return (NULL);
		ft_strncpy(tok[k], &str[i], tok_len);
		tok[k][tok_len] = '\0';
		while (str[i] && !ft_is_sep(str[i], sep))
			i++;
		k++;
	}
	tok[k] = NULL;
	return (tok);
}
