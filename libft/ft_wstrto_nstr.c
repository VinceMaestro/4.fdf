/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrto_nstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 14:38:55 by vpetit            #+#    #+#             */
/*   Updated: 2017/10/24 14:39:22 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_wstrto_nstr(wchar_t *w_str, int nbr_bytes)
{
	int			len;
	int			pos;
	int			tmp;
	char		*buff;
	int			max_len;

	len = 0;
	pos = 0;
	buff = NULL;
	if (w_str)
	{
		max_len = nbr_bytes ? nbr_bytes : 4 * ft_wstrlen(w_str);
		buff = ft_memalloc(max_len + 1);
		ft_bzero(buff, max_len + 1);
		while (w_str[pos])
		{
			tmp = ft_wcharto_str(&buff, len, w_str[pos]);
			if (tmp + len > max_len)
				break ;
			len += tmp;
			pos++;
		}
		ft_bzero(&buff[len], max_len - len);
	}
	return (buff);
}
