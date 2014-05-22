/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkesslas <pkesslas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 11:07:45 by pkesslas          #+#    #+#             */
/*   Updated: 2014/03/26 16:45:53 by glavanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_obj
{
	int				pos;
	int				type;
	int				coo[3];
	int				coo2[3];
	int				limite[2];
	int				ve[3];
	int				ve2[3];
	int				col[3];
	int				col2[3];
	int				bright;
	int				perl;
	int				wood;
	int				chkr;
	int				text;
	double			ray;
	double			detcu[6];
	double			coef[3];
	double			det;
	double			vlight[3];
	double			reflect;
	struct s_obj	*next;
	struct s_obj	*prev;
}					t_obj;

typedef struct		s_perl
{
	double			temp[2];
	double			vec[4];
	double			c[2];
	double			li[2];
	double			grad[8][2];
	double			unit;
	double			tmp;
	int				xb;
	int				yb;
	int				i[2];
	int				gi[4];
}					t_perl;

typedef struct		s_cam
{
	double			pos[3];
	double			upv[3];
	double			riv[3];
	double			up[3];
	double			ray[3];
}					t_cam;

typedef struct		s_img
{
	void			*img;
	char			*data;
	int				bpp;
	int				size;
	int				endian;
	int				x;
	int				y;
}					t_img;

typedef struct		s_ba
{
	void			*mlx;
	void			*wdw;
	void			*img;
	char			*pix;
	double			detmax;
	int				**big_img;
	int				indice[4];
	int				bi;
	int				nu;
	int				x;
	int				y;
	int				save_pos;
	int				save_pos2;
	int				nbr_light;
	int				type;
	int				islight;
	int				loop;
	int				tmpcol[3];
	int				ambcol[3];
	int				tmplight[3];
	int				actbrg;
	int				c1[3];
	int				c2[3];
	int				lightt;
	double			reflected[3];
	double			(*calinter[8])();
	void			(*callum[8])();
	void			(*cal_ref[8])();
	struct s_cam	*cam;
	struct s_img	*mars;
	struct s_img	*eye;
	struct s_img	*doge;
}					t_ba;

#endif
