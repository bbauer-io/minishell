/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_catcher.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:25:07 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/28 15:37:58 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern char		*g_line;
extern pid_t	g_wpid;

/*
** I think the idea here is to change the args and env to global variables and
** execve() the program into itself to reset everything.
*/

/*
**		if (execve(path, args, *env) == -1)
**			ft_putstr_fd("meh$h: reset failed! Has my executable moved?\n", 2);
**		exit(EXIT_FAILURE);
*/

void		restart_minishell(int sig)
{
	if (sig == SIGINT && !g_wpid)
	{
		ft_strdel(&g_line);
		ft_putstr("\nMeh$H> ");
	}
	else
		ft_putendl_fd("SIG CAPTURED!!!", 2);
}
