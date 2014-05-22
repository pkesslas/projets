/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 13:36:35 by pkesslas          #+#    #+#             */
/*   Updated: 2014/01/19 17:22:44 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		ft_init_vec(t_data *e)
{
	if (e->albert == 0)
	{
		e->posx = 12;
		e->posy = 14;
	}
}

void		ft_ray_pos(t_data *e, int x)
{
	e->cam = 2 * x / (double)e->w - 1;
	e->r_posx = e->posx;
	e->r_posy = e->posy;
	e->r_dirx = e->dirx + e->planex * e->cam;
	e->r_diry = e->diry + e->planey * e->cam;
}

void		ft_calc_dist(t_data *e)
{

	if (e->r_dirx < 0)
	{
		e->stepx = -1;
		e->s_distx = (e->r_posx - e->mapx) * e->d_distx;
	}
	else
	{
		e->stepx = 1;
		e->s_distx = (e->mapx + 1.0 - e->r_posx) * e->d_distx;
	}
	if (e->r_diry < 0)
	{
		e->stepy = -1;
		e->s_disty = (e->r_posy - e->mapy) * e->d_disty;
	}
	else
	{
		e->stepy = 1;
		e->s_disty = (e->mapy + 1.0 - e->r_posy) * e->d_disty;
	}
}

void		ft_correct_feye(t_data *e)
{
	if (e->side == 0)
		e->wdist = fabs((e->mapx - e->r_posx +
						 (1 - e->stepx) / 2) / e->r_dirx);
	else
		e->wdist = fabs((e->mapy - e->r_posy +
						 (1 - e->stepy) / 2) / e->r_diry);
}

void		ft_calc_hwall(t_data *e, int x)
{
	double	lineheight;
	double	sY;
	double	eY;
	double	color;

	lineheight = ft_abs(e->h / e->wdist);
	sY = -lineheight / 2 + e->h / 2;
	if (sY < 0)
		sY = 0;
	eY = lineheight / 2 + e->h / 2;
	if (eY >= e->h)
		eY = e->h - 1;
	color = (e->stepx == 1 ? 0x0000FF : (0x0000FF / 2));
	if (e->side == 1)
		color = (e->stepy == 1 ? 0xFDBFB7 : (0xFDBFB7 / 2));
	color = (e->map_1[e->mapx][e->mapy] == 7 ? (color + 0x0000FF) / 2 : color);
	e->x = x;
	ft_verline(e, sY, eY, color);
	ft_put_floor(e, eY, x);
	ft_put_sky(e, sY, x);
}
