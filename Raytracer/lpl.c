/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lpl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavanan <glavanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/02 10:45:48 by glavanan          #+#    #+#             */
/*   Updated: 2014/03/27 22:29:06 by rbobillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

void		ft_rotate_lum_lp(double pro[3], double pos[3],
								double ve2[3], t_obj *obj)
{
	pro[X] = 0;
	pro[Y] = 1;
	pro[Z] = 0;
	ft_rotate_pos_cyl(pro, obj);
	xrotate(pos, obj->coo2[X]);
	yrotate(pos, obj->coo2[Y]);
	zrotate(pos, obj->coo2[Z]);
	ve2[0] = -fabs((obj->coo[X] - pos[X]) * pro[X]);
	ve2[1] = -fabs((obj->coo[Y] - pos[Y]) * pro[Y]);
	ve2[2] = -fabs((obj->coo[Z] - pos[Z]) * pro[Z]);
}

void		ft_cal_lum_lp(t_ba *ba, t_obj *obj)
{
	double		pos[3];
	double		ve2[3];
	double		pro[3];

	ba->save_pos = obj->pos;
	pos[0] = ba->cam->pos[X] + (ba->cam->ray[X] * ba->detmax);
	pos[1] = ba->cam->pos[Y] + (ba->cam->ray[Y] * ba->detmax);
	pos[2] = ba->cam->pos[Z] + (ba->cam->ray[Z] * ba->detmax);
	obj->vlight[X] = obj->coo[X] - pos[X];
	obj->vlight[Y] = obj->coo[Y] - pos[Y];
	obj->vlight[Z] = obj->coo[Z] - pos[Z];
	normalize(obj->vlight);
	while (obj->pos != ba->nu)
		obj = obj->next;
	ft_rotate_lum_lp(pro, pos, ve2, obj);
	if (obj->type == 7)
	{
		ve2[0] = -ve2[0];
		ve2[1] = -ve2[1];
		ve2[2] = -ve2[2];
	}
	normalize(ve2);
	ft_calc_light(ve2, obj->col, ba, obj);
}

double		ft_put_lp(t_ba *ba, t_obj *obj)
{
	double		tmp[4];
	double		ray[3];
	double		cam[4];
	double		pos[3];

	rotate(ba, obj, ray, cam);
	tmp[2] = -1 * (cam[Y] / ray[Y]);
	pos[X] = cam[X] + (ray[X] * tmp[2]);
	pos[Y] = cam[Y] + (ray[Y] * tmp[2]);
	pos[Z] = cam[Z] + (ray[Z] * tmp[2]);
	tmp[0] = obj->ve[X] * pos[Z] - pos[X] * obj->ve[Z];
	tmp[1] = obj->ve2[Z] * obj->ve[X] - obj->ve[Z] * obj->ve2[X];
	tmp[3] = tmp[0] / tmp[1];
	tmp[0] = (pos[Z] - (tmp[3] * obj->ve2[Z])) / obj->ve[Z];
	if ((tmp[3] >= 0 && tmp[3] <= 1) && (tmp[0] <= 1 && tmp[0] >= 0))
		return (-1 * (cam[Y] / ray[Y]));
	else
		return (-1);
}
