#include "../include/fdf.h"

static void		init_inf_line(t_inf_line *inf, t_env *env, int i, int j)
{
	inf->x = env->pts[i].x;
	inf->y = env->pts[i].y;
	inf->dx = env->pts[i + j].x - env->pts[i].x;
	inf->dy = env->pts[i + j].y - env->pts[i].y;
	inf->xinc = (inf->dx > 0) ? 1 : -1;
	inf->yinc = (inf->dy > 0) ? 1 : -1;
	inf->dx = fabsf(inf->dx);
	inf->dy = fabsf(inf->dy);
}

static void		draw_right_line(t_env *env, t_inf_line *inf)
{
	int		i;

	i = 0;
	while (i <= inf->dx)
	{
		inf->x += inf->xinc;
		inf->sum += inf->dy;
		if (inf->sum >= inf->dx)
		{
			inf->sum -= inf->dx;
			inf->y += inf->yinc;
		}
		mlx_pixel_put(env->mlx, env->win, inf->x, inf->y, env->color);
		i++;
	}
}

static void		draw_down_line(t_env *env, t_inf_line *inf)
{
	int		i;

	i = 0;
	while (i <= inf->dy)
	{
		inf->y += inf->yinc;
		inf->sum += inf->dx;
		if (inf->sum >= inf->dy)
		{
			inf->sum -= inf->dy;
			inf->x += inf->xinc;
		}
		mlx_pixel_put(env->mlx, env->win, inf->x, inf->y, env->color);
		i++;
	}
}

static void		draw_one_line(t_env *env, int i, int j)
{
	t_inf_line		inf;

	init_inf_line(&inf, env, i, j);
	inf.sum = ft_fltmax(inf.dx, inf.dy) / 2;

	if (inf.dx > inf.dy)
		draw_right_line(env, &inf);
	else
		draw_down_line(env, &inf);
}

void		ft_draw_all_lines(t_env *env)
{
	int		tmp;
	int		i;

	i = 0;
	tmp = 0;
	while (!env->pts[i].last)
	{
		tmp = (int)env->pts[i].x;
		if (tmp % env->dim->w)
			draw_one_line(env, i, i + env->dim->w);
		if (env->pts[i].y < env->dim->h)
			draw_one_line(env, i, i + 1);
		i++;
	}
}
