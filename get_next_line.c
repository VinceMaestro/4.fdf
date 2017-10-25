/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 07:16:02 by vpetit            #+#    #+#             */
/*   Updated: 2017/09/29 18:35:08 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl_list	*ft_read_next(t_gnl_list *fd_lst)
{
	char	*new;
	int		reader;
	int		rl_size;

	rl_size = fd_lst->cont_sze - fd_lst->offset;
	new = ft_strnew(rl_size + BUFF_SIZE + 1);
	ft_bzero(new, rl_size + BUFF_SIZE + 1);
	new = ft_strncpy(new, &fd_lst->cont[fd_lst->offset], rl_size);
	ft_strdel(&fd_lst->cont);
	if (!(reader = read(fd_lst->fd, &new[rl_size], BUFF_SIZE)))
	{
		fd_lst->pos = rl_size + reader;
		fd_lst->ret = 2;
	}
	else if (reader == -1)
		fd_lst->ret = 1;
	else if (reader != BUFF_SIZE)
		fd_lst->pos = rl_size + reader;
	fd_lst->cont = new;
	fd_lst->cont_sze = rl_size + ft_min(reader, BUFF_SIZE);
	fd_lst->offset = 0;
	return (fd_lst);
}

static t_gnl_list	*ft_getstr_pos(t_gnl_list *fd_lst)
{
	char	*rest;

	fd_lst->ret = 0;
	fd_lst->pos = -1;
	while (!fd_lst->ret)
	{
		rest = ft_strchr(&fd_lst->cont[fd_lst->offset], '\n');
		if (rest || fd_lst->pos != -1)
		{
			if (rest)
				fd_lst->pos = (rest - fd_lst->cont);
			fd_lst->cont[fd_lst->pos] = 0;
			fd_lst->ret = 3;
		}
		else if (!fd_lst->ret)
			fd_lst = ft_read_next(fd_lst);
	}
	return (fd_lst);
}

static t_gnl_list	*ft_create_lst_fd(t_gnl_list *fd_lst, int fd)
{
	t_gnl_list	*new;

	if (!(new = (t_gnl_list*)malloc(sizeof(t_gnl_list))))
		return (NULL);
	if (fd_lst)
		new->first = fd_lst->first;
	else
		new->first = new;
	new->next = NULL;
	new->cont = NULL;
	new->cont_sze = 0;
	new->offset = 0;
	new->pos = 0;
	new->fd = fd;
	new->ret = 0;
	return (new);
}

static t_gnl_list	*ft_get_lst_fd(t_gnl_list *fd_lst, int fd)
{
	if (fd_lst)
	{
		if (fd_lst->fd != fd)
			fd_lst = fd_lst->first;
		while (fd_lst->next && fd_lst->fd != fd)
			fd_lst = fd_lst->next;
		if (fd_lst->fd != fd)
		{
			fd_lst->next = ft_create_lst_fd(fd_lst, fd);
			fd_lst = fd_lst->next;
		}
	}
	else
		fd_lst = ft_create_lst_fd(fd_lst, fd);
	return (fd_lst);
}

int					get_next_line(const int fd, char **line)
{
	static t_gnl_list	*fd_lst;
	int					ret;
	char				*str;

	ret = 0;
	if (fd < 0 || !line || BUFF_SIZE < 1)
		ret = -1;
	if (!ret)
	{
		fd_lst = ft_get_lst_fd(fd_lst, fd);
		fd_lst = ft_getstr_pos(fd_lst);
		str = ft_strdup(&fd_lst->cont[fd_lst->offset]);
		*line = str;
		fd_lst->offset = fd_lst->pos + 1;
		ret = fd_lst->ret - 2;
		if (!(ret != 0 || (*line && **line)))
			fd_lst->offset--;
	}
	return ((ret == -1) ? (-1) : (ret != 0 || (*line && **line)));
}
