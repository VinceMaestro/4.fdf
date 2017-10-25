/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:00:24 by vpetit            #+#    #+#             */
/*   Updated: 2017/10/25 16:02:42 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

#include <stdio.h>

int		ft_key_hook(int keycode, void *param)
{
	printf("key event %d\n", keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}
