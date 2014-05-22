/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavanan <glavanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 11:27:33 by glavanan          #+#    #+#             */
/*   Updated: 2014/03/26 09:51:08 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

void		ft_cal_reflect_cy(t_ba *ba, t_obj *obj, double pos[3])
{
	double	ray[3];
	double	normal[3];
	double	secray[3];
	double	norm;

	norm = sqrt(ft_sqrt(ba->cam->ray[X]) + ft_sqrt(ba->cam->ray[Y])
		+ ft_sqrt(ba->cam->ray[Z]));
	ray[X] = ba->cam->ray[X] / norm;
	ray[Y] = ba->cam->ray[Y] / norm;
	ray[Z] = ba->cam->ray[Z] / norm;
	xrotate(pos, obj->coo2[X]);
	yrotate(pos, obj->coo2[Y]);
	zrotate(pos, obj->coo2[Z]);
	normal[0] = pos[0] - obj->coo[X];
	normal[1] = 0;
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

double		ft_put_cy(t_ba *ba, t_obj *obj)
{
	double	tmp[9];
	double	ray[3];
	double	cam[3];
	double	y[3];

	rotate(ba, obj, ray, cam);
	tmp[0] = (ft_sqrt(ray[X]) + ft_sqrt(ray[Z]));
	tmp[1] = 2 * (ray[X] * (cam[X])
			+ (cam[Z]) * ray[Z]);
	tmp[2] = ft_sqrt(cam[X]) + ft_sqrt(cam[Z]) - ft_sqrt(obj->ray);
	tmp[3] = (-tmp[1] - sqrt(ft_sqrt(tmp[1]) - 4 * tmp[0] * tmp[2]))
		/ (2 * tmp[0]);
	y[0] = obj->coo[Y] - obj->limite[0];
	y[1] = obj->coo[Y] + obj->limite[1];
	y[2] = tmp[3] * ba->cam->ray[Y] + ba->cam->pos[Y];
	if (obj->limite[0] > 0 || obj->limite[1] > 0)
	{
		if (y[2] > y[1] || y[2] < y[0])
			return (0);
	}
	return (tmp[3]);
}

void		ft_cal_lum_cy(t_ba *ba, t_obj *obj)
{
	double	pos[3];
	double	ve2[3];

	ba->save_pos = obj->pos;
	pos[0] = ba->cam->pos[X] + (ba->cam->ray[X] * ba->detmax);
	pos[1] = ba->cam->pos[Y] + (ba->cam->ray[Y] * ba->detmax);
	pos[2] = ba->cam->pos[Z] + (ba->cam->ray[Z] * ba->detmax);
	obj->vlight[X] = obj->coo[X] - pos[0];
	obj->vlight[Y] = obj->coo[Y] - pos[1];
	obj->vlight[Z] = obj->coo[Z] - pos[2];
	normalize(obj->vlight);
	while (obj->pos != ba->nu)
		obj = obj->next;
	xrotate(pos, obj->coo2[X]);
	yrotate(pos, obj->coo2[Y]);
	zrotate(pos, obj->coo2[Z]);
	ve2[0] = obj->coo[X] - pos[0];
	ve2[1] = 0;
	ve2[2] = obj->coo[Z] - pos[2];
	normalize(ve2);
	if (obj->perl > 10)
		ft_init_perlin(ba, obj);
	ft_calc_light(ve2, obj->col, ba, obj);
	if (obj->perl > 10)
		ft_reset_obj_col(ba, obj);
}
