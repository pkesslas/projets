/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pla.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavanan <glavanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/16 14:31:42 by glavanan          #+#    #+#             */
/*   Updated: 2014/03/26 10:41:31 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

void		ft_cal_reflect_pl(t_ba *ba, t_obj *obj, double pos[3])
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
	normal[0] = -obj->coo[X];
	normal[1] = -obj->coo[Y];
	normal[2] = -obj->coo[Z];
	norm = sqrt(ft_sqrt(normal[0]) + ft_sqrt(normal[1]) + ft_sqrt(normal[2]));
	normal[0] = normal[0] / norm;
	normal[1] = normal[1] / norm;
	normal[2] = normal[2] / norm;
	secray[X] = -2 * normal[X] * scalar(ray, normal) + ray[X];
	secray[Y] = -2 * normal[Y] * scalar(ray, normal) + ray[Y];
	secray[Z] = -2 * normal[Z] * scalar(ray, normal) + ray[Z];
	ft_cal_reflect(ba, obj, pos, secray);
}

void		ft_cal_lum_pl(t_ba *ba, t_obj *obj)
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
	ve2[0] = -obj->coo[X];
	ve2[1] = -obj->coo[Y];
	ve2[Z] = -obj->coo[Z];
	normalize(ve2);
	if (obj->chkr > 0 && ft_color_plane(ba) == 1)
		ft_calc_light(ve2, obj->col, ba, obj);
	else if (obj->chkr > 0 && ft_color_plane(ba) == 0)
		ft_calc_light(ve2, obj->col2, ba, obj);
	else
		ft_calc_light(ve2, obj->col, ba, obj);
}

double		ft_put_pl(t_ba *ba, t_obj *obj)
{
	double		tmp[3];
	double		ray[3];
	double		cam[3];

	rotate(ba, obj, ray, cam);
	tmp[0] = obj->coo[X] * cam[X] + cam[Y] * obj->coo[Y] + obj->coo[Z] * cam[Z];
	tmp[1] = obj->coo[X] * ray[X] + ray[Y] * obj->coo[Y] + obj->coo[Z] * ray[Z];
	tmp[2] = -(obj->ray + tmp[0] / tmp[1]);
	return (tmp[2]);
}
