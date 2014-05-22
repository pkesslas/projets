/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_paramn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavanan <glavanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 15:53:09 by glavanan          #+#    #+#             */
/*   Updated: 2014/03/26 10:01:02 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdlib.h>

int		ft_coefn(t_obj *obj, char *str, int ret, char *nbr)
{
	int		i;

	i = 0;
	ret = ret + 1;
	while (str[ret] != ')')
	{
		nbr[i] = str[ret];
		ret = ret + 1;
		i++;
	}
	nbr[i] = '\0';
	obj->coef[Z] = atof(nbr);
	ret = ret + 1;
	i = 0;
	return (ret);
}

int		ft_coef(t_obj *obj, char *str, int ret, char *nbr)
{
	int		i;

	i = 0;
	while (str[ret] != '(')
		ret = ret + 1;
	ret = ret + 1;
	while (str[ret] != ',')
	{
		nbr[i] = str[ret];
		ret = ret + 1;
		i++;
	}
	nbr[i] = '\0';
	obj->coef[X] = atof(nbr);
	ret = ret + 1;
	i = 0;
	while (str[ret] != ',')
		nbr[i++] = str[ret++];
	nbr[i] = '\0';
	obj->coef[Y] = atof(nbr);
	ret = ft_coefn(obj, str, ret, nbr);
	return (ret);
}

int		ft_col2(t_obj *obj, char *str, int ret, char *nbr)
{
	int		i;

	i = 0;
	ret = ret + 1;
	while (str[ret] != ')')
	{
		nbr[i] = str[ret];
		ret = ret + 1;
		i++;
	}
	nbr[i] = '\0';
	obj->col[Z] = ft_atoi(nbr);
	ret = ret + 1;
	i = 0;
	return (ret);
}

int		ft_col(t_obj *obj, char *str, int ret, char *nbr)
{
	int		i;

	i = 0;
	while (str[ret] != '(')
		ret = ret + 1;
	ret = ret + 1;
	while (str[ret] != ',')
		nbr[i++] = str[ret++];
	nbr[i] = '\0';
	obj->col[X] = ft_atoi(nbr);
	ret = ret + 1;
	i = 0;
	while (str[ret] != ',')
	{
		nbr[i] = str[ret];
		ret = ret + 1;
		i++;
	}
	nbr[i] = '\0';
	obj->col[Y] = ft_atoi(nbr);
	ret = ft_col2(obj, str, ret, nbr);
	return (ret);
}

int		ft_ray(t_obj *obj, char *str, int ret, char *nbr)
{
	int		i;

	i = 0;
	while (str[ret] != '(')
		ret = ret + 1;
	ret = ret + 1;
	while (str[ret] != ')')
	{
		nbr[i] = str[ret];
		ret = ret + 1;
		i++;
	}
	nbr[i] = '\0';
	obj->ray = ft_atoi(nbr);
	return (ret);
}
