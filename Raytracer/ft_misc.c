/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/01 15:02:55 by pkesslas          #+#    #+#             */
/*   Updated: 2014/03/27 18:31:07 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <unistd.h>
#include <fcntl.h>

void	ft_reset_col(t_ba *ba)
{
	ba->tmpcol[0] = 0x00;
	ba->tmpcol[1] = 0x00;
	ba->tmpcol[2] = 0x00;
	ba->ambcol[0] = 0x00;
	ba->ambcol[1] = 0x00;
	ba->ambcol[2] = 0x00;
}

void	ft_do_the_light(t_ba *ba, t_obj *obj)
{
	while (obj->pos != ba->nu)
		obj = obj->next;
	if (obj->reflect > 0)
		ft_reflect(ba, obj);
	while (obj->pos != 0)
		obj = obj->next;
	ft_multi_spot(ba);
	ft_shadow(ba, obj);
}

void	ft_finish_bmp(int fd, char *mir)
{
	fd = open("rt.bmp", O_RDWR | O_CREAT | O_TRUNC, 0644);
	writeheader(fd);
	write(fd, mir, 480 * 640 * 3);
	close(fd);
}

int		ft_file_param_next(t_obj *obj, char *str, char *tmp, int ret)
{
	if (!(ft_strncmp("plan", tmp, 2)))
		ret = ft_file_pla(obj, str, ret);
	else if (!(ft_strncmp("cone", tmp, 2)))
		ret = ft_file_con(obj, str, ret);
	else if (!(ft_strncmp("limited", tmp, 2)))
		ret = ft_file_lpl(obj, str, ret);
	else if (!(ft_strncmp("cube", tmp, 2)))
		ret = ft_file_cub(obj, str, ret);
	else if (!(ft_strncmp("end", tmp, 1)))
		ft_putstr("File read\n");
	return (ret);
}
