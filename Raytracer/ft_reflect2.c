/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reflect2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/25 10:44:37 by pkesslas          #+#    #+#             */
/*   Updated: 2014/03/25 17:40:32 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdlib.h>

void	ft_switchval_init(t_ba *cal, t_ba *ref, t_ba *ba)
{
	cal->cam->pos[0] = ref->cam->pos[0];
	cal->cam->pos[1] = ref->cam->pos[1];
	cal->cam->pos[2] = ref->cam->pos[2];
	cal->cam->ray[0] = ref->cam->ray[0];
	cal->cam->ray[1] = ref->cam->ray[1];
	cal->cam->ray[2] = ref->cam->ray[2];
	cal->ambcol[0] = ba->ambcol[0];
	cal->ambcol[1] = ba->ambcol[1];
	cal->ambcol[2] = ba->ambcol[2];
	cal->calinter[2] = &ft_put_sp;
	cal->calinter[3] = &ft_put_pl;
	cal->calinter[4] = &ft_put_cy;
	cal->calinter[5] = &ft_put_co;
	cal->calinter[6] = &ft_put_lp;
	cal->calinter[7] = &ft_put_cu;
	cal->callum[2] = &ft_cal_lum_sp;
	cal->callum[3] = &ft_cal_lum_pl;
	cal->callum[4] = &ft_cal_lum_cy;
	cal->callum[5] = &ft_cal_lum_co;
	cal->callum[6] = &ft_cal_lum_lp;
	cal->callum[7] = &ft_cal_lum_cu;
	cal->cal_ref[2] = &ft_cal_reflect_sp;
	cal->cal_ref[3] = &ft_cal_reflect_pl;
	cal->cal_ref[4] = &ft_cal_reflect_cy;
	cal->cal_ref[5] = &ft_cal_reflect_co;
}

void	ft_apply_reflected_color(t_ba *ba, t_obj *obj)
{
	while (obj->pos != ba->nu)
		obj = obj->next;
	ba->tmpcol[0] = ba->tmpcol[0] * (1 - obj->reflect);
	ba->tmpcol[1] = ba->tmpcol[1] * (1 - obj->reflect);
	ba->tmpcol[2] = ba->tmpcol[2] * (1 - obj->reflect);
}

void	ft_init_ref(t_ba *ref, double pos[3], double secray[3], t_obj *obj)
{
	ref->save_pos = obj->pos;
	ref->nu = -1;
	ref->detmax = -1;
	ref->cam = (t_cam *)malloc(sizeof(t_cam));
	ref->cam->pos[X] = pos[X];
	ref->cam->pos[Y] = pos[Y];
	ref->cam->pos[Z] = pos[Z];
	ref->cam->ray[X] = secray[X];
	ref->cam->ray[Y] = secray[Y];
	ref->cam->ray[Z] = secray[Z];
}
