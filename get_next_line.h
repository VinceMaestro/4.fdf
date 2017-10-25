/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 07:16:16 by vpetit            #+#    #+#             */
/*   Updated: 2017/03/25 21:46:35 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_get_next_line_list	t_gnl_list;

struct	s_get_next_line_list
{
	char		*cont;
	int			cont_sze;
	int			offset;
	int			pos;
	int			fd;
	int			ret;
	t_gnl_list	*next;
	t_gnl_list	*first;
};

# ifndef BUFF_SIZE
#  define BUFF_SIZE 8
# endif

int		get_next_line(const int fd, char **line);

#endif
