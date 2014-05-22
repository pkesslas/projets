/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 12:12:49 by pkesslas          #+#    #+#             */
/*   Updated: 2014/01/19 14:32:17 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		ft_move(t_data *e, int keycode)
{
	if (keycode == 65362)
	{
		e->albert = 1;
		if (e->map_1[(int)(e->posx + e->dirx * 0.05)][(int)e->posy] <= 0)
			e->posx += e->dirx * 0.05;
		if( e->map_1[(int)e->posx][(int)(e->posy + e->diry * 0.05)] <= 0)
			e->posy += e->diry * 0.05;
		ft_print_wall(e);
	}
	if (keycode == 65364)
	{
		e->albert = 1;
		if (e->map_1[(int)(e->posx - e->dirx * 0.05)][(int)e->posy] <= 0)
			e->posx -= e->dirx * 0.05;
		if (e->map_1[(int)e->posx][(int)(e->posy - e->diry * 0.05)] <= 0)
			e->posy -= e->diry * 0.05;
		ft_print_wall(e);
	}
}

void		ft_rotate2(t_data *e, int keycode)
{
	double	olddirx;
	double	oldplanex;

	if (keycode == 65361)
	{
		e->albert = 1;
		olddirx = e->dirx;
		e->dirx = e->dirx * cos(0.05) - e->diry * sin(0.05);
		e->diry = olddirx * sin(0.05) + e->diry * cos(0.05);
		oldplanex = e->planex;
		e->planex = e->planex * cos(0.05) - e->planey * sin(0.05);
		e->planey = oldplanex * sin(0.05) + e->planey * cos(0.05);
		ft_print_wall(e);
	}
}

void		ft_rotate(t_data *e, int keycode)
{
	double	olddirx;
	double	oldplanex;

	if (keycode == 65363)
	{
		e->albert = 1;
		olddirx = e->dirx;
		e->dirx = e->dirx * cos(-0.05) - e->diry * sin(-0.05);
		e->diry = olddirx * sin(-0.05) + e->diry * cos(-0.05);
		oldplanex = e->planex;
		e->planex = e->planex * cos(-0.05) - e->planey * sin(-0.05);
		e->planey = oldplanex * sin(-0.05) + e->planey * cos(-0.05);
		ft_print_wall(e);
	}
	ft_rotate2(e, keycode);
}

int			ft_key_hook(int keycode, t_data *e)
{
	if (keycode == 65307)
		exit (0);
	if (keycode == 32)
	{
		e->albert = 1;
		if (e->map_1[(int)(e->posx + e->dirx)][(int)e->posy] == 7)
		{
			e->map_1[(int)(e->posx + e->dirx)][(int)e->posy] = -1;
			ft_print_wall(e);
		}
		else if (e->map_1[(int)(e->posx + e->dirx)][(int)e->posy] == -1)
		{
			e->map_1[(int)(e->posx + e->dirx)][(int)e->posy] = 7;
			ft_print_wall(e);
		}
	}
	ft_move(e, keycode);
	ft_rotate(e, keycode);
	e->indice = mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
	return (0);
}

int			ft_expose_hook(t_data *e)
{
	e->indice = mlx_put_image_to_window(e->mlx, e->win, e->img.img, 0, 0);
	return (0);
}
