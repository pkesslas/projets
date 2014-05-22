/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sph.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavanan <glavanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 11:50:57 by glavanan          #+#    #+#             */
/*   Updated: 2014/03/26 10:42:39 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

void		ft_cal_reflect_sp(t_ba *ba, t_obj *obj, double pos[3])
{
	double		ray[3];
	double		normal[3];
	double		secray[3];
	double		norm;

	norm = sqrt(ft_sqrt(ba->cam->ray[X]) + ft_sqrt(ba->cam->ray[Y])
			+ ft_sqrt(ba->cam->ray[Z]));
	ray[X] = ba->cam->ray[X] / norm;
	ray[Y] = ba->cam->ray[Y] / norm;
	ray[Z] = ba->cam->ray[Z] / norm;
	normal[0] = pos[0] - obj->coo[X];
	normal[1] = pos[1] - obj->coo[Y];
	normal[2] = pos[2] - obj->coo[Z];
	norm = sqrt(ft_sqrt(normal[0]) + ft_sqrt(normal[1]) + ft_sqrt(normal[2]));
	normal[0] = normal[0] / norm;
	normal[1] = normal[1] / norm;
	normal[2] = normal[2] / norm;
	secray[X] = -2 * normal[X] * scalar(ray, normal) + ray[X];
	secray[Y] = -2 * normal[Y] * scalar(ray, normal) + ray[Y];
	secray[Z] = -2 * normal[Z] * scalar(ray, normal) + ray[Z];
	ft_cal_reflect(ba, obj, pos, secray);
}

double		ft_put_sp(t_ba *ba, t_obj *obj)
{
	double	tmp[5];
	double	y[3];

	tmp[0] = ((ba->cam->ray[X] * ba->cam->ray[X]) + (ba->cam->ray[Y]
			* ba->cam->ray[Y]) + (ba->cam->ray[Z] * ba->cam->ray[Z]));
	tmp[1] = 2 * (((ba->cam->pos[X] - obj->coo[X]) * ba->cam->ray[X])
			+ ((ba->cam->pos[Y] - obj->coo[Y]) * ba->cam->ray[Y])
			+ ((ba->cam->pos[Z] - obj->coo[Z]) * ba->cam->ray[Z]));
	tmp[2] = (((ba->cam->pos[X] - obj->coo[X])
		* (ba->cam->pos[X] - obj->coo[X])) + ((ba->cam->pos[Y] - obj->coo[Y])
		* (ba->cam->pos[Y] - obj->coo[Y])) + ((ba->cam->pos[Z] - obj->coo[Z])
		* (ba->cam->pos[Z] - obj->coo[Z]))) - ft_sqrt(obj->ray);
	tmp[3] = tmp[1] * tmp[1] - (4 * tmp[0] * tmp[2]);
	tmp[4] = (-tmp[1] - sqrt(tmp[3])) / (2 * tmp[0]);
	y[0] = (obj->coo[Y] + obj->ray - obj->limite[0]);
	y[1] = (obj->coo[Y] - obj->ray + obj->limite[1]);
	y[2] = (tmp[4] * ba->cam->ray[Y]) + ba->cam->pos[Y];
	if (y[2] < y[1] || y[2] > y[0])
		return (0);
	return (tmp[4]);
}

void		ft_cal_lum_sp(t_ba *ba, t_obj *obj)
{
	double		pos[3];
	double		ve2[3];

	ba->save_pos = obj->pos;
	pos[0] = ba->cam->pos[X] + (ba->cam->ray[X] * ba->detmax);
	pos[1] = ba->cam->pos[Y] + (ba->cam->ray[Y] * ba->detmax);
	pos[2] = ba->cam->pos[Z] + (ba->cam->ray[Z] * ba->detmax);
	obj->vlight[X] = pos[X] - obj->coo[X];
	obj->vlight[Y] = pos[Y] - obj->coo[Y];
	obj->vlight[Z] = pos[Z] - obj->coo[Z];
	normalize(obj->vlight);
	while (obj->pos != ba->nu)
		obj = obj->next;
	ve2[0] = pos[0] - obj->coo[X];
	ve2[1] = pos[1] - obj->coo[Y];
	ve2[2] = pos[2] - obj->coo[Z];
	normalize(ve2);
	if (obj->text >= 1 && obj->text <= 3)
		ft_init_texture(ba, obj, ve2);
	else if (obj->perl > 10)
		ft_init_perlin(ba, obj);
	ft_calc_light(ve2, obj->col, ba, obj);
	if ((obj->perl > 10 || (obj->text >= 1 && obj->text <= 3)))
		ft_reset_obj_col(ba, obj);
}
