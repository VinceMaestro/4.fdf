/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ullnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 17:24:07 by vpetit            #+#    #+#             */
/*   Updated: 2017/10/23 19:42:51 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int			ft_put_ullnbr(t_ull nbr)
{
	long int	buff;

	buff = '0';
	(nbr % 10 != nbr) ? (ft_put_ullnbr(nbr / 10)) : buff;
	buff = '0' + nbr % 10;
	write(1, &buff, 1);
	return (0);
}
