/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 16:45:24 by pkesslas          #+#    #+#             */
/*   Updated: 2014/01/09 16:46:37 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		ft_print_wall(t_data *e)
{
	double	x;

	ft_init_vec(e);
	x = 0;
	while (x < e->w)
	{
		ft_ray_pos(e, x);
		ft_init_dda(e);
		ft_calc_dist(e);
		ft_dda(e);
		ft_correct_feye(e);
		ft_calc_hwall(e, x);
		x++;
	}
}
