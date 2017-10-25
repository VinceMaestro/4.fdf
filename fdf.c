/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:01:49 by vpetit            #+#    #+#             */
/*   Updated: 2017/10/25 18:06:01 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// gcc -o mlx main.c -lmlx -framework OpenGL -framework AppKit

void		fdf(int open_fd)
{
	void		*mlx;
	void		*win;
	int			x;
	int			y;

	// while (get_next_line(open_fd, &line))
	// 	updt_map(env, line);
	y = 50;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
	while (y < 150)
	{
		x = 50;
		while (x < 150)
			mlx_pixel_put(mlx, win, x++, y, 0x00AAAAAA);
		y++;
	}
	mlx_key_hook(win, ft_key_hook, 0); // Keyboard Input
	mlx_mouse_hook(win, ft_mouse_hook, 0); // Mouse Input
	mlx_expose_hook(win, ft_expose_hook, 0); // Display
	// mlx_loop_hook(win, ft_loop_hook, 0); // Quand rien a faire?
	mlx_loop(mlx);
}
