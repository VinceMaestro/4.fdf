/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 17:29:40 by vpetit            #+#    #+#             */
/*   Updated: 2017/10/27 17:29:40 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void		ft_get_xyz_pos(char **args, t_env *env, int h)
{
	int		i;
	int		mod;

	i = 0;
	mod = env->dim->w;
	if (!args || !env)
		ft_error("Error\n");
	while (args[i] && !(env->pts[(h * mod) + i].last))
	{
		env->pts[(h * mod) + i].x = i;
		env->pts[(h * mod) + i].y = h;
		env->pts[(h * mod) + i].z = ft_atoi(args[i]);
		i++;
	}
	while (i < mod)
	{
		env->pts[(h * mod) + i].x = i;
		env->pts[(h * mod) + i].y = h;
		env->pts[(h * mod) + i].z = 0;
		i++;
	}
}

int				ft_get_pts(int fd, t_env *env)
{
	char		*line;
	char		**args;
	int			total;
	int			h;

	line = NULL;
	h = 0;
	total = env->dim->h * env->dim->w;
	if (!(env->pts = (t_pts*)malloc(sizeof(t_pts) * (total + 1))))
		ft_error("Malloc KO\n");
	env->pts[total].last = 1;
	while (--total >= 0)
		env->pts[total].last = 0;
	while (get_next_line(fd, &line))
	{
		args = ft_strsplit(line, ' ');
		ft_strdel(&line);
		ft_get_xyz_pos(args, env, h);
		h++;
	}
	return (VALID);
}
