/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_text.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/21 12:21:01 by pkesslas          #+#    #+#             */
/*   Updated: 2014/03/26 10:36:12 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdlib.h>

void			ft_apply_doge(t_ba *e, t_obj *o, double img[3])
{
	char		*pos;

	pos = e->doge->data + (int)img[0] * e->doge->size
		+ (int)(img[1] * e->doge->y) * e->doge->bpp / 8;
	o->col[0] = (unsigned char)pos[e->doge->bpp / 8 - 4];
	o->col[1] = (unsigned char)pos[e->doge->bpp / 8 - 3];
	o->col[2] = (unsigned char)pos[e->doge->bpp / 8 - 2];
}

void			ft_apply_mars(t_ba *e, t_obj *o, double img[3])
{
	char		*pos;

	pos = e->mars->data + (int)img[0] * e->mars->size
		+ (int)(img[1] * e->mars->y) * e->mars->bpp / 8;
	o->col[0] = (unsigned char)pos[e->mars->bpp / 8 - 4];
	o->col[1] = (unsigned char)pos[e->mars->bpp / 8 - 3];
	o->col[2] = (unsigned char)pos[e->mars->bpp / 8 - 2];
}

void			ft_apply_eye(t_ba *e, t_obj *o, double img[3])
{
	char		*pos;

	pos = e->eye->data + (int)img[0] * e->eye->size
		+ (int)(img[1] * e->eye->y) * e->eye->bpp / 8;
	o->col[0] = (unsigned char)pos[e->eye->bpp / 8 - 4];
	o->col[1] = (unsigned char)pos[e->eye->bpp / 8 - 3];
	o->col[2] = (unsigned char)pos[e->eye->bpp / 8 - 2];
}

void			ft_init_text_vec(double vn[3], double ve[3], t_obj *o)
{
	vn[X] = 0;
	vn[Z] = 0;
	ve[Y] = 0;
	ve[Z] = 0;
	vn[Y] = o->ray;
	ve[X] = 3;
}

void			ft_init_struct_text(t_ba *ba)
{
	ba->eye = (t_img *)malloc(sizeof(t_img));
	ba->mars = (t_img *)malloc(sizeof(t_img));
	ba->doge = (t_img *)malloc(sizeof(t_img));
	ba->eye->bpp = 0;
	ba->eye->size = 0;
	ba->eye->endian = 0;
	ba->mars->bpp = 0;
	ba->mars->size = 0;
	ba->mars->endian = 0;
	ba->doge->bpp = 0;
	ba->doge->size = 0;
	ba->doge->endian = 0;
}
