#include "../include/fdf.h"

void		ft_put_pixel_on_image(t_env *env, float x, float y)
{
	t_l		pos;

	pos = ((int)x * env->bits_per_pixel / 8) + ((int)y * env->size_line);
	if ((int)x > 0 && (int)x < WIN_W && (int)y > 0 && (int)y < WIN_H)
	{
		env->data[pos] = (env->color) % 256;
		env->data[pos + 1] = (env->color >> 8) % 256;
		env->data[pos + 2] = (env->color >> 16) % 256;
	}
}
