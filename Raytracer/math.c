/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awybiera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/15 17:34:21 by awybiera          #+#    #+#             */
/*   Updated: 2014/03/23 14:39:47 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <math.h>

double	scalar(double a[3], double b[3])
{
	double	ret;

	ret = a[0] * b[0];
	ret += a[1] * b[1];
	ret += a[2] * b[2];
	return (ret);
}

double	ft_sqrt(double a)
{
	return (a * a);
}

void	normalize(double vec[3])
{
	double	len;

	len = sqrt(ft_sqrt(vec[0]) + ft_sqrt(vec[1]) + ft_sqrt(vec[2]));
	vec[0] = vec[0] / len;
	vec[1] = vec[1] / len;
	vec[2] = vec[2] / len;
}

int		getmin(double ret[4])
{
	int		min;
	int		i;

	i = 0;
	while (i < 4 && ret[i] == 0)
		i++;
	min = i;
	while (i < 4)
	{
		if (ret[i] != 0 && ret[min] > ret[i])
			min = i;
		i++;
	}
	return (min);
}
