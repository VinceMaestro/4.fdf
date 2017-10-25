/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 14:02:16 by vpetit            #+#    #+#             */
/*   Updated: 2017/10/24 14:03:12 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

void		*ft_malloc(size_t size, const char *func, const char *err)
{
	void		*new;

	new = NULL;
	if (!(new = malloc(size)))
	{
		write(2, func, ft_strlen(func));
		ft_error(err);
	}
	return (new);
}
