/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_atol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 16:20:42 by vpetit            #+#    #+#             */
/*   Updated: 2017/10/27 16:35:56 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long		ft_base_atol(char *str, char *base)
{
	int		base_len;
	long	nbr;
	int		i;
	char	*pos;

	i = 0;
	nbr = 0;
	pos = NULL;
	base_len = ft_strlen(base);
	if (!str || !base)
		return (0);
	while (str[i] && (pos = ft_strchr(base, str[i])))
		nbr += (pos - base) * ft_llpower(base_len, i);
	return (pos ? nbr : 0);
}
