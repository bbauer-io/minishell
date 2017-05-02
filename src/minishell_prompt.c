/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_prompt.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 21:07:13 by bbauer            #+#    #+#             */
/*   Updated: 2017/05/01 22:34:01 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

/*
** Prints a prompt and waits for standard input. The g_reading variable is to
** help manage ctrl-c.
*/

int			minishell_prompt(char **line)
{
	int		status;

	ft_putstr("Meh$H> ");
	signal(SIGINT, reset_prompt);
	status = get_next_line(0, line);
	signal(SIGINT, SIG_IGN);
	return (status);
}
