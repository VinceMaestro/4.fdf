#include "../include/fdf.h"

static float	ft_calc_proj_x(float x, float y, u_int16_t options)
{
	float	   ret;

	ret = (0.7 * x - 0.7 * y) * options + WIN_W / 2;
	return (ret);
}

static float	ft_calc_proj_y(float x, float y, float z, u_int16_t options)
{
	float	   ret;

	ret = (0.82 * z - 0.41 * (x + y)) * options + WIN_H / 2;
	return (ret);
}

void		   	ft_project(t_env *env, u_int16_t options)
{
	int			i;

	i = 0;
	if (env)
	{
		while (!env->pts[i].last)
		{
			env->pts[i].x_proj = ft_calc_proj_x(env->pts[i].x, env->pts[i].y, \
				options);
			env->pts[i].y_proj = ft_calc_proj_y(env->pts[i].x, \
				env->pts[i].y, env->pts[i].y, options);
			mlx_pixel_put(env->mlx, env->win, env->pts[i].x_proj, \
				env->pts[i].y_proj, DEF_COL);// + get_hex(env->pts[i].z)
			i++;
		}
	}
}
