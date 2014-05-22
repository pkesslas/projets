/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavanan <glavanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/05 16:27:17 by glavanan          #+#    #+#             */
/*   Updated: 2014/03/27 18:17:24 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		ft_ini_cub(t_ba *ba, t_obj *obj, double cam[3], double ray[3])
{
	ba->cam->pos[X] = cam[X];
	ba->cam->pos[Y] = cam[Y];
	ba->cam->pos[Z] = cam[Z];
	ba->cam->ray[X] = ray[X];
	ba->cam->ray[Y] = ray[Y];
	ba->cam->ray[Z] = ray[Z];
	obj->coo2[X] = 0;
	obj->coo2[Y] = 0;
	obj->coo2[Z] = 0;
	obj->coo[X] = 0;
	obj->coo[Y] = 0;
	obj->coo[Z] = 0;
}

void		ft_lum_cu(t_ba *ba, t_obj *obj)
{
	ft_cal_lum_lp(ba, obj);
	while (obj->pos != ba->nu)
		obj = obj->next;
	obj->coo[Y] += obj->ve2[X];
	while (obj->pos != ba->lightt)
		obj = obj->next;
	ft_cal_lum_lp(ba, obj);
	while (obj->pos != ba->nu)
		obj = obj->next;
	obj->coo[Y] -= obj->ve2[X];
	obj->coo2[Z] -= 90;
	obj->coo[X] += obj->ve[Z];
	while (obj->pos != ba->lightt)
		obj = obj->next;
	ft_cal_lum_lp(ba, obj);
	while (obj->pos != ba->nu)
		obj = obj->next;
	ft_lum_cu2(ba, obj);
}

void		ft_lum_cu2(t_ba *ba, t_obj *obj)
{
	obj->coo2[Z] += 90;
	obj->coo[X] -= obj->ve[Z];
	obj->coo2[Z] -= 90;
	while (obj->pos != ba->lightt)
		obj = obj->next;
	ft_cal_lum_lp(ba, obj);
	while (obj->pos != ba->nu)
		obj = obj->next;
	obj->coo2[Z] += 90;
	obj->coo2[X] += 90;
	obj->coo[Z] += obj->ve2[X];
	while (obj->pos != ba->lightt)
		obj = obj->next;
	ft_cal_lum_lp(ba, obj);
	while (obj->pos != ba->nu)
		obj = obj->next;
	obj->coo[Z] -= obj->ve2[X];
	while (obj->pos != ba->lightt)
		obj = obj->next;
	ft_cal_lum_lp(ba, obj);
}

void		ft_cal_lum_cu(t_ba *ba, t_obj *obj)
{
	int		tmp[6];
	double	tmp2[12];

	ba->lightt = obj->pos;
	while (obj->pos != ba->nu)
		obj = obj->next;
	ft_save(ba, obj, tmp, tmp2);
	while (obj->pos != ba->lightt)
		obj = obj->next;
	ft_lum_cu(ba, obj);
	while (obj->pos != ba->nu)
		obj = obj->next;
	ft_replace1(ba, obj, tmp, tmp2);
}
