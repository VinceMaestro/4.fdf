/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 15:50:24 by vpetit            #+#    #+#             */
/*   Updated: 2017/10/21 12:38:08 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_ltoabase(t_l nbr, const char *base)
{
	char	*str;
	t_ul	cp_nbr;
	int		i;
	t_ul	base_len;

	if (!nbr || !base || !*base)
		return (ft_strdup("0"));
	cp_nbr = (t_ul)nbr;
	base_len = (t_ul)ft_strlen(base);
	i = 0;
	while (cp_nbr)
	{
		cp_nbr /= base_len;
		i++;
	}
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = 0;
	cp_nbr = (t_ul)nbr;
	while (--i >= 0)
	{
		str[i] = base[cp_nbr % base_len];
		cp_nbr /= base_len;
	}
	return (str);
}
