/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reflect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavanan <glavanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 14:52:35 by glavanan          #+#    #+#             */
/*   Updated: 2014/03/26 10:15:14 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_cal_col_inter(t_ba *ba, t_ba *cal, t_obj *obj)
{
	cal->islight = 0;
	while (obj->pos != 1)
		obj = obj->next;
	ft_reset_col(cal);
	while (obj->pos != 0)
	{
		if (obj->type == 1 && cal->detmax > 0.0001)
		{
			ba->callum[cal->type](cal, obj);
			cal->islight++;
		}
		obj = obj->next;
	}
	if (cal->islight != 0)
	{
		if (cal->save_pos2 < 10)
			ft_reflect(cal, obj);
		ft_multi_spot(cal);
		ft_shadow(cal, obj);
	}
}

void	ft_switchval_cal(t_ba *cal, t_ba *ref, t_ba *ba)
{
	ft_switchval_init(cal, ref, ba);
	cal->x = ba->x;
	cal->y = ba->y;
	cal->mars = ba->mars;
	cal->eye = ba->eye;
	cal->doge = ba->doge;
	cal->save_pos2 = ba->save_pos2 + 1;
	cal->nu = ref->nu;
	cal->detmax = ref->detmax;
	cal->type = ref->type;
}

void	ft_reflec_color(t_ba *ba, t_ba *ref, t_obj *obj, t_ba *cal)
{
	cal->cam = (t_cam *)malloc(sizeof(t_cam));
	ft_switchval_cal(cal, ref, ba);
	if (ref->save_pos != ref->nu && ref->nu > 0)
	{
		while (obj->pos != ref->nu)
			obj = obj->next;
		ft_cal_col_inter(ba, cal, obj);
		while (obj->pos != ref->save_pos)
			obj = obj->next;
		if ((ba->tmpcol[0] = cal->tmpcol[0]
			* obj->reflect + ba->tmpcol[0] * (1 - obj->reflect)) > 255)
			ba->tmpcol[0] = 255;
		if ((ba->tmpcol[1] = cal->tmpcol[1]
			* obj->reflect + ba->tmpcol[1] * (1 - obj->reflect)) > 255)
			ba->tmpcol[1] = 255;
		if ((ba->tmpcol[2] = cal->tmpcol[2]
			* obj->reflect + ba->tmpcol[2] * (1 - obj->reflect)) > 255)
			ba->tmpcol[2] = 255;
	}
	else
		ft_apply_reflected_color(ba, obj);
	free(cal->cam);
}

void	ft_reflect(t_ba *ba, t_obj *obj)
{
	double		pos[3];

	if (ba->nu > 0)
	{
		while (obj->pos != ba->nu)
			obj = obj->next;
		pos[X] = ba->cam->pos[X] + (ba->cam->ray[X] * ba->detmax);
		pos[Y] = ba->cam->pos[Y] + (ba->cam->ray[Y] * ba->detmax);
		pos[Z] = ba->cam->pos[Z] + (ba->cam->ray[Z] * ba->detmax);
		if (obj->type > 1 && obj->type < 6)
			ba->cal_ref[obj->type](ba, obj, pos);
	}
}

void	ft_cal_reflect(t_ba *ba, t_obj *obj, double pos[3], double secray[3])
{
	t_ba	ref;
	double	tmp;
	t_ba	cal;

	tmp = 0;
	ref.nu = -1;
	ft_init_ref(&ref, pos, secray, obj);
	while (obj->pos != 1)
		obj = obj->next;
	while (obj->pos != 0)
	{
		if (obj->type > 1)
		{
			tmp = ba->calinter[obj->type](&ref, obj);
			if (tmp > 0.00001 && !(tmp > ref.detmax && ref.detmax >= 0.00001))
			{
				ref.nu = obj->pos;
				ref.type = obj->type;
				ref.detmax = tmp;
			}
		}
		obj = obj->next;
	}
	ft_reflec_color(ba, &ref, obj, &cal);
	free(ref.cam);
}
