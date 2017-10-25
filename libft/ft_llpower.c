/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llpower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 15:34:47 by vpetit            #+#    #+#             */
/*   Updated: 2017/08/30 17:31:02 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_llpower(long long x, long long n)
{
	long long	value;

	value = 1;
	if (n > 0 && x > 1)
	{
		while (n)
		{
			value = value * x;
			n--;
		}
	}
	return (value);
}
