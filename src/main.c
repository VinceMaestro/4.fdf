/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 20:00:52 by vpetit            #+#    #+#             */
/*   Updated: 2017/10/31 16:03:31 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

static void		ft_error_checker_fdf_caller(char *filename)
{
	int		fd;
	int		fd2;
	int		ret;
	t_env	*env;

	ret = 0;
	fd2 = 0;
	env = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1 || !(env = (t_env*)malloc(sizeof(t_env))))
		fd == -1 ? ft_error("open file () failed \n") : ft_error("Malloc KO\n");
	if ((ft_get_input_dim_w_h(fd, env) == INVALID) || (ret = close(fd) == -1))
		ret == -1 ? ft_error("close file () failed \n") : ft_error("Error\n");
	else if ((fd2 = open(filename, O_RDONLY)) == -1)
		ft_error("open file () failed \n");
	else if (ft_get_pts_coordinate(fd2, env) != VALID || \
		(ret = close(fd2) == -1))
		ret == -1 ? ft_error("close file () failed \n") : ft_error("Error\n");
	fdf(env);
}

int				main(int argc, char **argv)
{
	if (argc == 2)
		ft_error_checker_fdf_caller(argv[1]);
	else
		ft_putstr("usage: ./fdf source_file\n");
	return (0);
}
