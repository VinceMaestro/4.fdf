/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arr_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 17:40:18 by vpetit            #+#    #+#             */
/*   Updated: 2017/10/27 17:40:19 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_get_arr_len(char **args)
{
	int		len;

	len = 0;
	if (!args)
		return (0);
	while (args[len])
		len++;
	return (len);
}
