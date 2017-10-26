#include "../include/fdf.h"

#include <stdio.h>

static float	ft_calc_proj_x(float x, float y, u_int16_t zoom)
{
	float	   ret;

	ret = (0.7 * x - 0.7 * y) * zoom;
	return (ret);
}

static float	ft_calc_proj_y(float x, float y, float z, u_int16_t zoom)
{
	float	   ret;

	ret = -1 * (0.82 * z - 0.41 * (x + y)) * zoom;
	return (ret);
}

void		   	ft_project(t_env *env)
{
	int			i;

	i = 0;
	if (env)
	{
		while (!env->pts[i].last)
		{
			env->pts[i].x_proj = ft_calc_proj_x(env->pts[i].x, env->pts[i].y, \
				env->zoom);
			env->pts[i].y_proj = ft_calc_proj_y(env->pts[i].x, \
				env->pts[i].y, env->pts[i].y, env->zoom);
			mlx_pixel_put(env->mlx, env->win, env->pts[i].x_proj, \
				env->pts[i].y_proj, env->color);// + get_hex(env->pts[i].z)
			i++;
		}
	}
	printf("i've seen %i char", i);
}
