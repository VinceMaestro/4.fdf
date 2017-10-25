/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 20:00:52 by vpetit            #+#    #+#             */
/*   Updated: 2017/10/25 20:43:15 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include <stdio.h>

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
	int		ret;
	t_env	env;

	// while (get_next_line(open_fd, &line))
	// 	updt_map(env, line);
	ret = 0;
	open_fd = open(filename, O_RDONLY);
	if (open_fd == -1)
		ft_error("open file () failed \n");
	if (ft_is_valid(open_fd, &env) && (ret = close(open_fd) != -1))
		fdf(&env);
	else
		ret == -1 ? ft_error("close file () failed \n") : ft_error("Error\n");
}

int				main(int argc, char **argv)
{
	if (argc == 2)
		ft_caller_fdf(argv[1]);
	else
		ft_putstr("usage: ./fdf source\n");
	return (0);
}
