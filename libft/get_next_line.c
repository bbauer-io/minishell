/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <bbauer@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:30:05 by bbauer            #+#    #+#             */
/*   Updated: 2017/04/25 15:24:34 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define LIST_STR (char*)fd_node->content
#define NL ft_strcspn(LIST_STR, '\n')

static t_list	*find_fd(int fd)
{
	static t_list	*master_list;
	t_list			*tmp;

	tmp = master_list;
	while (tmp)
	{
		if (tmp->content_size == (size_t)fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("", 1);
	tmp->content_size = (size_t)fd;
	ft_lstadd(&master_list, tmp);
	return (master_list);
}

int				get_next_line(const int fd, char **line)
{
	t_list	*fd_node;
	int		ret;
	char	*buff;
	char	*tmp;

	buff = ft_strnew(BUFF_SIZE);
	if (fd < 0 || line == NULL || read(fd, *line, 0) < 0)
		return (-1);
	fd_node = find_fd(fd);
	while (!ft_strchr(LIST_STR, '\n') && (read(fd, buff, BUFF_SIZE)))
	{
		tmp = fd_node->content;
		fd_node->content = ft_strjoin(LIST_STR, buff);
		free(tmp);
		ft_bzero(buff, BUFF_SIZE + 1);
	}
	ret = ((LIST_STR)[NL] == '\n' || (ft_strlen(LIST_STR) > 0)) ? 1 : 0;
	*line = ft_strsub(LIST_STR, 0, NL);
	tmp = fd_node->content;
	fd_node->content = ft_strsub(LIST_STR, NL + 1, ft_strlen(LIST_STR + NL));
	free(tmp);
	free(buff);
	return (ret);
}
