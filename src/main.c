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

#include "../include/fdf.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#include <stdio.h>

int		ft_loop_hook(int keycode, void *param)
{
	// if (keycode == 53)
	// 	exit(1);
	if (param)
		printf("key event %d\n", keycode);
	return (0);
}

static void		ft_caller_fdf(char *filename)
{
	int		fd;
	int		fd2;
	int		ret;
	t_env	*env;

	// while (get_next_line(fd, &line))
	// 	updt_map(env, line);
	ret = 0;
	fd2 = 0;
	env = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1 || !(env = (t_env*)malloc(sizeof(t_env))))
		fd == -1 ? ft_error("open file () failed \n") : ft_error("Malloc KO\n");
	if ((ft_get_dim(fd, env) == INVALID) || (ret = close(fd) == -1))
		ret == -1 ? ft_error("close file () failed \n") : ft_error("Error\n");
	else if ((fd2 = open(filename, O_RDONLY)) == -1)
		ft_error("open file () failed \n");
	else if (ft_get_pts(fd2, env) != VALID || (ret = close(fd2) == -1))
		ret == -1 ? ft_error("close file () failed \n") : ft_error("Error\n");
	fdf(fd2, env);
}

int				main(int argc, char **argv)
{
	if (argc == 2)
		ft_caller_fdf(argv[1]);
	else
		ft_putstr("usage: ./fdf source\n");
	return (0);
}
