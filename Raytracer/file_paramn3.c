/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_paramn3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/15 10:22:34 by pkesslas          #+#    #+#             */
/*   Updated: 2014/03/25 11:48:24 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		ft_chkr(t_obj *obj, char *str, int ret, char *nbr)
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
	obj->chkr = ft_atoi(nbr);
	return (ret);
}

int		ft_text(t_obj *obj, char *str, int ret, char *nbr)
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
	obj->text = ft_atoi(nbr);
	return (ret);
}
