/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 20:44:22 by vpetit            #+#    #+#             */
/*   Updated: 2017/10/25 21:28:56 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_is_valid(int open_fd, t_env *env)
{
	char		*line;
	char		**args;
	int			err;
	int			;
	int			len;

	err = 0;
	line = NULL;
	len = 0;
	while (get_next_line(open_fd, &line) && !err)
	{
		args = ft_strsplit(line, ' ');
		ft_strdel(&line);
		err = ft_arr_str_to_arr_int();
		len++;
	}

}
