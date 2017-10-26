#include "libft.h"

int			ft_get_arr_len(char **args)
{
	int		len;

	len = 0;
	if (!args)
		return (0);
	while (args[len])
		len++;
	return (len);
}
