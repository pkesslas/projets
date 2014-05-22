/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 14:37:42 by pkesslas          #+#    #+#             */
/*   Updated: 2014/01/19 17:19:30 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int				ft_abs(int i)
{
	if (i < 0)
		return (i * -1);
	return (i);
}

int				main()
{
	t_data		e;

	e.w = 1000;
	e.h = 620;
	e.dirx = -1;
	e.diry = 0;
	e.planex = 0;
	e.planey = 0.66;
	e.albert = 0;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, e.w, e.h, "WOLF 3D");
	e.img.img = mlx_new_image(e.mlx, e.w, e.h);
	e.img.data = mlx_get_data_addr(e.img.img, &e.img.bpp,
									&e.img.size_l, &e.img.endian);
	mlx_hook(e.win, 1, (1L << 0), &ft_key_hook, &e);
	ft_init_map_1(&e);
	ft_print_wall(&e);
	e.indice = mlx_hook(e.win, 2, 2, ft_key_hook, &e);
	e.indice = mlx_hook(e.win, 3, 3, ft_key_hook, &e);
	e.indice = mlx_key_hook(e.win, &ft_key_hook, &e);
	e.indice = mlx_expose_hook(e.win, &ft_expose_hook, &e);
	e.indice = mlx_loop(e.mlx);
	return (0);
}
