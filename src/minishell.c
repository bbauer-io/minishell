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

void	cleanup(char *line, char **args)
{
	int		i;

	i = 0;
	if (line)
		free(line);
	while (args && args[i])
		free(args[i++]);
	if (args)
		free(args);
	return ;
}

void	minishell_loop(void)
{
	int		status;
	char	*line;
	char	**args;

	args = NULL;
	line = NULL;
	status = 1;
	while (status)
	{
		// print prompt
		ft_putstr("===D~ ");
		// read command from std input
		get_next_line(0, &line);
		// break line into a program and args
		args = ft_strtok(line, " ");
		// execute program
		status = minishell_exec(args);
		// cleanup
		cleanup(line, args);
	}
	return ;
}

int		main(int argc, char **argv)
{
	minishell_loop();
	return (EXIT_SUCCESS);
}
