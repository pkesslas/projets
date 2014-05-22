/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavanan <glavanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 14:26:46 by glavanan          #+#    #+#             */
/*   Updated: 2014/03/26 09:56:08 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdlib.h>

int		ft_coon2(t_obj *obj, char *str, int ret, char *nbr)
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
	obj->coo2[Z] = ft_atoi(nbr);
	return (ret);
}

int		ft_coo2(t_obj *obj, char *str, int ret, char *nbr)
{
	int		i;

	i = 0;
	while (str[ret] != '(')
		ret = ret + 1;
	ret = ret + 1;
	while (str[ret] != ',')
		nbr[i++] = str[ret++];
	nbr[i] = '\0';
	obj->coo2[X] = ft_atoi(nbr);
	ret++;
	i = 0;
	while (str[ret] != ',')
	{
		nbr[i] = str[ret];
		ret = ret + 1;
		i++;
	}
	nbr[i] = '\0';
	obj->coo2[Y] = ft_atoi(nbr);
	ret = ft_coon2(obj, str, ret, nbr);
	return (ret);
}

int		ft_coon(t_obj *obj, char *str, int ret, char *nbr)
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
	obj->coo[Z] = ft_atoi(nbr);
	return (ret);
}

int		ft_coo(t_obj *obj, char *str, int ret, char *nbr)
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
	obj->coo[X] = ft_atoi(nbr);
	ret++;
	i = 0;
	while (str[ret] != ',')
		nbr[i++] = str[ret++];
	nbr[i] = '\0';
	obj->coo[Y] = ft_atoi(nbr);
	ret = ft_coon(obj, str, ret, nbr);
	return (ret);
}

int		ft_file_cam(t_obj *obj, char *str, int ret)
{
	char	*nbr;

	obj->type = 0;
	nbr = (char *)malloc(sizeof(char) * 13);
	ret = ft_coo(obj, str, ret, nbr);
	ret = ft_coo2(obj, str, ret, nbr);
	free(nbr);
	return (ret);
}
