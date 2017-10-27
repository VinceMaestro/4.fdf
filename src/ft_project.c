/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_project.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 21:48:05 by vpetit            #+#    #+#             */
/*   Updated: 2017/10/27 21:26:32 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static float	ft_calc_proj_x(float x, float y, t_env *env)
{
	int			w;
	float		ret;
	u_int16_t	zoom;

	w = env->dim->w;
	zoom = env->zoom;
	ret = (0.7 * x - 0.7 * y) * zoom + env->x_off;
	return (ret);
}

static float	ft_calc_proj_y(float x, float y, float z, t_env *env)
{
	int			h;
	float		ret;
	u_int16_t	zoom;

	h = env->dim->h;
	zoom = env->zoom;
	ret = (0.82 * z - 0.41 * (x + y)) * -zoom + env->y_off;
	return (ret);
}

void			ft_project(t_env *env)
{
	int			i;

	i = 0;
	if (env)
	{
		while (!env->pts[i].last)
		{
			env->pts[i].x_proj = ft_calc_proj_x(env->pts[i].x, env->pts[i].y, \
				env);
			env->pts[i].y_proj = ft_calc_proj_y(env->pts[i].x, \
				env->pts[i].y, env->pts[i].z, env);
			i++;
		}
	}
}
