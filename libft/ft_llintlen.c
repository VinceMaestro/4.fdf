/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llintlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 17:31:46 by vpetit            #+#    #+#             */
/*   Updated: 2017/09/26 17:43:08 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_llintlen(long long nbr)
{
	int		len;

	len = 1;
	nbr < 0 ? len++ : len;
	while (nbr && nbr != nbr % 10)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len);
}
