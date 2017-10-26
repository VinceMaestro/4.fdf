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

#include "../include/fdf.h"

int			ft_get_dim(int fd, t_env *env)
{
	char		*line;
	char		**args;
	int			tmp;

	line = NULL;
	env->dim = (t_dim*)malloc(sizeof(t_dim));
	env->dim->h = 0;
	env->dim->w = 0;
	while (get_next_line(fd, &line))
	{
		args = ft_strsplit(line, ' ');
		ft_strdel(&line);
		tmp = ft_get_arr_len(args);
		env->dim->w = ft_max(env->dim->w, tmp);
		env->dim->h++;
	}
	return (env->dim->h && env->dim->w ? VALID : INVALID);
}
