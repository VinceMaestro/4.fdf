/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharto_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 14:38:34 by vpetit            #+#    #+#             */
/*   Updated: 2017/10/24 14:38:35 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_conv_one_byte(char **buff, int pos, wchar_t w_c)
{
	(*buff)[pos + 0] = w_c & 0x7F;
	return (1);
}

static int		ft_conv_two_byte(char **buff, int pos, wchar_t w_c)
{
	(*buff)[pos + 0] = ((w_c & 0x7c0) >> 6) | 0xc0;
	(*buff)[pos + 1] = ((w_c & 0x3f) | 0x80);
	return (2);
}

static int		ft_conv_three_byte(char **buff, int pos, wchar_t w_c)
{
	(*buff)[pos + 0] = (((w_c & 0xf000) >> 12) | 0xe0);
	(*buff)[pos + 1] = (((w_c & 0xfc0) >> 6) | 0x80);
	(*buff)[pos + 2] = ((w_c & 0x3f) | 0x80);
	return (3);
}

static int		ft_conv_four_byte(char **buff, int pos, wchar_t w_c)
{
	(*buff)[pos + 0] = (((w_c & 0x1c0000) >> 18) | 0xf0);
	(*buff)[pos + 1] = (((w_c & 0x3f000) >> 12) | 0x80);
	(*buff)[pos + 2] = (((w_c & 0xfc0) >> 6) | 0x80);
	(*buff)[pos + 3] = ((w_c & 0x3f) | 0x80);
	return (4);
}

int				ft_wcharto_str(char **buff, int pos, wchar_t w_c)
{
	if (w_c < 0x80)
		return (ft_conv_one_byte(buff, pos, w_c));
	else if (w_c < 0x800)
		return (ft_conv_two_byte(buff, pos, w_c));
	else if (w_c < 0x10000)
		return (ft_conv_three_byte(buff, pos, w_c));
	else if (w_c < 0x110000)
		return (ft_conv_four_byte(buff, pos, w_c));
	return (0);
}
