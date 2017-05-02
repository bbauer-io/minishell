/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parse_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 14:27:16 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/01 23:13:50 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void		find_end_of_quote_str(char *line, size_t *i, int *end_quote)
{
	(*i)++;
	*end_quote = 1;
	while (line[*i] != '\"')
		(*i)++;
}

/*
** separates args at ; unless the command is enclosed in quotations ";"
** *command is set to null by cleanup when before  funciton is called from
** minishell_loop()
*/

void			separate_multiple_args(char ***args, char **line)
{
	size_t	i;
	int		l_begin;
	int		end_quote;

	trim_and_free(line);
	i = 0;
	end_quote = 0;
	while (line && *line && i < ft_strlen(*line))
	{
		l_begin = i;
		while ((*line)[i] && (*line)[i] != ' ' && !end_quote)
		{
			if ((*line)[i] == '\"')
				find_end_of_quote_str(*line, &i, &end_quote);
			i++;
		}
		if ((*line)[i] == '\0' || (*line)[i] == ' ' || end_quote)
		{
			end_quote = 0;
			copy_to_args_lst(args, line, i, l_begin);
		}
		while ((*line)[i] == ' ')
			i++;
	}
}
