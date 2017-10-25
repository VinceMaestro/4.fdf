/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:03:19 by vpetit            #+#    #+#             */
/*   Updated: 2017/10/25 18:05:18 by vpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FDF_H
# define FDF_H

# define K_ESC	53
// # define K_ESC	53

# include "mlx.h"
# include "libft/libft.h"
# include "get_next_line.h"

void		fdf(int open_fd);
int			ft_key_hook(int keycode, void *param);
int			ft_expose_hook(int keycode, void *param);
int			ft_mouse_hook(int keycode, void *param);

// typedef struct s_env	t_env;
// typedef struct s_map	t_map;

// struct s_env
// {
// 	void		*mlx;
// 	void		*win;
// 	t_map		*map;
// };
//
// struct s_map
// {
// 	int			x;
// 	int			y;
// 	int			z;
// 	map[x][y]
// }

#endif
