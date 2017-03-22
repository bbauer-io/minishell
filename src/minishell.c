/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:44:49 by bbauer            #+#    #+#             */
/*   Updated: 2017/03/21 19:23:45 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	minishell_loop(void);
{
	int		status;
	char	*line;
	char	**args;

	status = 1;
	while (status)
	{
		ft_putstr("$> ");
		line = get_next_line();
		args = minishell_split_line(line);
		status = minishell_exec(args);

		free(line);
		free(args);
	}
}

int		main(int argc, char **argv)
{
	minishell_loop();
	return (EXIT_SUCCESS);
}
