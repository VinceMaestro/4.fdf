/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 20:00:52 by vpetit            #+#    #+#             */
/*   Updated: 2017/10/24 21:42:41 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>

#include <stdio.h>

int		ft_key_hook(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	printf("key event %d\n", keycode);
	return (0);
}

int		ft_mouse_hook(int keycode, void *param)
{
	// if (keycode == 53)
	// 	exit(1);
	printf("key event %d\n", keycode);
	return (0);
}

int		ft_expose_hook(int keycode, void *param)
{
	// if (keycode == 53)
	// 	exit(1);
	printf("key event %d\n", keycode);
	return (0);
}

int		ft_loop_hook(int keycode, void *param)
{
	// if (keycode == 53)
	// 	exit(1);
	printf("key event %d\n", keycode);
	return (0);
}

static void		ft_caller_fdf(char *filename)
{
	int		open_fd;

	open_fd = open(filename, O_RDONLY);
	if (open_fd == -1)
		ft_error("open file () failed \n");
	else if (is_valid(open_fd))
		ft_fdf();
	if (close(open_fd) == -1)
		ft_error("close file () failed \n");
	return (0);
}

int				main(int argc, char **argv)
{
	if (argc == 2)
		ft_caller_fdf(argv[1]);
	else
		ft_putstr("usage: ./fdf source\n");
	return (0);
}

static void		ft_fdf(open_fd)
{
	void		*mlx;
	void		*win;
	int			x;
	int			y;

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
	return (0);
}
