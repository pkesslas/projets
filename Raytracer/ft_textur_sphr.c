/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textur_sphr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/16 11:04:28 by pkesslas          #+#    #+#             */
/*   Updated: 2014/03/26 10:36:42 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <mlx.h>
#include <math.h>
#include <stdlib.h>

void			ft_apply_texture(t_ba *e, t_obj *o, double img[3])
{
	if (o->text == 1)
		ft_apply_doge(e, o, img);
	else if (o->text == 2)
		ft_apply_mars(e, o, img);
	else if (o->text == 3)
		ft_apply_eye(e, o, img);
}

void			ft_normalize_ve_vn(double ve[3], double vn[3])
{
	normalize(ve);
	normalize(vn);
}

void			ft_texture(t_ba *e, t_obj *o, double norm[3])
{
	double		vn[3];
	double		ve[3];
	double		tmp[3];
	double		img[2];
	double		grk[2];

	ft_init_text_vec(vn, ve, o);
	ft_normalize_ve_vn(ve, vn);
	grk[0] = acos(-scalar(vn, norm));
	if (o->text == 1)
		img[0] = e->doge->y * (1 - grk[0] / M_PI);
	else if (o->text == 2)
		img[0] = e->mars->y * (1 - grk[0] / M_PI);
	else if (o->text == 3)
		img[0] = e->eye->y * (1 - grk[0] / M_PI);
	grk[1] = (acos(scalar(norm, ve) / sin(grk[0]))) / (2.0 * M_PI);
	tmp[X] = (vn[Y] * ve[Z]) - (ve[Z] * vn[Y]);
	tmp[Y] = (vn[Z] * ve[X]) - (ve[X] * vn[Z]);
	tmp[Z] = (vn[X] * ve[Y]) - (ve[Y] * vn[X]);
	if (scalar(tmp, norm) > 0)
		img[1] = grk[1];
	else
		img[1] = 1 - grk[1];
	ft_apply_texture(e, o, img);
}

void			ft_init_texture(t_ba *ba, t_obj *obj, double norm[3])
{
	ba->c1[0] = obj->col[0];
	ba->c1[1] = obj->col[1];
	ba->c1[2] = obj->col[2];
	ba->c2[0] = obj->col2[0];
	ba->c2[1] = obj->col2[1];
	ba->c2[2] = obj->col2[2];
	ft_texture(ba, obj, norm);
}

void			ft_init_textures(t_ba *ba)
{
	ft_init_struct_text(ba);
	ba->eye->x = WD_W;
	ba->eye->y = WD_H;
	ba->eye->img = mlx_xpm_file_to_image(ba->mlx,
		"texture/eye.xpm", &ba->eye->x, &ba->eye->y);
	ba->eye->data = mlx_get_data_addr(ba->eye->img, &ba->eye->bpp,
		&ba->eye->size, &ba->eye->endian);
	ba->mars->x = WD_W;
	ba->mars->y = WD_H;
	ba->mars->img = mlx_xpm_file_to_image(ba->mlx,
		"texture/mars.xpm", &ba->mars->x, &ba->mars->y);
	ba->mars->data = mlx_get_data_addr(ba->mars->img, &ba->mars->bpp,
		&ba->mars->size, &ba->mars->endian);
	ba->doge->x = WD_W;
	ba->doge->y = WD_H;
	ba->doge->img = mlx_xpm_file_to_image(ba->mlx,
		"texture/doge.xpm", &ba->doge->x, &ba->doge->y);
	ba->doge->data = mlx_get_data_addr(ba->doge->img, &ba->doge->bpp,
		&ba->doge->size, &ba->doge->endian);
}
