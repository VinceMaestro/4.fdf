/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullintlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 17:25:07 by vpetit            #+#    #+#             */
/*   Updated: 2017/08/30 17:25:09 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_ullintlen(unsigned long long nbr)
{
	size_t	len;

	len = 1;
	while (nbr && nbr != nbr % 10)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len);
}
