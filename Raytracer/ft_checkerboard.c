/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkerboard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/17 16:09:20 by pkesslas          #+#    #+#             */
/*   Updated: 2014/03/25 10:31:17 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

int			ft_iseven(int nb)
{
	int		n;

	n = nb % 2;
	if (n < 0)
		n *= -1;
	return (n);
}

int			ft_color_plane(t_ba *e)
{
	double	cc[3];
	double	p[3];

	cc[X] = e->detmax * e->cam->ray[X] + e->cam->pos[X];
	cc[Y] = e->detmax * e->cam->ray[Y] + e->cam->pos[Y];
	cc[Z] = e->detmax * e->cam->ray[Z] + e->cam->pos[Z];
	p[X] = cc[X] / 6;
	p[Y] = cc[Y] / 6;
	p[Z] = cc[Z] / 6;
	if (ft_iseven(floor(p[Z])) == 0)
	{
		if (ft_iseven(floor(p[X])) == ft_iseven(floor(p[Y])))
			return (1);
		else
			return (0);
	}
	else
	{
		if (ft_iseven(floor(p[X])) == ft_iseven(floor(p[Y])))
			return (0);
		else
			return (1);
	}
}
