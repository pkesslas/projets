/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shadow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 14:55:57 by pkesslas          #+#    #+#             */
/*   Updated: 2014/03/27 11:01:10 by glavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdlib.h>

void		ft_init_shad(t_ba *ba, t_ba *shad, t_obj *obj)
{
	double	pos[3];

	pos[X] = ba->cam->pos[X] + (ba->cam->ray[X] * ba->detmax);
	pos[Y] = ba->cam->pos[Y] + (ba->cam->ray[Y] * ba->detmax);
	pos[Z] = ba->cam->pos[Z] + (ba->cam->ray[Z] * ba->detmax);
	shad->cam = (t_cam *)malloc(sizeof(t_cam));
	shad->cam->ray[X] = pos[X] - obj->coo[X];
	shad->cam->ray[Y] = pos[Y] - obj->coo[Y];
	shad->cam->ray[Z] = pos[Z] - obj->coo[Z];
	shad->cam->pos[X] = obj->coo[X];
	shad->cam->pos[Y] = obj->coo[Y];
	shad->cam->pos[Z] = obj->coo[Z];
}

void		ft_multi_spot(t_ba *ba)
{
	if ((ba->tmpcol[0] = (ba->tmpcol[0] / ba->islight) + ba->ambcol[0]) > 255)
		ba->tmpcol[0] = 255;
	if ((ba->tmpcol[1] = (ba->tmpcol[1] / ba->islight) + ba->ambcol[1]) > 255)
		ba->tmpcol[1] = 255;
	if ((ba->tmpcol[2] = (ba->tmpcol[2] / ba->islight) + ba->ambcol[2]) > 255)
		ba->tmpcol[2] = 255;
}

int			ft_isshads(t_ba *ba, t_ba *shad, t_obj *obj)
{
	double	det;

	while (obj->pos != 0)
		obj = obj->next;
	obj = obj->next;
	while (obj->pos != 0)
	{
		if (obj->type > 1)
		{
			det = ba->calinter[obj->type](shad, obj);
			if (det > 0.0001 && det < 0.9999)
				return (1);
		}
		obj = obj->next;
	}
	return (0);
}

void		ft_set_shads(t_ba *ba, int nbr_shads)
{
	ba->tmpcol[0] = (ba->tmpcol[0] * 0.70) / nbr_shads;
	ba->tmpcol[1] = (ba->tmpcol[1] * 0.70) / nbr_shads;
	ba->tmpcol[2] = (ba->tmpcol[2] * 0.70) / nbr_shads;
}

void		ft_shadow(t_ba *ba, t_obj *obj)
{
	t_ba	shad;
	int		nbr_shads;

	nbr_shads = 0;
	obj = obj->next;
	while (obj->pos != 0)
	{
		if (obj->type == 1)
		{
			ft_init_shad(ba, &shad, obj);
			if (ft_isshads(ba, &shad, obj) == 1)
				nbr_shads++;
		}
		obj = obj->next;
	}
	if (nbr_shads != 0)
		ft_set_shads(ba, nbr_shads);
	free(shad.cam);
}
