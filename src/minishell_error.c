/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/30 12:42:06 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/30 12:49:00 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void		ft_put_err(char *str1, char *str2)
{
	ft_putstr_fd("minishell: ", 2);
	if (!str1 && !str2)
		ft_putendl_fd("Error!", 2);
	else if (str1 && str2)
	{
		ft_putstr_fd(str1, 2);
		ft_putendl_fd(str2, 2);
	}
	else if (str1 && !str2)
		ft_putendl_fd(str1, 2);
}
