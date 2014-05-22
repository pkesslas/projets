/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavanan <glavanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/03 12:45:20 by glavanan          #+#    #+#             */
/*   Updated: 2014/03/27 18:35:03 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int		ft_file_param(t_obj *obj, char *str, int ret)
{
	int		i;
	char	*tmp;

	tmp = str;
	i = ret;
	while (i - 1 > 0)
		tmp += 1 + 0 * (i -= 1);
	if (!(ft_strncmp("camera", tmp, 4)))
		ret = ft_file_cam(obj, str, ret);
	if (!(ft_strncmp("spot", tmp, 2)))
		ret = ft_file_spo(obj, str, ret);
	else if (!(ft_strncmp("sphere", tmp, 4)))
		ret = ft_file_sph(obj, str, ret);
	else if (!(ft_strncmp("cylindre", tmp, 6)))
		ret = ft_file_cyl(obj, str, ret);
	else
		return (ft_file_param_next(obj, str, tmp, ret));
	return (ret);
}

int		ft_init_obj(t_obj *obj, char *str, int ret, t_obj *tmp)
{
	ret = ft_file_param(obj, str, ret);
	tmp->next = obj;
	obj->prev = NULL;
	return (ret);
}

int		ft_file(t_obj *obj, char *str, int ret)
{
	t_obj	*tmp;

	tmp = (t_obj *)malloc(sizeof(t_obj));
	if (obj->pos == -1)
	{
		obj->pos = 0;
		ret = ft_init_obj(obj, str, ret, obj);
	}
	else
	{
		tmp->next = obj;
		while (obj->next->pos != 0)
			obj = obj->next;
		tmp->pos = obj->pos + 1;
		ret = ft_init_obj(tmp, str, ret, obj);
	}
	return (ret);
}

int		ft_read_file(int fd, t_obj *obj)
{
	int		ret;
	char	buf[1025];
	char	*tmp;
	char	*str;

	str = (char *)malloc(sizeof(char) * 1);
	ret = 0;
	str[0] = '\0';
	while ((ret = read(fd, buf, 1024)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(str, buf);
		free(str);
		str = tmp;
	}
	ft_putstr(str);
	if (ret == -1)
		return (0);
	obj->pos = -1;
	ret = 0;
	ret = ft_file(obj, str, ret);
	while (str[ret++])
		if (str[ret] >= 97 && str[ret] <= 122 && str[ret - 1] == '\n')
			ret = ft_file(obj, str, ret + 1);
	return (1);
}

int		ft_select_env(char **argv, t_obj *obj)
{
	int		fd;

	obj->pos = -1;
	if (!argv[1])
	{
		ft_putstr_fd("usage : ./rt file\n", 2);
		return (0);
	}
	if (argv[2])
	{
		ft_putstr("only : ");
		ft_putstr(argv[1]);
		ft_putstr(" will be open\n");
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putstr("can't open file");
		return (0);
	}
	ft_read_file(fd, obj);
	return (1);
}
