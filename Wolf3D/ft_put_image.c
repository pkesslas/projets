/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 13:34:44 by pkesslas          #+#    #+#             */
/*   Updated: 2014/01/09 16:53:46 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int			ft_put_p(t_data *e, int x, int y, int color[3])
{
	int		i;

	i = y * e->w * 4 + x * 4;
	e->img.data[i++] = color[0];
	e->img.data[i++] = color[1];
	e->img.data[i++] = color[2];
	return (0);
}

void		ft_put_floor(t_data *e, int sy, int x)
{
	int		y;
	int		color[3];

	color[0] = 0x6A;
	color[1] = 0x4B;
	color[2] = 0x24;
	y = e->h - 1;
	while (y != sy)
		ft_put_p(e, x, y--, color);
}

void		ft_put_sky(t_data *e, int se, int x)
{
	int		y;
	int		color[3];

	color[0] = 0x2C;
	color[1] = 0x75;
	color[2] = 0xFF;
	y = 0;
	while (y != se)
		ft_put_p(e, x, y++, color);
}

void		ft_verline(t_data *e, int y1, int y2, int color)
{
	int		tab[3];

	tab[0] = color % 65536;
	color -= tab[0] * 65536;
	tab[1] = color % 256;
	color -= tab[1] * 256;
	tab[2] = color;
	if (y1 > y2)
	{
		while (y2 < y1)
			ft_put_p(e, e->x, y2++, tab);
	}
	else
	{
		while (y2 > y1)
			ft_put_p(e, e->x, y2--, tab);
	}
}
