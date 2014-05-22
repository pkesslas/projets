/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 14:41:16 by pkesslas          #+#    #+#             */
/*   Updated: 2014/01/19 17:22:23 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _WOLF_H_
# define _WOLF_H_

# include "libft/libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <math.h>

typedef struct	s_img
{
	int			bpp;
	int			size_l;
	int			endian;
	int			x;
	int			y;
	char		*data;
	void		*img;
}				t_img;

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	int			albert;
	int			w;
	int			h;
	int			x;
	int			indice;
	char		*beg_str;
	t_img		img;
	t_img		gun;
	int			**map_1;
	int			mapx;
	int			mapy;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	double		s_distx;
	double		s_disty;
	double		d_distx;
	double		d_disty;
	double		wdist;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		cam;
	double		r_posx;
	double		r_posy;
	double		r_dirx;
	double		r_diry;
	double		move_speed;
	double		rot_speed;
}				t_data;

void		ft_init_map_1(t_data *e);
void		ft_copy_tab(int map[21][21], t_data *e);
int			ft_key_hook(int keycode, t_data *e);
void		ft_print_wall(t_data *e);
int			ft_put_p(t_data *e, int x, int y, int color[3]);
void		ft_verline(t_data *e, int y1, int y2, int color);
void		ft_init_vec(t_data *e);
void		ft_init_dda(t_data *e);
void		ft_ray_post(t_data *e);
void		ft_calc_dist(t_data *e);
void		ft_correct_feye(t_data *e);
void		ft_put_floor(t_data *e, int sy, int x);
int			ft_expose_hook(t_data *e);
void		ft_put_sky(t_data *e, int se, int x);
void		ft_dda(t_data *e);
void		ft_move(t_data *e, int keycode);
void		ft_rotate2(t_data *e, int keycode);
void		ft_rotate(t_data *e, int keycode);
void		ft_ray_pos(t_data *e, int x);
void		ft_calc_hwall(t_data *e, int x);
int			ft_abs(int i);

#endif /* _WOLF_H_ */
