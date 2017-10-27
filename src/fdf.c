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

static void			get_deltas(t_env *env)
{
	int			i;
	float		max_y;
	float		min_y;

	i = -1;
	env->delta_y = 0;
	min_y = env->pts[0].y_proj;
	max_y = env->pts[0].y_proj;
	while (!env->pts[++i].last)
	{
		min_y = env->pts[i].y_proj < min_y ? \
			env->pts[i].y_proj : min_y;
		max_y = env->pts[i].y_proj > max_y ? \
			env->pts[i].y_proj : max_y;
	}
	if (max_y > min_y)
		env->delta_y = max_y - min_y;
	env->delta_x = env->pts[env->dim->w].x - \
		env->pts[env->dim->w * (env->dim->h - 1)].x;
}

static int			get_def_zoom(t_env *env)
{
	if (env->dim->w * OP_ZOOM6 < WIN_W && env->dim->h * OP_ZOOM6 < WIN_H \
		&& env->delta_y * OP_ZOOM6 < WIN_H)
		return (OP_ZOOM6);
	else if (env->dim->w * OP_ZOOM5 < WIN_W && env->dim->h * OP_ZOOM5 < WIN_H \
		&& env->delta_y * OP_ZOOM5 < WIN_H)
		return (OP_ZOOM5);
	else if (env->dim->w * OP_ZOOM4 < WIN_W && env->dim->h * OP_ZOOM4 < WIN_H \
		&& env->delta_y * OP_ZOOM4 < WIN_H)
		return (OP_ZOOM4);
	else if (env->dim->w * OP_ZOOM3 < WIN_W && env->dim->h * OP_ZOOM3 < WIN_H \
		&& env->delta_y * OP_ZOOM3 < WIN_H)
		return (OP_ZOOM3);
	else if (env->dim->w * OP_ZOOM2 < WIN_W && env->dim->h * OP_ZOOM2 < WIN_H \
		&& env->delta_y * OP_ZOOM2 < WIN_H)
		return (OP_ZOOM2);
	else if (env->dim->w * OP_ZOOM1 < WIN_W && env->dim->h * OP_ZOOM1 < WIN_H \
		&& env->delta_y * OP_ZOOM1 < WIN_H)
		return (OP_ZOOM1);
	else
		return (DEF_ZOOM);
}

void				fdf(t_env *env)
{
	if (!env)
		ft_error("Error\n");
	env->zoom = OP_ZOOM0;
	env->color = DEF_COL;
	env->x_off = 0;
	env->y_off = 0;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIN_W, WIN_H, "mlx 42");
	ft_project(env);
	get_deltas(env);
	env->zoom = get_def_zoom(env);
	ft_project(env);
	get_deltas(env);

	float	tmp_y_end;
	float	tmp_y_first;

	tmp_y_end = (-0.41 * (env->pts[env->dim->w * env->dim->h - 1].x + env->pts[env->dim->w * env->dim->h - 1].y)) * env->zoom;
	tmp_y_first = (-0.41 * (env->pts[0].x + env->pts[0].y)) * env->zoom;
	env->x_off = (WIN_W - env->delta_x) / 2;
	env->y_off = (WIN_H - env->delta_y + (tmp_y_first - tmp_y_end)) / 2;

	printf("WIN_H = %i\nenv->delta_y = %f\nenv->zoom = %f\nenv->x_off = %f\nenv->y_off = %f\ntmp_y_end = %f\ntmp_y_first = %f\n", WIN_H, env->delta_y, env->zoom, env->x_off, env->y_off, tmp_y_end, tmp_y_first);

	// env->x_off = WIN_W / 2 - (((env->pts[env->dim->w].x_proj - env->pts[env->dim->w * (env->dim->h - 1)].x_proj) * env->zoom) / 2);
	// env->y_off = (WIN_H / 2) - (((env->pts[env->dim->w * env->dim->h - 1].y_proj - env->pts[0].y_proj) / 2) * env->zoom) + ((env->delta_y * env->zoom) / 2);// - ( / 2 * env->zoom);
	ft_project(env);
	ft_draw_all_lines(env);
	mlx_key_hook(env->win, ft_key_hook, (void*)env);
	mlx_loop(env->mlx);
}
