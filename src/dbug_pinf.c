#include <stdio.h>

void			dbug_pinf(t_inf_line *inf)
{
	if (!inf)
		return ;
	printf("inf_line : x = %f ; y = %f ; dx = %f ; dy = %f ; xinc = %f ; yinc = %f ; sum = %f\n", \
		inf->x, inf->y, inf->dx, inf->dy, inf->xinc, inf->yinc, inf->sum);
}
