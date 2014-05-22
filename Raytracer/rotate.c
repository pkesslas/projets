/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awybiera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 16:19:39 by awybiera          #+#    #+#             */
/*   Updated: 2014/03/25 13:53:19 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

void	rotate(t_ba *ba, t_obj *obj, double ray[3], double cam[3])
{
	ray[X] = ba->cam->ray[X];
	ray[Y] = ba->cam->ray[Y];
	ray[Z] = ba->cam->ray[Z];
	cam[X] = ba->cam->pos[X] - obj->coo[X];
	cam[Y] = ba->cam->pos[Y] - obj->coo[Y];
	cam[Z] = ba->cam->pos[Z] - obj->coo[Z];
	if (obj->coo2[X] != 0)
	{
		xrotate(ray, obj->coo2[X]);
		xrotate(cam, obj->coo2[X]);
	}
	if (obj->coo2[Y] != 0)
	{
		yrotate(ray, obj->coo2[Y]);
		yrotate(cam, obj->coo2[Y]);
	}
	if (obj->coo2[Z] != 0)
	{
		zrotate(ray, obj->coo2[Z]);
		zrotate(cam, obj->coo2[Z]);
	}
}

void	xrotate(double ray[3], double ang)
{
	double	tmp1;
	double	tmp2;

	tmp1 = ray[1];
	tmp2 = ray[2];
	ray[1] = (tmp1 * cos(ang * RAD)) - (sin(ang * RAD) * tmp2);
	ray[2] = (tmp1 * sin(ang * RAD)) + (cos(ang * RAD) * tmp2);
}

void	yrotate(double ray[3], double ang)
{
	double	tmp1;
	double	tmp2;

	tmp1 = ray[0];
	tmp2 = ray[2];
	ray[0] = (tmp1 * cos(ang * RAD)) + (sin(ang * RAD) * tmp2);
	ray[2] = (tmp1 * -sin(ang * RAD)) + (cos(ang * RAD) * tmp2);
}

void	zrotate(double ray[3], double ang)
{
	double	tmp1;
	double	tmp2;

	tmp1 = ray[0];
	tmp2 = ray[1];
	ray[0] = (tmp1 * cos(ang * RAD)) - (sin(ang * RAD) * tmp2);
	ray[1] = (tmp1 * sin(ang * RAD)) + (cos(ang * RAD) * tmp2);
}
