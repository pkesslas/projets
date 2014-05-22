/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavanan <glavanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 18:08:35 by glavanan          #+#    #+#             */
/*   Updated: 2014/03/26 10:37:12 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "rt.h"

void	ft_setimg(t_ba *ba)
{
	int		bpp;
	int		size;
	int		endian;

	size = 0;
	endian = 0;
	bpp = 0;
	ba->img = mlx_new_image(ba->mlx, WD_H, WD_W);
	ba->pix = mlx_get_data_addr(ba->img, &bpp, &size, &endian);
}

int		ft_key_hook(int keycode, t_ba *ba)
{
	if (keycode == 65307)
		exit(0);
	(void)ba;
	return (0);
}

int		ft_expose_hook(t_ba *ba)
{
	int		i;

	i = 0;
	if (ba)
		mlx_put_image_to_window(ba->mlx, ba->wdw, ba->img, 0, 0);
	return (i);
}

void	ft_init_ptrfunc(t_ba *ba)
{
	ba->calinter[2] = &ft_put_sp;
	ba->calinter[3] = &ft_put_pl;
	ba->calinter[4] = &ft_put_cy;
	ba->calinter[5] = &ft_put_co;
	ba->calinter[6] = &ft_put_lp;
	ba->calinter[7] = &ft_put_cu;
	ba->callum[2] = &ft_cal_lum_sp;
	ba->callum[3] = &ft_cal_lum_pl;
	ba->callum[4] = &ft_cal_lum_cy;
	ba->callum[5] = &ft_cal_lum_co;
	ba->callum[6] = &ft_cal_lum_lp;
	ba->callum[7] = &ft_cal_lum_cu;
	ba->cal_ref[2] = &ft_cal_reflect_sp;
	ba->cal_ref[3] = &ft_cal_reflect_pl;
	ba->cal_ref[4] = &ft_cal_reflect_cy;
	ba->cal_ref[5] = &ft_cal_reflect_co;
}

int		main(int argc, char **argv)
{
	t_ba	ba;
	t_obj	obj;
	int		i;

	(void)argc;
	if (!(i = ft_select_env(argv, &obj)))
		return (0);
	ft_init_ptrfunc(&ba);
	if ((ba.mlx = mlx_init()) == NULL)
	{
		ft_putstr("mlx_init failed. Abort.\n");
		exit(-1);
	}
	ba.wdw = mlx_new_window(ba.mlx, (WD_H / 2), (WD_W / 2), "RT - Mr Pickles");
	ft_setimg(&ba);
	ft_draw(&ba, &obj);
	ba.loop = mlx_key_hook(ba.wdw, &ft_key_hook, &ba);
	ba.loop = mlx_expose_hook(ba.wdw, &ft_expose_hook, &ba);
	ba.loop = mlx_loop(ba.mlx);
	return (0);
}
