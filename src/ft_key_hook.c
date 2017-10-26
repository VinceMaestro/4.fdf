/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:00:24 by vpetit            #+#    #+#             */
/*   Updated: 2017/10/25 16:02:42 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../include/fdf.h"

#include <stdio.h>

static u_int16_t	get_zoom(int k)
{
	if (k == K_ZOOM1)
		return (OP_ZOOM1);
	if (k == K_ZOOM2)
		return (OP_ZOOM2);
	if (k == K_ZOOM3)
		return (OP_ZOOM3);
	if (k == K_ZOOM4)
		return (OP_ZOOM4);
	if (k == K_ZOOM5)
		return (OP_ZOOM5);
	if (k == K_ZOOM6)
		return (OP_ZOOM6);
	if (k == K_ZOOM7)
		return (OP_ZOOM7);
	return (OP_ZOOM0);
}

int					ft_key_hook(int k, t_env *env)
{
	if (env)
		printf("key event %d\n", k);
	if (k == K_ESC)
	{
		mlx_destroy_window(env->mlx, env->win);
		exit(0);
	}
	else if (k >= K_ZOOM0 && k <= K_ZOOM7)
	{
		mlx_clear_window(env->mlx, env->win);
		ft_project(env, get_zoom(k));
		ft_draw_all_lines(env);
	}
	return (0);
}
