/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_llnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 14:45:52 by vpetit            #+#    #+#             */
/*   Updated: 2017/10/21 10:26:32 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int	ft_put_llnbr_neg(t_ll nbr)
{
	char	buff;

	(nbr % 10 != nbr) ? (ft_put_llnbr_neg(nbr / 10)) : (write(1, "-", 1));
	buff = '0' + nbr % 10;
	write(1, &buff, 1);
	return (0);
}

int			ft_put_llnbr(t_ll nbr)
{
	long long	buff;

	buff = '0';
	if (nbr == LLONG_MIN)
		return (write(1, "-9223372036854775808", 20));
	else if (nbr < 0)
		return (ft_put_llnbr_neg(-nbr));
	(nbr % 10 != nbr) ? (ft_put_llnbr(nbr / 10)) : buff;
	buff = '0' + nbr % 10;
	write(1, &buff, 1);
	return (0);
}
