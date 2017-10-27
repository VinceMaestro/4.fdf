/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_dim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 20:44:22 by vpetit            #+#    #+#             */
/*   Updated: 2017/10/27 21:08:03 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int			ft_get_dim(int fd, t_env *env)
{
	char		*line;
	char		**args;
	int			tmp;
	int			err;

	line = NULL;
	env->dim = (t_dim*)malloc(sizeof(t_dim));
	env->dim->h = 0;
	env->dim->w = 0;
	while ((err = get_next_line(fd, &line)) > 0)
	{
		args = ft_strsplit(line, ' ');
		ft_strdel(&line);
		tmp = ft_get_arr_len(args);
		env->dim->w = ft_max(env->dim->w, tmp);
		env->dim->h++;
	}
	if (err == -1)
		ft_error("usage: ./fdf source_file\n");
	return (env->dim->h && env->dim->w ? VALID : INVALID);
}
