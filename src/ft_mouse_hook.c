/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_hook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:05:12 by vpetit            #+#    #+#             */
/*   Updated: 2017/10/25 18:05:49 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

#include <stdio.h>

int		ft_mouse_hook(int keycode, t_env *env)
{
	// if (keycode == 1)
		// ft_rot(LEFT)
	// else if (keycode == 2)
		// ft_rot(RIGHT)
	if (env)
		printf("key event %d\n", keycode);
	return (0);
}
