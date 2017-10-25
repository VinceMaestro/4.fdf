/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expose_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:01:38 by vpetit            #+#    #+#             */
/*   Updated: 2017/10/25 16:02:46 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

int		ft_expose_hook(int keycode, void *param)
{
	// if (keycode == 53)
	// 	exit(1);
	printf("key event %d\n", keycode);
	return (0);
}
