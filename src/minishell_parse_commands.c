/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parse_commands.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 10:24:23 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/28 13:56:33 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void		unclosed_quote_parse_error(char *line, int i)
{
	int		loc;
	int		k;

	k = 0;
	loc = i;
	while (line[loc] != '\"')
		loc--;
	ft_putstr_fd("parse error near:\n", 2);
	ft_putendl_fd(line, 2);
	while (k++ < loc)
		ft_putchar_fd(' ', 2);
	ft_putchar_fd('^', 2);
	while (loc++ < i)
		ft_putchar_fd('~', 2);
	ft_putchar_fd('\n', 2);
	return ;
}

static void		null_cmd_parse_error(char *line, int i)
{
	int		k;

	k = 0;
	ft_putstr_fd("parse error near:\n", 2);
	ft_putendl_fd(line, 2);
	while (++k < i)
		ft_putchar_fd(' ', 2);
	ft_putchar_fd('^', 2);
	ft_putendl_fd("^", 2);
	return ;
}

static int		increment_index_to_end_quote(size_t *i, char *line)
{
	(*i)++;
	while (line[*i] != '\"')
	{
		(*i)++;
		if (line[*i] == '\0')
		{
			unclosed_quote_parse_error(line, *i);
			return (0);
		}
	}
	return (1);
}

/*
** separates commands at ; unless the command is enclosed in quotations ";"
** *command is set to null by cleanup when before  funciton is called from
** minishell_loop()
*/

void			separate_multiple_commands(char ***commands, char **line)
{
	size_t	i;
	int		l_begin;

	trim_and_free(line);
	i = 0;
	while (line && *line && i < ft_strlen(*line))
	{
		l_begin = i;
		while ((*line)[i] && (*line)[i] != ';')
		{
			if ((*line)[i] == '\"')
				if (increment_index_to_end_quote(&i, *line) == 0)
					return ;
			i++;
		}
		if (i > 0 && (*line)[i] == ';' && ((*line)[i - 1] == ';'))
			return (null_cmd_parse_error(*line, i));
		if ((*line)[i] == '\0' || (*line)[i] == ';')
			copy_to_list(commands, line, i, l_begin);
		i++;
	}
}
