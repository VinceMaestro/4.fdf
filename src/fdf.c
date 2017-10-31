/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:01:49 by vpetit            #+#    #+#             */
/*   Updated: 2017/10/31 15:55:32 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void				fdf(t_env *env)
{
	if (!env)
		ft_error("Error\n");
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIN_W, WIN_H, "mlx 42");
	ft_init_var_and_center_screen(env);
	ft_project(env);
	ft_draw_all_lines(env);
	mlx_key_hook(env->win, ft_key_hook, (void*)env);
	mlx_loop(env->mlx);
}
