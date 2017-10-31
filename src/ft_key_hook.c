/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:00:24 by vpetit            #+#    #+#             */
/*   Updated: 2017/10/31 16:21:20 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/fdf.h"

static void			updt_offset(t_env *env, int k)
{
	if (k == K_LEFT || k == K_RIGHT)
		env->x_off += k == K_RIGHT ? (WIN_W / 10) : (-WIN_W / 10);
	if (k == K_UP || k == K_DOWN)
		env->y_off += k == K_UP ? (-WIN_H / 10) : (WIN_H / 10);
}

static void			updt_color(t_env *env, int k)
{
	if (k == K_R_COL)
		env->color = R_COL;
	else if (k == K_G_COL)
		env->color = G_COL;
	else if (k == K_B_COL)
		env->color = B_COL;
	else if (k == K_PINK_COL)
		env->color = PINK_COL;
	else
		env->color = DEF_COL;
}

static void			updt_zoom(t_env *env, int k)
{
	env->zoom = OP_ZOOM0;
	if (k == K_ZOOM1)
		env->zoom = OP_ZOOM1;
	if (k == K_ZOOM2)
		env->zoom = OP_ZOOM2;
	if (k == K_ZOOM3)
		env->zoom = OP_ZOOM3;
	if (k == K_ZOOM4)
		env->zoom = OP_ZOOM4;
	if (k == K_ZOOM5)
		env->zoom = OP_ZOOM5;
	if (k == K_ZOOM6)
		env->zoom = OP_ZOOM6;
}

int					ft_key_hook(int k, t_env *env)
{
	int			modif;

	modif = 0;
	if (k == K_ESC || k == K_QUIT)
	{
		mlx_destroy_window(env->mlx, env->win);
		exit(0);
	}
	if ((k == K_R_COL || k == K_G_COL || k == K_B_COL || k == K_PINK_COL || \
		k == K_DEF_COL) && (modif++ || 1))
		updt_color(env, k);
	if ((k >= K_ZOOM0 && k <= K_ZOOM6) && (modif++ || 1))
		updt_zoom(env, k);
	if ((k == K_LEFT || k == K_RIGHT || k == K_UP || k == K_DOWN) && \
		(modif++ || 1))
		updt_offset(env, k);
	if (modif || k == K_RESET)
	{
		mlx_clear_window(env->mlx, env->win);
		(k == K_RESET ? ft_init_var_and_center_screen(env) : NULL);
		ft_project(env);
		ft_draw_all_lines(env);
	}
	return (0);
}
