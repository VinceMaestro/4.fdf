/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 17:24:34 by vpetit            #+#    #+#             */
/*   Updated: 2017/08/30 17:24:35 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnstr(void *str, int len)
{
	char	*buff;
	int		i;

	if (str && len > 0)
	{
		buff = str;
		i = 0;
		while (buff[i] && i < len)
		{
			write(1, &(buff[i]), 1);
			i += 1;
		}
	}
}
