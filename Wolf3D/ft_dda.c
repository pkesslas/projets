/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 13:32:31 by pkesslas          #+#    #+#             */
/*   Updated: 2014/01/12 16:13:08 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		ft_init_dda(t_data *e)
{
	e->mapx = e->r_posx;
	e->mapy = e->r_posy;
	e->d_distx = sqrt(1 + (e->r_diry * e->r_diry) / (e->r_dirx * e->r_dirx));
	e->d_disty = sqrt(1 + (e->r_dirx * e->r_dirx) / (e->r_diry * e->r_diry));
	e->hit = 0;
}

void		ft_dda(t_data *e)
{
	while (e->hit == 0)
	{
		if (e->s_distx < e->s_disty)
		{
			e->s_distx += e->d_distx;
			e->mapx += e->stepx;
			e->side = 0;
		}
		else
		{
			e->s_disty += e->d_disty;
			e->mapy += e->stepy;
			e->side = 1;
		}
		if (e->map_1[e->mapx][e->mapy] > 0)
			e->hit = 1;
	}
}
