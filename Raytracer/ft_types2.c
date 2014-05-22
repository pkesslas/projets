/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavanan <glavanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 17:52:01 by glavanan          #+#    #+#             */
/*   Updated: 2014/03/27 19:01:02 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "rt.h"

void	ft_check_int(char *str)
{
	int		d;

	d = 0;
	while (str[d])
	{
		if (!(str[d] == '.' || str[d] == '-' || (str[d] <= 57 && str[d] >= 48)))
		{
			ft_putstr("Hoy ! Hoy ! Hoy ! Don't try to make me segfault \n");
			exit(1);
		}
		d++;
	}
}

void	ft_check_line(char *str, int ret, int nbr)
{
	int		tab;

	tab = 0;
	while (str[ret] != '}')
	{
		if (str[ret] == '\n')
			tab++;
		ret++;
	}
	if (tab != nbr)
	{
		ft_putstr("Hoy ! Hoy ! Hoy ! Don't try to make me segfault\n");
		exit(1);
	}
}

int		ft_file_cub(t_obj *obj, char *str, int ret)
{
	char	*nbr;

	obj->type = 7;
	ft_check_line(str, ret, 9);
	nbr = (char *)malloc(sizeof(char) * 13);
	ret = ft_tab3(obj->coo, str, ret, nbr);
	ret = ft_tab3(obj->coo2, str, ret, nbr);
	ret = ft_tab3(obj->ve, str, ret, nbr);
	ret = ft_tab3(obj->ve2, str, ret, nbr);
	ret = ft_tab1v(&obj->ray, str, ret, nbr);
	ret = ft_tab3(obj->col, str, ret, nbr);
	ret = ft_coef(obj, str, ret, nbr);
	free(nbr);
	return (ret);
}

int		ft_file_lpl(t_obj *obj, char *str, int ret)
{
	char	*nbr;

	obj->type = 6;
	ft_check_line(str, ret, 9);
	nbr = (char *)malloc(sizeof(char) * 13);
	ret = ft_tab3(obj->coo, str, ret, nbr);
	ret = ft_tab3(obj->coo2, str, ret, nbr);
	ret = ft_tab3(obj->ve, str, ret, nbr);
	ret = ft_tab3(obj->ve2, str, ret, nbr);
	ret = ft_tab1v(&obj->ray, str, ret, nbr);
	ret = ft_tab3(obj->col, str, ret, nbr);
	ret = ft_coef(obj, str, ret, nbr);
	free(nbr);
	return (ret);
}
