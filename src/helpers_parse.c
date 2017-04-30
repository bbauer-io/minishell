/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 14:18:53 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/30 10:08:39 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
** Copies a section of a string to a char ** table, if the string is
** encapsulated with " " marks, they will be ignored.
*/

void			copy_to_args_lst(char ***args, char **line, int i, int l_begin)
{
	char	**tmp_args;
	char	*tmp;

	tmp_args = *args;
	if ((*line)[l_begin] == '\"')
	{
		tmp = ft_strnew(i - l_begin - 2);
		ft_strncpy(tmp, &(*line)[l_begin + 1], i - l_begin - 2);
	}
	else
	{
		tmp = ft_strnew(i - l_begin);
		ft_strncpy(tmp, &(*line)[l_begin], i - l_begin);
	}
	*args = ft_tab_add_one(*args, tmp);
	ft_strdel(&tmp);
	if (tmp_args)
		free(tmp_args);
	return ;
}

/*
** Copies a section of a string to a new entry in a char ** table
** (the table will be created if it is the pointer to it is NULL.
*/

void			copy_to_list(char ***commands, char **line, int i, int l_begin)
{
	char	**tmp_com;
	char	*tmp;

	tmp_com = *commands;
	tmp = ft_strnew(i - l_begin);
	ft_strncpy(tmp, &(*line)[l_begin], i - l_begin);
	*commands = ft_tab_add_one(*commands, tmp);
	ft_strdel(&tmp);
	if (tmp_com)
		free(tmp_com);
	return ;
}

/*
** Takes a pointer to a string, ft_strtrims the string to remove \t \n ' '
** Frees the original string and returns the copy.
*/

void			trim_and_free(char **str)
{
	char	*trimmed;

	trimmed = ft_strtrim(*str);
	ft_strdel(str);
	*str = trimmed;
	return ;
}
