/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perlin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 11:58:41 by pkesslas          #+#    #+#             */
/*   Updated: 2014/03/26 10:38:45 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

static int	g_perm[] =
{
	151, 160, 137, 91, 90, 15, 131, 13, 201, 95, 96, 53, 194, 233, 7, 225
	, 140, 36, 103, 30, 69, 142, 8, 99, 37, 240, 21, 10, 23, 190, 6, 148
	, 247, 120, 234, 75, 0, 26, 197, 62, 94, 252, 219, 203, 117, 35, 11
	, 32, 57, 177, 33, 88, 237, 149, 56, 87, 174, 20, 125, 136, 171, 168
	, 68, 175, 74, 165, 71, 134, 139, 48, 27, 166, 77, 146, 158, 231, 83
	, 111, 229, 122, 60, 211, 133, 230, 220, 105, 92, 41, 55, 46, 245, 40
	, 244, 102, 143, 54, 65, 25, 63, 161, 1, 216, 80, 73, 209, 76, 132, 187
	, 208, 89, 18, 169, 200, 196, 135, 130, 116, 188, 159, 86, 164, 100, 109
	, 198, 173, 186, 3, 64, 52, 217, 226, 250, 124, 123, 5, 202, 38, 147
	, 118, 126, 255, 82, 85, 212, 207, 206, 59, 227, 47, 16, 58, 17, 182
	, 189, 28, 42, 223, 183, 170, 213, 119, 248, 152, 2, 44, 154, 163
	, 70, 221, 153, 101, 155, 167, 43, 172, 9, 129, 22, 39, 253, 19, 98, 108
	, 110, 79, 113, 224, 232, 178, 185, 112, 104, 218, 246, 97, 228, 251, 34
	, 242, 193, 238, 210, 144, 12, 191, 179, 162, 241, 81, 51, 145, 235, 249
	, 14, 239, 107, 49, 192, 214, 31, 181, 199, 106, 157, 184, 84, 204, 176
	, 115, 121, 50, 45, 127, 4, 150, 254, 138, 236, 205, 93, 222, 114, 67, 29
	, 24, 72, 243, 141, 128, 195, 78, 66, 215, 61, 156, 180
};

void		ft_reset_obj_col(t_ba *ba, t_obj *obj)
{
	obj->col[0] = ba->c1[0];
	obj->col[1] = ba->c1[1];
	obj->col[2] = ba->c1[2];
	obj->col2[0] = ba->c2[0];
	obj->col2[1] = ba->c2[1];
	obj->col2[2] = ba->c2[2];
}

void		ft_file_grad(t_perl *e)
{
	e->grad[0][0] = e->unit;
	e->grad[0][1] = e->unit;
	e->grad[1][0] = -e->unit;
	e->grad[1][1] = e->unit;
	e->grad[2][0] = e->unit;
	e->grad[2][1] = -e->unit;
	e->grad[3][0] = -e->unit;
	e->grad[3][1] = -e->unit;
	e->grad[4][0] = 1;
	e->grad[4][1] = 0;
	e->grad[5][0] = -1;
	e->grad[5][1] = 0;
	e->grad[6][0] = 0;
	e->grad[6][1] = 1;
	e->grad[7][0] = 0;
	e->grad[7][1] = -1;
}

double		ft_perlin2(t_perl *e, float x, float y)
{
	e->temp[0] = x - e->xb;
	e->temp[1] = y - (e->yb + 1);
	e->vec[2] = e->grad[e->gi[2]][0] * e->temp[0]
		+ e->grad[e->gi[2]][1] * e->temp[1];
	e->temp[0] = x - (e->xb + 1);
	e->temp[1] = y - (e->yb + 1);
	e->vec[3] = e->grad[e->gi[3]][0] * e->temp[0]
		+ e->grad[e->gi[3]][1] * e->temp[1];
	e->tmp = x - e->xb;
	e->c[0] = 3 * e->tmp * e->tmp - 2 * e->tmp * e->tmp * e->tmp;
	e->li[0] = e->vec[0] + e->c[0] * (e->vec[1] - e->vec[0]);
	e->li[1] = e->vec[2] + e->c[0] * (e->vec[3] - e->vec[2]);
	e->tmp = y - e->yb;
	e->c[1] = 3 * e->tmp * e->tmp - 2 * e->tmp * e->tmp * e->tmp;
	return (e->li[0] + e->c[1] * (e->li[1] - e->li[0]));
}

double		ft_perlin(t_perl *e, float x, float y, double res)
{
	x /= res;
	y /= res;
	e->unit = 1.0f / sqrt(2);
	ft_file_grad(e);
	e->xb = (int)x;
	e->yb = (int)y;
	e->i[0] = e->xb & 255;
	e->i[1] = e->yb & 255;
	e->gi[0] = g_perm[e->i[0] + g_perm[e->i[1]]] % 8;
	e->gi[1] = g_perm[e->i[0] + 1 + g_perm[e->i[1]]] % 8;
	e->gi[2] = g_perm[e->i[0] + g_perm[e->i[1] + 1]] % 8;
	e->gi[3] = g_perm[e->i[0] + 1 + g_perm[e->i[1] + 1]] % 8;
	e->temp[0] = x - e->xb;
	e->temp[1] = y - e->yb;
	e->vec[0] = e->grad[e->gi[0]][0] * e->temp[0]
		+ e->grad[e->gi[0]][1] * e->temp[1];
	e->temp[0] = x - (e->xb + 1);
	e->temp[1] = y - e->yb;
	e->vec[1] = e->grad[e->gi[1]][0] * e->temp[0]
		+ e->grad[e->gi[1]][1] * e->temp[1];
	return (ft_perlin2(e, x, y));
}

void		ft_init_perlin(t_ba *ba, t_obj *obj)
{
	t_perl	e;
	double	perl;

	perl = 0;
	ba->c1[0] = obj->col[0];
	ba->c1[1] = obj->col[1];
	ba->c1[2] = obj->col[2];
	ba->c2[0] = obj->col2[0];
	ba->c2[1] = obj->col2[1];
	ba->c2[2] = obj->col2[2];
	if (obj->wood >= 1)
	{
		perl = ft_perlin(&e, ba->x, ba->y, obj->perl) * 20;
		perl = perl - fabs(perl);
		perl = perl * M_PI;
		perl = (1 - cos(perl)) * 0.5;
	}
	else
		perl = fabs(ft_perlin(&e, ba->x, ba->y, obj->perl));
	obj->col[0] = perl * ba->c1[0] + (1 - perl) * ba->c2[0];
	obj->col[1] = perl * ba->c1[1] + (1 - perl) * ba->c2[1];
	obj->col[2] = perl * ba->c1[2] + (1 - perl) * ba->c2[2];
}
