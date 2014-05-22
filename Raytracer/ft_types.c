/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavanan <glavanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/23 16:18:22 by glavanan          #+#    #+#             */
/*   Updated: 2014/03/27 19:00:28 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdlib.h>

int		ft_file_con(t_obj *obj, char *str, int ret)
{
	char	*nbr;

	ft_check_line(str, ret, 12);
	obj->type = 5;
	nbr = (char *)malloc(sizeof(char) * 13);
	ret = ft_tab3(obj->coo, str, ret, nbr);
	ret = ft_tab3(obj->coo2, str, ret, nbr);
	ret = ft_tab2(obj->limite, str, ret, nbr);
	ret = ft_tab1v(&obj->ray, str, ret, nbr);
	ret = ft_tab3(obj->col, str, ret, nbr);
	ret = ft_tab3(obj->col2, str, ret, nbr);
	ret = ft_coef(obj, str, ret, nbr);
	ret = ft_tab1(&obj->perl, str, ret, nbr);
	ret = ft_tab1(&obj->wood, str, ret, nbr);
	ret = ft_tab1v(&obj->reflect, str, ret, nbr);
	free(nbr);
	return (ret);
}

int		ft_file_cyl(t_obj *obj, char *str, int ret)
{
	char	*nbr;

	ft_check_line(str, ret, 12);
	obj->type = 4;
	nbr = (char *)malloc(sizeof(char) * 13);
	ret = ft_tab3(obj->coo, str, ret, nbr);
	ret = ft_tab3(obj->coo2, str, ret, nbr);
	ret = ft_tab2(obj->limite, str, ret, nbr);
	ret = ft_tab1v(&obj->ray, str, ret, nbr);
	ret = ft_tab3(obj->col, str, ret, nbr);
	ret = ft_tab3(obj->col2, str, ret, nbr);
	ret = ft_coef(obj, str, ret, nbr);
	ret = ft_tab1(&obj->perl, str, ret, nbr);
	ret = ft_tab1(&obj->wood, str, ret, nbr);
	ret = ft_tab1v(&obj->reflect, str, ret, nbr);
	free(nbr);
	return (ret);
}

int		ft_file_spo(t_obj *obj, char *str, int ret)
{
	char	*nbr;

	obj->type = 1;
	ft_check_line(str, ret, 5);
	nbr = (char *)malloc(sizeof(char) * 13);
	ret = ft_tab3(obj->coo, str, ret, nbr);
	ret = ft_tab3(obj->col, str, ret, nbr);
	ret = ft_tab1(&obj->bright, str, ret, nbr);
	free(nbr);
	return (ret);
}

int		ft_file_sph(t_obj *obj, char *str, int ret)
{
	char	*nbr;

	obj->type = 2;
	ft_check_line(str, ret, 12);
	nbr = (char *)malloc(sizeof(char) * 13);
	ret = ft_tab3(obj->coo, str, ret, nbr);
	ret = ft_tab1v(&obj->ray, str, ret, nbr);
	ret = ft_tab2(obj->limite, str, ret, nbr);
	ret = ft_tab3(obj->col, str, ret, nbr);
	ret = ft_tab3(obj->col2, str, ret, nbr);
	ret = ft_coef(obj, str, ret, nbr);
	ret = ft_tab1(&obj->perl, str, ret, nbr);
	ret = ft_tab1(&obj->wood, str, ret, nbr);
	ret = ft_tab1(&obj->text, str, ret, nbr);
	ret = ft_tab1v(&obj->reflect, str, ret, nbr);
	free(nbr);
	return (ret);
}

int		ft_file_pla(t_obj *obj, char *str, int ret)
{
	char	*nbr;

	obj->type = 3;
	ft_check_line(str, ret, 10);
	nbr = (char *)malloc(sizeof(char) * 13);
	ret = ft_tab3(obj->coo, str, ret, nbr);
	ret = ft_tab3(obj->coo2, str, ret, nbr);
	ret = ft_tab1v(&obj->ray, str, ret, nbr);
	ret = ft_tab3(obj->col, str, ret, nbr);
	ret = ft_tab3(obj->col2, str, ret, nbr);
	ret = ft_coef(obj, str, ret, nbr);
	ret = ft_tab1(&obj->chkr, str, ret, nbr);
	ret = ft_tab1v(&obj->reflect, str, ret, nbr);
	return (ret);
}
