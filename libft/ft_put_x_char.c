/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 15:18:18 by vpetit            #+#    #+#             */
/*   Updated: 2017/09/23 13:55:33 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void		ft_put_x_char(char c, int nbr)
{
	int		i;

	i = 0;
	if (c && nbr > 0)
	{
		while (i < nbr)
		{
			write(1, &c, 1);
			i++;
		}
	}
}
