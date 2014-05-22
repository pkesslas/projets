/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_paramn4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/27 14:34:52 by pkesslas          #+#    #+#             */
/*   Updated: 2014/03/26 20:14:06 by glavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdlib.h>

int		ft_tab3n(int file[3], char *str, int ret, char *nbr)
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
	ft_check_int(nbr);
	file[Z] = ft_atoi(nbr);
	ret = ret + 1;
	i = 0;
	return (ret);
}

int		ft_tab3(int file[3], char *str, int ret, char *nbr)
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
	ft_check_int(nbr);
	file[X] = ft_atoi(nbr);
	ret = ret + 1;
	i = 0;
	while (str[ret] != ',')
		nbr[i++] = str[ret++];
	nbr[i] = '\0';
	ft_check_int(nbr);
	file[Y] = ft_atoi(nbr);
	ret = ft_tab3n(file, str, ret, nbr);
	return (ret);
}

int		ft_tab2(int file[2], char *str, int ret, char *nbr)
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
	ft_check_int(nbr);
	file[X] = ft_atoi(nbr);
	ret = ret + 1;
	i = 0;
	while (str[ret] != ')')
		nbr[i++] = str[ret++];
	nbr[i] = '\0';
	ft_check_int(nbr);
	file[Y] = ft_atoi(nbr);
	return (ret);
}

int		ft_tab1(int *file, char *str, int ret, char *nbr)
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
	ft_check_int(nbr);
	*file = ft_atoi(nbr);
	return (ret);
}

int		ft_tab1v(double *file, char *str, int ret, char *nbr)
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
	ft_check_int(nbr);
	*file = atof(nbr);
	return (ret);
}
