/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:01:49 by vpetit            #+#    #+#             */
/*   Updated: 2017/10/26 13:59:17 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		fdf(int fd, t_env *env)
{
	if (!fd)
		return ;
	env->zoom = DEF_ZOOM;
	env->color = DEF_COL;
	env->x_off = 0;
	env->y_off = 0;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIN_W, WIN_H, "mlx 42");
	ft_project(env);
	ft_draw_all_lines(env);

	mlx_key_hook(env->win, ft_key_hook, (void*)env); // Keyboard Input
	mlx_mouse_hook(env->win, ft_mouse_hook, (void*)env); // Mouse Input
	// mlx_loop_hook(env->win, ft_loop_hook, 0); // Quand rien a faire?
	mlx_loop(env->mlx);
}
