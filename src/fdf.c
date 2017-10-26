/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:01:49 by vpetit            #+#    #+#             */
/*   Updated: 2017/10/25 20:38:41 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		fdf(int fd, t_env *env)
{
	u_int16_t	options;

	options = OP_ZOOM0;
	if (!fd)
		return ;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIN_W, WIN_H, "mlx 42");
	ft_project(env, options);
	ft_draw_all_lines(env);

	mlx_key_hook(env->win, ft_key_hook, (void*)env); // Keyboard Input
	mlx_mouse_hook(env->win, ft_mouse_hook, (void*)env); // Mouse Input
	// mlx_loop_hook(env->win, ft_loop_hook, 0); // Quand rien a faire?
	mlx_loop(env->mlx);
}
