/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:01:49 by vpetit            #+#    #+#             */
/*   Updated: 2017/10/28 00:51:34 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

#include <stdio.h>

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
	// printf("min_y = %f\nmax_y = %f\n", min_y, max_y);
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

static void			init_var_and_center_screen(t_env *env)
{
	env->zoom = OP_ZOOM0;
	env->color = DEF_COL;
	env->x_off = 0;
	env->y_off = 0;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIN_W, WIN_H, "mlx 42");
	ft_project(env);
	get_y_info_for_screen_center(env);
	get_def_zoom(env);
	ft_project(env);
	get_y_info_for_screen_center(env);
	center_screen(env);
	// printf("WIN_H = %i\nenv->delta_y = %f\nenv->zoom = %f\n\
	// env->x_off = %f\nenv->y_off = %f\ntmp_y_end = %f\n\
	// env->pts[env->dim->w * env->dim->h - 1].y_proj = %f\n", \
	// WIN_H, env->delta_y, env->zoom, env->x_off, env->y_off, \
	// tmp_y_end, env->pts[env->dim->w * env->dim->h - 1].y_proj);
}

void				fdf(t_env *env)
{
	if (!env)
		ft_error("Error\n");
	init_var_and_center_screen(env);
	ft_project(env);
	ft_draw_all_lines(env);
	mlx_key_hook(env->win, ft_key_hook, (void*)env);
	mlx_loop(env->mlx);
}
