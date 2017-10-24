/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:25:36 by vpetit            #+#    #+#             */
/*   Updated: 2017/10/10 18:51:11 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

#include <stdio.h>

//======================================================================
// Classic main : take 1 argv


static int	ft_display_file(char *argv)
{
	int		open_fd;
	int		ret;
	char	*line;
	int		cpt = 0;

	ret = 1;
	line = NULL;

	open_fd = open(argv, O_RDONLY);

	if (open_fd == -1)
	{
		ft_putstr_fd("open file () failed \n", 2);
		return (-1);
	}

	while ((ret = get_next_line(open_fd, &line)) == 1)
	{
		ft_putend(line);
		free(line);
		// ft_putnbr(ret);
		cpt++;
	}

	// ft_putnbr(cpt);
	if (close(open_fd) == -1)
	{
		ft_putstr_fd("close file () failed \n", 2);
		return (-1);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putstr_fd("File name missing.\n", 2);
		return (-1);
	}
	else if (argc == 2)
		return (ft_display_file(argv[1]));
	ft_putstr_fd("Too many arguments.\n", 2);
	return (-1);
}



//======================================================================
// FOR 3 fd


/*

static int	ft_display_file(char *argv1, char *argv2, char *argv3)
{
	int		open_fd1;
	int		open_fd2;
	int		open_fd3;
	int		ret1;
	int		ret2;
	int		ret3;
	char	*line1;
	char	*line2;
	char	*line3;
	// int		cpt;

	// cpt = 0;
	ret1 = 1;
	ret2 = 1;
	ret3 = 1;
	line1 = NULL;
	line2 = NULL;
	line3 = NULL;
	open_fd1 = open(argv1, O_RDWR);
	open_fd2 = open(argv2, O_RDWR);
	open_fd3 = open(argv3, O_RDWR);
	if (open_fd1 == -1 || open_fd2 == -1 || open_fd3 == -1)
	{
		ft_putstr_fd("open file () failed \n", 2);
		return (-1);
	}
	while (ret1 == 1 || ret2 == 1 || ret3 == 1)
	{
		ret1 = get_next_line(open_fd1, &line1);
		ft_putstr(line1);
		if (ret1)
			ft_putstr("\n");
		// cpt++;
		ret2 = get_next_line(open_fd2, &line2);
		ft_putstr(line2);
		if (ret2)
			ft_putstr("\n");

		ret3 = get_next_line(open_fd3, &line3);
		ft_putstr(line3);
		if (ret3)
			ft_putstr("\n");
	}
	if (close(open_fd1) == -1 || close(open_fd2) == -1 || close(open_fd3) == -1)
	{
		ft_putstr_fd("close file () failed \n", 2);
		return (-1);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	if (argc != 4)
	{
		ft_putstr_fd("usage: ./gnl file1 file2 file3\n", 2);
		return (-1);
	}
	else
		return (ft_display_file(argv[1], argv[2], argv[3]));
}

*/


//======================================================================
// Multi fd FileChecker


/*

int				main(void)
{
	char	*line_fd0;
	int		p_fd0[2];
	int		fd0 = 0;
	int		out_fd0 = dup(fd0);

	char	*line_fd1;
	int		p_fd1[2];
	int		fd1 = 1;
	int		out_fd1 = dup(fd1);

	char	*line_fd2;
	int		p_fd2[2];
	int		fd2 = 2;
	int		out_fd2 = dup(fd2);

	char	*line_fd3;
	int		p_fd3[2];
	int		fd3 = 3;
	int		out_fd3 = dup(fd3);

	pipe(p_fd0);
	dup2(p_fd0[1], fd0);
	write(fd0, "aaa\nbbb\n", 8);
	dup2(out_fd0, fd0);
	close(p_fd0[1]);

	pipe(p_fd1);
	dup2(p_fd1[1], fd1);
	write(fd1, "111\n222\n", 8);
	dup2(out_fd1, fd1);
	close(p_fd1[1]);

	pipe(p_fd2);
	dup2(p_fd2[1], fd2);
	write(fd2, "www\nzzz\n", 8);
	dup2(out_fd2, fd2);
	close(p_fd2[1]);

	pipe(p_fd3);
	dup2(p_fd3[1], fd3);
	write(fd3, "888\n999\n", 8);
	dup2(out_fd3, fd3);
	close(p_fd3[1]);

	get_next_line(p_fd0[0], &line_fd0);
	if (strcmp(line_fd0, "aaa"))
	{
	}
	printf("'%s' vs '%s'\n", line_fd0, "aaa");
	get_next_line(p_fd1[0], &line_fd1);
	if (strcmp(line_fd1, "111"))
	{
	}
	printf("'%s' vs '%s'\n", line_fd1, "111");
	get_next_line(p_fd2[0], &line_fd2);
	if (strcmp(line_fd2, "www"))
	{
	}
	printf("'%s' vs '%s'\n", line_fd2, "www");
	get_next_line(p_fd3[0], &line_fd3);
	if (strcmp(line_fd3, "888"))
	{
	}
	printf("'%s' vs '%s'\n", line_fd3, "888");
	get_next_line(p_fd0[0], &line_fd0);
	if (strcmp(line_fd0, "bbb"))
	{
	}
	printf("'%s' vs '%s'\n", line_fd0, "bbb");
	get_next_line(p_fd1[0], &line_fd1);
	if (strcmp(line_fd1, "222"))
	{
	}
	printf("'%s' vs '%s'\n", line_fd1, "222");
	get_next_line(p_fd2[0], &line_fd2);
	if (strcmp(line_fd2, "zzz"))
	{
	}
	printf("'%s' vs '%s'\n", line_fd2, "zzz");
	get_next_line(p_fd3[0], &line_fd3);
	if (strcmp(line_fd3, "999"))
	{
	}
	printf("'%s' vs '%s'\n", line_fd3, "999");
	return (0);
}

*/
