/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 14:50:01 by vpetit            #+#    #+#             */
/*   Updated: 2017/10/21 12:37:38 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_itoabase(int nbr, const char *base)
{
	char	*str;
	t_ui	cp_nbr;
	int		i;
	int		base_len;

	if (!nbr || !base || !*base)
		return (ft_strdup("0"));
	cp_nbr = (t_ui)nbr;
	base_len = ft_strlen(base);
	i = 0;
	while (cp_nbr)
	{
		cp_nbr /= base_len;
		i++;
	}
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i] = 0;
	cp_nbr = (t_ui)nbr;
	while (--i >= 0)
	{
		str[i] = base[cp_nbr % base_len];
		cp_nbr /= base_len;
	}
	return (str);
}
