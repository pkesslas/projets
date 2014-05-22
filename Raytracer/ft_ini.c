/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ini.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavanan <glavanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/24 17:31:37 by glavanan          #+#    #+#             */
/*   Updated: 2014/03/23 12:15:38 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdlib.h>

void	ft_cal_ray(t_ba *ba, int x, int y)
{
	ba->cam->ray[X] = (ba->cam->up[X] - ba->cam->pos[X]) + ba->cam->riv[X]
		* WV / WD_H * x - ba->cam->upv[X] * HV / WD_W * y;
	ba->cam->ray[Y] = (ba->cam->up[Y] - ba->cam->pos[Y]) + ba->cam->riv[Y]
		* WV / WD_H * x - ba->cam->upv[Y] * HV / WD_W * y;
	ba->cam->ray[Z] = (ba->cam->up[Z] - ba->cam->pos[Z]) + ba->cam->riv[Z]
		* WV / WD_H * x - ba->cam->upv[Z] * HV / WD_W * y;
}

void	ft_ini_next(t_ba *ba, t_obj *obj, double tmp[3])
{
	(void)obj;
	ba->cam->up[X] = ba->cam->pos[X] + ((DP * tmp[X]) + (HV / 2)
			* ba->cam->upv[X]) - ((WV / 2) * ba->cam->riv[X]);
	ba->cam->up[Y] = ba->cam->pos[Y] + ((DP * tmp[Y]) + (HV / 2)
			* ba->cam->upv[Y]) - ((WV / 2) * ba->cam->riv[Y]);
	ba->cam->up[Z] = ba->cam->pos[Z] + ((DP * tmp[Z]) + (HV / 2)
			* ba->cam->upv[Z]) - ((WV / 2) * ba->cam->riv[Z]);
}

void	ft_ini(t_ba *ba, t_obj *obj)
{
	double		tmp[3];
	double		tmp2[3];

	ba->cam = (t_cam *)malloc(sizeof(t_cam));
	ba->big_img = (int **)malloc(sizeof(ba->big_img) * (WD_H * WD_W));
	ba->cam->pos[X] = obj->coo[X];
	ba->cam->pos[Y] = obj->coo[Y];
	ba->cam->pos[Z] = obj->coo[Z];
	tmp[X] = ba->cam->pos[X] + obj->coo2[X];
	tmp[Y] = ba->cam->pos[Y] + obj->coo2[Y];
	tmp[Z] = ba->cam->pos[Z] + obj->coo2[Z];
	tmp2[X] = tmp[X] - ba->cam->pos[X];
	tmp2[Y] = tmp[Y] - ba->cam->pos[Y];
	tmp2[Z] = tmp[Z] - ba->cam->pos[Z];
	normalize(tmp2);
	ba->cam->upv[X] = 0;
	ba->cam->upv[Y] = tmp[Z];
	ba->cam->upv[Z] = -tmp[Y];
	normalize(ba->cam->upv);
	ba->cam->riv[X] = (tmp2[Y] * ba->cam->upv[Z]) - (ba->cam->upv[Y] * tmp2[Z]);
	ba->cam->riv[Y] = (tmp2[Z] * ba->cam->upv[X]) - (ba->cam->upv[Z] * tmp2[X]);
	ba->cam->riv[Z] = (tmp2[X] * ba->cam->upv[Y]) - (ba->cam->upv[X] * tmp2[Y]);
	normalize(ba->cam->riv);
	ft_ini_next(ba, obj, tmp2);
}
