/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavanan <glavanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 17:20:59 by glavanan          #+#    #+#             */
/*   Updated: 2014/03/26 10:08:33 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <mlx.h>

int				ft_put_p(t_ba *e, int x, int y, int color[3])
{
	int			i;

	i = y * WD_H * 4 + x * 4;
	e->pix[i++] = color[0];
	e->pix[i++] = color[1];
	e->pix[i++] = color[2];
	return (0);
}

void			ft_count_spot(t_ba *ba, t_obj *obj)
{
	int		spot;

	spot = 0;
	obj = obj->next;
	while (obj->pos != 0)
	{
		if (obj->type == 1)
			spot++;
		obj = obj->next;
	}
	ba->nbr_light = spot;
}

void			ft_put_color(t_ba *ba, t_obj *obj)
{
	int		i[2];

	i[0] = 0;
	ba->islight = 0;
	obj = obj->next;
	ft_reset_col(ba);
	while (obj->pos != 0)
	{
		if (obj->type == 1 && ba->detmax > 0.0001)
		{
			ba->callum[ba->type](ba, obj);
			ba->islight++;
		}
		i[0]++;
		obj = obj->next;
	}
	if (ba->islight != 0)
		ft_do_the_light(ba, obj);
	ft_put_in_int(ba);
}

void			ft_put_obj(t_ba *ba, t_obj *obj, int x, int y)
{
	ft_cal_ray(ba, x, y);
	obj = obj->next;
	ba->detmax = 0;
	ba->nu = 0;
	while (obj->pos != 0)
	{
		if (obj->type > 1)
		{
			obj->det = ba->calinter[obj->type](ba, obj);
			if (obj->det > 0.001
				&& !(obj->det > ba->detmax && ba->detmax >= 0.001))
			{
				ba->nu = obj->pos;
				ba->type = obj->type;
				ba->detmax = obj->det;
			}
		}
		obj = obj->next;
	}
	ft_put_color(ba, obj);
}

void			ft_draw(t_ba *ba, t_obj *obj)
{
	ft_ini(ba, obj);
	ft_count_spot(ba, obj);
	ft_init_textures(ba);
	ba->bi = 0;
	ba->x = 0;
	while (ba->x < (WD_H))
	{
		ba->y = 0;
		while (ba->y < (WD_W))
		{
			ft_put_obj(ba, obj, ba->x, ba->y);
			ba->y++;
		}
		ba->x++;
	}
	ft_antialiasing(ba);
	writefile(ba->pix);
}
