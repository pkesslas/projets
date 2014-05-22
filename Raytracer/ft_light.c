/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/26 19:04:46 by pkesslas          #+#    #+#             */
/*   Updated: 2014/03/26 10:14:45 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

void			ft_calc_reflected_ray(t_ba *ba, double normal[3], t_obj *obj)
{
	double	vlong;

	ba->reflected[X] = 2 * (scalar(normal, obj->vlight)) * normal[X]
		- obj->vlight[X];
	ba->reflected[Y] = 2 * (scalar(normal, obj->vlight)) * normal[Y]
		- obj->vlight[Y];
	ba->reflected[Z] = 2 * (scalar(normal, obj->vlight)) * normal[Z]
		- obj->vlight[Z];
	vlong = sqrt(ft_sqrt(ba->reflected[X]) + ft_sqrt(ba->reflected[Y])
		+ ft_sqrt(ba->reflected[Z]));
	ba->reflected[X] = ba->reflected[X] / vlong;
	ba->reflected[Y] = ba->reflected[Y] / vlong;
	ba->reflected[Z] = ba->reflected[Z] / vlong;
}

void			ft_phong(double indice[2], int color[3], t_ba *ba, t_obj *obj)
{
	if (indice[0] >= 0)
	{
		ba->ambcol[0] = color[0] * obj->coef[0];
		ba->ambcol[1] = color[1] * obj->coef[0];
		ba->ambcol[2] = color[2] * obj->coef[0];
		ba->tmpcol[0] += color[0] * indice[0] * obj->coef[1];
		ba->tmpcol[1] += color[1] * indice[0] * obj->coef[1];
		ba->tmpcol[2] += color[2] * indice[0] * obj->coef[1];
		if (indice[1] >= 0)
		{
			ba->tmpcol[0] += ba->tmplight[0]
				* pow(indice[1], ba->actbrg) * obj->coef[2];
			ba->tmpcol[1] += ba->tmplight[1]
				* pow(indice[1], ba->actbrg) * obj->coef[2];
			ba->tmpcol[2] += ba->tmplight[2]
				* pow(indice[1], ba->actbrg) * obj->coef[2];
		}
	}
	else if (ba->islight == 0)
	{
		ba->tmpcol[0] = 0x00;
		ba->tmpcol[1] = 0x00;
		ba->tmpcol[2] = 0x00;
	}
}

void			ft_save_light_color(t_ba *ba, t_obj *obj)
{
	ba->tmplight[0] = obj->col[0];
	ba->tmplight[1] = obj->col[1];
	ba->tmplight[2] = obj->col[2];
}

void			ft_calc_light(double normal[3], int color[3],
								t_ba *ba, t_obj *obj)
{
	double		indice[2];
	double		vlong[2];
	int			tmp;

	tmp = obj->pos;
	while (obj->pos != ba->save_pos)
		obj = obj->next;
	ba->actbrg = obj->bright;
	ft_save_light_color(ba, obj);
	ft_calc_reflected_ray(ba, normal, obj);
	indice[0] = scalar(normal, obj->vlight);
	vlong[0] = sqrt(ft_sqrt(normal[X]) + ft_sqrt(normal[Y])
					+ ft_sqrt(normal[Z]));
	vlong[1] = sqrt(ft_sqrt(obj->vlight[X]) + ft_sqrt(obj->vlight[Y])
					+ ft_sqrt(obj->vlight[Z]));
	indice[0] /= -1 * (vlong[0] * vlong[1]);
	indice[1] = scalar(ba->reflected, obj->vlight);
	vlong[0] = sqrt(ft_sqrt(ba->reflected[X]) + ft_sqrt(ba->reflected[Y])
					+ ft_sqrt(ba->reflected[Z]));
	vlong[1] = sqrt(ft_sqrt(obj->vlight[X]) + ft_sqrt(obj->vlight[Y])
					+ ft_sqrt(obj->vlight[Z]));
	indice[1] /= vlong[0] * vlong[1];
	while (obj->pos != tmp)
		obj = obj->next;
	ft_phong(indice, color, ba, obj);
}
