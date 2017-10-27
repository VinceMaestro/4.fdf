/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:03:19 by vpetit            #+#    #+#             */
/*   Updated: 2017/10/27 19:05:43 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WIN_W		1720
# define WIN_H		1080

# define K_ESC		53
# define K_QUIT		12

# define K_DEF_COL	2
# define K_R_COL	15
# define K_G_COL	5
# define K_B_COL	11
# define K_PINK_COL	35

# define K_ZOOM_IN	4
# define K_ZOOM_OUT	5

# define K_ZOOM0	18
# define K_ZOOM1	19
# define K_ZOOM2	20
# define K_ZOOM3	21
# define K_ZOOM4	23
# define K_ZOOM5	22
# define K_ZOOM6	26

# define K_LEFT		123
# define K_RIGHT	124
# define K_UP		126
# define K_DOWN		125

# define VALID		1
# define INVALID	-1

# define OP_ZOOM0	(1 << 0)
# define OP_ZOOM1	(1 << 1)
# define OP_ZOOM2	(1 << 2)
# define OP_ZOOM3	(1 << 3)
# define OP_ZOOM4	(1 << 4)
# define OP_ZOOM5	(1 << 5)
# define OP_ZOOM6	(1 << 6)

# define DEF_ZOOM	(1 << 0)

# define DEF_COL	0x007F0080
# define R_COL		0x00FF0000
# define G_COL		0x0000FF00
# define B_COL		0x000000FF
# define PINK_COL	0x00FF1CAE

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "get_next_line.h"
# include <math.h>

typedef struct s_env		t_env;
typedef struct s_pts		t_pts;
typedef struct s_dim		t_dim;
typedef struct s_inf_line	t_inf_line;

struct		s_env
{
	void		*mlx;
	void		*win;
	t_pts		*pts;
	t_dim		*dim;
	int			color;
	int			zoom;
	int			delta_x;
	int			delta_y;
	int			x_off;
	int			y_off;
};

struct		s_dim
{
	int		w;
	int		h;
};

struct		s_pts
{
	float			x;
	float			y;
	float			z;
	float			x_proj;
	float			y_proj;
	float			last;
};

struct		s_inf_line
{
	float			x;
	float			y;
	float			dx;
	float			dy;
	float			xinc;
	float			yinc;
	float			sum;
};

void		fdf(t_env *env);
int			ft_key_hook(int k, t_env *env);
int			ft_get_dim(int fd, t_env *env);
int			ft_get_pts(int fd, t_env *env);
void		ft_draw_all_lines(t_env *env);
void		ft_project(t_env *env);

#endif
