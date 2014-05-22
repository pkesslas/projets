/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_antialiasing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 18:20:31 by pkesslas          #+#    #+#             */
/*   Updated: 2014/03/26 10:06:03 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdlib.h>

void		ft_put_in_int(t_ba *ba)
{
	ba->big_img[ba->bi] = (int *)malloc(sizeof(int) * 4);
	ba->big_img[ba->bi][0] = ba->tmpcol[0];
	ba->big_img[ba->bi][1] = ba->tmpcol[1];
	ba->big_img[ba->bi][2] = ba->tmpcol[2];
	ba->bi++;
}

void		ft_set_aa(t_ba *ba, int x, int y)
{
	int		color[3];

	color[0] =
		(ba->big_img[ba->indice[0]][0] + ba->big_img[ba->indice[1]][0]
		+ ba->big_img[ba->indice[2]][0] + ba->big_img[ba->indice[3]][0]) / 4;
	color[1] =
		(ba->big_img[ba->indice[0]][1] + ba->big_img[ba->indice[1]][1]
		+ ba->big_img[ba->indice[2]][1] + ba->big_img[ba->indice[3]][1]) / 4;
	color[2] =
		(ba->big_img[ba->indice[0]][2] + ba->big_img[ba->indice[1]][2]
		+ ba->big_img[ba->indice[2]][2] + ba->big_img[ba->indice[3]][2]) / 4;
	ba->indice[0] += 2;
	ba->indice[1] += 2;
	ba->indice[2] += 2;
	ba->indice[3] += 2;
	ft_put_p(ba, x, y, color);
}

void		ft_antialiasing(t_ba *ba)
{
	int		x;
	int		y;

	x = 0;
	ba->indice[0] = 0;
	ba->indice[1] = 1;
	ba->indice[2] = 960;
	ba->indice[3] = 961;
	while (x < (WD_H / 2))
	{
		y = 0;
		while (y < (WD_W / 2))
		{
			ft_set_aa(ba, x, y);
			y++;
		}
		ba->indice[0] += 960;
		ba->indice[1] += 960;
		ba->indice[2] += 960;
		ba->indice[3] += 960;
		x++;
	}
}
