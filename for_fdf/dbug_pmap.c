#include "../include/fdf.h"

void    dbug_pmap(t_env *env)
{
	int		i;

	i = 0;
	if (env)
	{
		ft_putstr("\t||\tenv->dim->w = ");
		ft_putnbr(env->dim->w);
		ft_putstr("\t||\tenv->dim->h = ");
		ft_putnbr(env->dim->h);
		ft_putstr("\t||\n");
		while (!env->pts[i].last)
		{
			if (i && !(i % env->dim->w))
				ft_putchar('\n');
			ft_putnbr(env->pts[i].z);
			ft_putchar(' ');
			i++;
		}
	}
	ft_putchar('\n');
}
