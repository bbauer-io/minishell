/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbauer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 15:55:06 by bbauer            #+#    #+#             */
/*   Updated: 2017/01/12 13:50:01 by bbauer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gnl		*find_fd_in_list(int const fd, t_gnl *list)
{
	if (list)
		while (list->fd != fd && list->next)
			list = list->next;
	if (list && list->fd != fd && !list->next)
	{
		if (NULL == (list->next = (t_gnl *)malloc(sizeof(t_gnl))))
			return (NULL);
		list = list->next;
		list->fd = fd;
		list->file = NULL;
		list->current_line = NULL;
		list->next = NULL;
	}
	else if (!list || (!list->next && fd != list->fd))
	{
		if (NULL == (list = (t_gnl *)malloc(sizeof(t_gnl))))
			return (NULL);
		list->fd = fd;
		list->file = NULL;
		list->current_line = NULL;
		list->next = NULL;
	}
	return (list);
}

void			null_termination_check(t_gnl *li, int length)
{
	if (li->file[length - 1] != '\0')
	{
		li->file = ft_realloc(li->file, length, 1);
		li->file[length] = '\0';
	}
	return ;
}

void			read_delengthenizer(t_gnl *li, int ret, char *buffer)
{
	li->file = ft_realloc(li->file, ft_strlen(li->file) + 1, ret);
	ft_strcat(li->file, buffer);
	return ;
}

int				read_file(int const fd, t_gnl *li)
{
	int		ret;
	char	buffer[BUFF_SIZE + 1];
	int		length;

	length = 0;
	ret = 1;
	while (ret)
	{
		if (-1 == (ret = read(fd, buffer, BUFF_SIZE)))
			return (-1);
		buffer[ret] = '\0';
		if (!li->file)
		{
			li->file = (char *)malloc(sizeof(char) * (ret + 1));
			ft_strcpy(li->file, buffer);
			li->file[ret] = '\0';
		}
		else if (ret)
			read_delengthenizer(li, ret, buffer);
		length += ret;
	}
	null_termination_check(li, length);
	li->current_line = li->file;
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static t_gnl		*list;
	t_gnl				*li;

	if (NULL == (li = find_fd_in_list(fd, list)))
		return (-1);
	if (!list)
		list = li;
	if (!line || fd < 0)
		return (-1);
	if (!(li->file))
		if (-1 == read_file(fd, li))
			return (-1);
	if (li->current_line && *li->current_line == '\n')
		li->current_line++;
	if (li->current_line == NULL || *li->current_line == '\0')
	{
		*line = NULL;
		return (0);
	}
	*line = ft_strndup(li->current_line, ft_wrdlen(li->current_line, '\n'));
	li->current_line = ft_strchr(li->current_line, '\n');
	return (1);
}
