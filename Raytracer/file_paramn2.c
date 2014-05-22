/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_paramn2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 14:34:52 by pkesslas          #+#    #+#             */
/*   Updated: 2014/03/26 10:03:32 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_brg(t_obj *obj, char *str, int ret, char *nbr)
{
	int	i;

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
	obj->bright = ft_atoi(nbr);
	return (ret);
}

int		ft_wood(t_obj *obj, char *str, int ret, char *nbr)
{
	int	i;

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
	obj->wood = ft_atoi(nbr);
	return (ret);
}

int		ft_perl(t_obj *obj, char *str, int ret, char *nbr)
{
	int	i;

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
	obj->perl = ft_atoi(nbr);
	return (ret);
}

int		ft_rvb2(t_obj *obj, char *str, int ret, char *nbr)
{
	int	i;

	i = 0;
	ret = ret + 1;
	while (str[ret] != ')')
	{
		nbr[i] = str[ret];
		ret = ret + 1;
		i++;
	}
	nbr[i] = '\0';
	obj->col2[Z] = ft_atoi(nbr);
	ret = ret + 1;
	i = 0;
	return (ret);
}

int		ft_rvb(t_obj *obj, char *str, int ret, char *nbr)
{
	int	i;

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
	obj->col2[X] = ft_atoi(nbr);
	ret = ret + 1;
	i = 0;
	while (str[ret] != ',')
		nbr[i++] = str[ret++];
	nbr[i] = '\0';
	obj->col2[Y] = ft_atoi(nbr);
	ret = ft_rvb2(obj, str, ret, nbr);
	return (ret);
}
