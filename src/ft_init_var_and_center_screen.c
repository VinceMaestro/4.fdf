/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_var_and_center_screen.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:51:40 by vpetit            #+#    #+#             */
/*   Updated: 2017/10/31 16:20:35 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void			center_screen(t_env *env)
{
	env->x_off = -env->pts[env->dim->w * env->dim->h - 1].x_proj + WIN_W / 2 - \
		(env->pts[env->dim->w - 1].x - \
			env->pts[env->dim->w * env->dim->h - 1].x_proj) / 2;
	env->y_off = -env->pts[env->pts_y_min].y_proj + (WIN_H - env->delta_y) / 2;
}

static void			get_y_info_for_screen_center(t_env *env)
{
	int			i;
	float		max_y;
	float		min_y;

	i = -1;
	env->pts_y_min = 0;
	min_y = env->pts[0].y_proj;
	max_y = env->pts[0].y_proj;
	while (!env->pts[++i].last)
	{
		env->pts_y_min = env->pts[i].y_proj < min_y ? i : env->pts_y_min;
		min_y = env->pts[i].y_proj < min_y ? \
			env->pts[i].y_proj : min_y;
		max_y = env->pts[i].y_proj > max_y ? \
			env->pts[i].y_proj : max_y;
	}
	env->delta_y = max_y - min_y;
}

static void			get_def_zoom(t_env *env)
{
	if (env->dim->w * OP_ZOOM6 < WIN_W && env->dim->h * OP_ZOOM6 < WIN_H \
		&& env->delta_y * OP_ZOOM6 < WIN_H)
		env->zoom = OP_ZOOM6;
	else if (env->dim->w * OP_ZOOM5 < WIN_W && env->dim->h * OP_ZOOM5 < WIN_H \
		&& env->delta_y * OP_ZOOM5 < WIN_H)
		env->zoom = OP_ZOOM5;
	else if (env->dim->w * OP_ZOOM4 < WIN_W && env->dim->h * OP_ZOOM4 < WIN_H \
		&& env->delta_y * OP_ZOOM4 < WIN_H)
		env->zoom = OP_ZOOM4;
	else if (env->dim->w * OP_ZOOM3 < WIN_W && env->dim->h * OP_ZOOM3 < WIN_H \
		&& env->delta_y * OP_ZOOM3 < WIN_H)
		env->zoom = OP_ZOOM3;
	else if (env->dim->w * OP_ZOOM2 < WIN_W && env->dim->h * OP_ZOOM2 < WIN_H \
		&& env->delta_y * OP_ZOOM2 < WIN_H)
		env->zoom = OP_ZOOM2;
	else if (env->dim->w * OP_ZOOM1 < WIN_W && env->dim->h * OP_ZOOM1 < WIN_H \
		&& env->delta_y * OP_ZOOM1 < WIN_H)
		env->zoom = OP_ZOOM1;
	else
		env->zoom = DEF_ZOOM;
}

void				ft_init_var_and_center_screen(t_env *env)
{
	env->zoom = OP_ZOOM0;
	env->color = DEF_COL;
	env->x_off = 0;
	env->y_off = 0;
	ft_project(env);
	get_y_info_for_screen_center(env);
	get_def_zoom(env);
	ft_project(env);
	get_y_info_for_screen_center(env);
	center_screen(env);
}
