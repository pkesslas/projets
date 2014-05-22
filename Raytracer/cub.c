/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavanan <glavanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/03 14:25:48 by glavanan          #+#    #+#             */
/*   Updated: 2014/03/27 22:29:22 by rbobillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double		ft_replace(t_ba *ba, t_obj *obj, double det[12], int tmp[3])
{
	int		i;
	double	ret;

	ret = 0;
	i = 0;
	while (i < 6)
	{
		if (obj->detcu[i] > 0.001 && !(obj->detcu[i] > ret && ret >= 0.001))
			ret = obj->detcu[i];
		i++;
	}
	obj->coo2[X] -= 90;
	obj->coo2[X] = tmp[0];
	obj->coo2[Y] = tmp[1];
	obj->coo2[Z] = tmp[2];
	obj->coo[X] = tmp[3];
	obj->coo[Y] = tmp[4];
	obj->coo[Z] = tmp[5];
	ba->cam->pos[X] = det[6];
	ba->cam->pos[Y] = det[7];
	ba->cam->pos[Z] = det[8];
	ba->cam->ray[X] = det[9];
	ba->cam->ray[Y] = det[10];
	ba->cam->ray[Z] = det[11];
	return (ret);
}

double		ft_replace1(t_ba *ba, t_obj *obj, int tmp[6], double tmp2[6])
{
	double		ret;

	ret = 0.0;
	obj->coo2[X] = tmp[0];
	obj->coo2[Y] = tmp[1];
	obj->coo2[Z] = tmp[2];
	obj->coo[X] = tmp[3];
	obj->coo[Y] = tmp[4];
	obj->coo[Z] = tmp[5];
	ba->cam->pos[X] = tmp2[0];
	ba->cam->pos[Y] = tmp2[1];
	ba->cam->pos[Z] = tmp2[2];
	ba->cam->ray[X] = tmp2[3];
	ba->cam->ray[Y] = tmp2[4];
	ba->cam->ray[Z] = tmp2[5];
	return (ret);
}

void		ft_save(t_ba *ba, t_obj *obj, int tmp[6], double tmp2[12])
{
	tmp[0] = obj->coo2[X];
	tmp[1] = obj->coo2[Y];
	tmp[2] = obj->coo2[Z];
	tmp[3] = obj->coo[X];
	tmp[4] = obj->coo[Y];
	tmp[5] = obj->coo[Z];
	tmp2[6] = ba->cam->pos[X];
	tmp2[7] = ba->cam->pos[Y];
	tmp2[8] = ba->cam->pos[Z];
	tmp2[9] = ba->cam->ray[X];
	tmp2[10] = ba->cam->ray[Y];
	tmp2[11] = ba->cam->ray[Z];
}

double		ft_put_cu(t_ba *ba, t_obj *obj)
{
	double		det[12];
	double		ray[3];
	double		cam[3];
	int			tmp[6];

	ft_save(ba, obj, tmp, det);
	rotate(ba, obj, ray, cam);
	ft_ini_cub(ba, obj, cam, ray);
	ft_put_cu2(ba, obj);
	return (ft_replace(ba, obj, det, tmp));
}

void		ft_put_cu2(t_ba *ba, t_obj *obj)
{
	obj->detcu[5] = ft_put_lp(ba, obj);
	obj->coo[Y] += obj->ve2[X];
	obj->detcu[0] = ft_put_lp(ba, obj);
	obj->coo[Y] -= obj->ve2[X];
	obj->coo2[Z] -= 90;
	obj->coo[X] += obj->ve[Z];
	obj->detcu[1] = ft_put_lp(ba, obj);
	obj->coo2[Z] += 90;
	obj->coo[X] -= obj->ve[Z];
	obj->coo2[Z] -= 90;
	obj->detcu[2] = ft_put_lp(ba, obj);
	obj->coo2[Z] += 90;
	obj->coo2[X] += 90;
	obj->coo[Z] += obj->ve2[X];
	obj->detcu[3] = ft_put_lp(ba, obj);
	obj->coo[Z] -= obj->ve2[X];
	obj->detcu[4] = ft_put_lp(ba, obj);
}
