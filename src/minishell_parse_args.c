/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parse_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 14:27:16 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/28 14:27:22 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
** separates args at ; unless the command is enclosed in quotations ";"
** *command is set to null by cleanup when before  funciton is called from
** minishell_loop()
*/

void			separate_multiple_args(char ***args, char **line)
{
	size_t	i;
	int		l_begin;

	trim_and_free(line);
	i = 0;
	while (line && *line && i < ft_strlen(*line))
	{
		l_begin = i;
		while ((*line)[i] && (*line)[i] != ' ')
		{
			if ((*line)[i] == '\"')
			{
				i++;
				while ((*line)[i] != '\"')
					i++;
			}
			i++;
		}
		if ((*line)[i] == '\0' || (*line)[i] == ' ')
			copy_to_args_lst(args, line, i, l_begin);
		i++;
	}
}
