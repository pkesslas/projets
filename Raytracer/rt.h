/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glavanan <glavanan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/22 18:11:57 by glavanan          #+#    #+#             */
/*   Updated: 2014/03/27 18:29:58 by pkesslas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# define WD_H (640 * 2)
# define WD_W (480 * 2)
# define X 0
# define Y 1
# define Z 2
# define DP 1.0
# define HV 0.35
# define WV 0.5
# define RAD M_PI / 180

# include <unistd.h>
# include "struct.h"

/*
** reflect.c
*/

void	ft_cal_reflect_sp(t_ba *ba, t_obj *obj, double pos[3]);
void	ft_cal_reflect_pl(t_ba *ba, t_obj *obj, double pos[3]);
void	ft_cal_reflect_cy(t_ba *ba, t_obj *obj, double pos[3]);
void	ft_cal_reflect_co(t_ba *ba, t_obj *obj, double pos[3]);
void	ft_reflect_color(t_ba *ba, t_ba *ref, t_obj *obj);
void	ft_cal_reflect(t_ba *ba, t_obj *obj, double pos[3], double secray[3]);
void	ft_reflect(t_ba *ba, t_obj *obj);

/*
**	ft_reflect2.c
*/

void	ft_switchval_init(t_ba *cal, t_ba *ref, t_ba *ba);
void	ft_init_ref(t_ba *ref, double pos[3], double secray[3], t_obj *obj);
void	ft_apply_reflected_color(t_ba *ba, t_obj *obj);

/*
**	Tidy up
*/

void	ft_cal_lum_sp(t_ba *ba, t_obj *obj);
void	ft_cal_lum_pl(t_ba *ba, t_obj *obj);
void	ft_cal_lum_cy(t_ba *ba, t_obj *obj);
void	ft_cal_lum_co(t_ba *ba, t_obj *obj);
void	ft_cal_lum_lp(t_ba *ba, t_obj *obj);
void	ft_cal_lum_cu(t_ba *ba, t_obj *obj);
void	ft_rotate_pos_cyl(double pos[3], t_obj *obj);

/*
**	ft_antialiasing.c
*/

void	ft_antialiasing(t_ba *ba);
void	ft_put_in_int(t_ba *ba);

/*
**	bmp.c
*/

void	writefile(char *pix);
void	writeheader(int fd);
void	reversemirror(char *mir);
void	reversepix(char *s1, char *s2);
void	copypix(char *pix, int j, char *mir);

/*
**	ft_apply_text.c
*/

void	ft_apply_doge(t_ba *e, t_obj *o, double img[3]);
void	ft_apply_mars(t_ba *e, t_obj *o, double img[3]);
void	ft_apply_eye(t_ba *e, t_obj *o, double img[3]);
void	ft_init_text_vec(double vn[3], double ve[3], t_obj *o);
void	ft_init_struct_text(t_ba *ba);

/*
**	ft_texture_sphr.c
*/

void	ft_init_texture(t_ba *ba, t_obj *obj, double norm[3]);
void	ft_init_textures(t_ba *ba);
void	ft_texture(t_ba *e, t_obj *o, double norm[3]);
void	ft_apply_texture(t_ba *e, t_obj *o, double img[3]);

/*
**	ft_perlin.c
*/

void	ft_init_perlin(t_ba *ba, t_obj *obj);
void	ft_reset_obj_col(t_ba *ba, t_obj *obj);

/*
**	ft_shadow.c
*/

void	ft_shadow(t_ba *ba, t_obj *obj);
void	ft_set_shads(t_ba *ba, int nbr_shads);
int		ft_isshads(t_ba *ba, t_ba *shad, t_obj *obj);
void	ft_multi_spot(t_ba *ba);
void	ft_init_shad(t_ba *ba, t_ba *shad, t_obj *obj);

/*
**	ft_light.c
*/

void	ft_calc_lightvec(t_ba *ba, t_obj *obj);
void	ft_calc_reflected_ray(t_ba *ba, double normal[3], t_obj *obj);
void	ft_calc_light(double normal[3], int color[3], t_ba *ba, t_obj *obj);
void	ft_phong(double indice[2], int color[3], t_ba *ba, t_obj *obj);

/*
**	sph.c
*/

double	ft_put_sp(t_ba *ba, t_obj *obj);
double	ft_put_pl(t_ba *ba, t_obj *obj);
double	ft_put_co(t_ba *ba, t_obj *obj);
double	ft_put_cy(t_ba *ba, t_obj *obj);
double	ft_put_lp(t_ba *ba, t_obj *obj);
double	ft_put_cu(t_ba *ba, t_obj *obj);

/*
** ft_cub.c
*/

double	ft_replace(t_ba *ba, t_obj *obj, double det[12], int tmp[6]);
double	ft_replace1(t_ba *ba, t_obj *obj, int tmp[6], double tmp2[12]);
void	ft_save(t_ba *ba, t_obj *obj, int tmp[6], double tmp2[12]);
void	ft_cal_lum_cu(t_ba *ba, t_obj *obj);
void	ft_lum_cub(t_ba *ba, t_obj *obj);
double	ft_put_cu(t_ba *ba, t_obj *obj);
void	ft_lum_cu(t_ba *ba, t_obj *obj);
void	ft_lum_cu2(t_ba *ba, t_obj *obj);
void	ft_put_cu2(t_ba *ba, t_obj *obj);
void	ft_ini_cub(t_ba *ba, t_obj *obj, double cam[3], double ray[3]);

/*
**	ft_draw.c
*/

void	ft_draw(t_ba *ba, t_obj *obj);
void	ft_put_obj(t_ba *ba, t_obj *obj, int x, int y);
void	ft_put_color(t_ba *ba, t_obj *obj);
int		ft_put_p(t_ba *ba, int x, int y, int color[3]);

/*
**	main.c
*/

void	ft_setimg(t_ba *ba);
int		ft_key_hook(int keycode, t_ba *ba);
int		ft_expose_hook(t_ba *ba);

/*
**	ft_ini.c
*/

void	ft_cal_ray(t_ba *ba, int x, int y);
void	ft_ini_next(t_ba *ba, t_obj *obj, double tmp[3]);
void	ft_ini(t_ba *ba, t_obj *obj);

/*
**	math.c
*/

double	scalar(double v[3], double v2[3]);
double	ft_sqrt(double a);
void	normalize(double vec[3]);

/*
**	ft_checkerboard.c
*/

void	ft_check_int(char *str);
void	ft_check_line(char *str, int ret, int nbr);
int		ft_color_plane(t_ba *e);
int		ft_iseven(int nb);

/*
**	ft_types.c
*/

int		ft_file_con(t_obj *obj, char *str, int ret);
int		ft_file_cyl(t_obj *obj, char *str, int ret);
int		ft_file_spo(t_obj *obj, char *str, int ret);
int		ft_file_sph(t_obj *obj, char *str, int ret);
int		ft_file_pla(t_obj *obj, char *str, int ret);
int		ft_file_con(t_obj *obj, char *str, int ret);

/*
**	ft_type2.c
*/

void	ft_check_line(char *str, int ret, int nbr);
int		ft_file_cub(t_obj *obj, char *str, int ret);
int		ft_file_lpl(t_obj *obj, char *str, int ret);

/*
**	ft_env.c
*/

int		ft_file_param(t_obj *obj, char *str, int ret);
int		ft_init_obj(t_obj *obj, char *str, int ret, t_obj *tmp);
int		ft_read_file(int fd, t_obj *obj);
int		ft_select_env(char **argv, t_obj *obj);

/*
**	ft_file_param.c
*/

int		ft_file_cam(t_obj *obj, char *str, int ret);
int		ft_coo(t_obj *obj, char *str, int ret, char *nbr);
int		ft_coo2(t_obj *obj, char *str, int ret, char *nbr);
int		ft_coon(t_obj *obj, char *str, int ret, char *nbr);
int		ft_coon2(t_obj *obj, char *str, int ret, char *nbr);

/*
**	ft_file_paramn.c
*/

int		ft_col2(t_obj *obj, char *str, int ret, char *nbr);
int		ft_col(t_obj *obj, char *str, int ret, char *nbr);
int		ft_ray(t_obj *obj, char *str, int ret, char *nbr);
int		ft_coef(t_obj *obj, char *str, int ret, char *nbr);
int		ft_coefn(t_obj *obj, char *str, int ret, char *nbr);

/*
**	ft_file_paramn3.c
*/

int		ft_chkr(t_obj *obj, char *str, int ret, char *nbr);
int		ft_text(t_obj *obj, char *str, int ret, char *nbr);

/*
**	ft_file_paramn2.c
*/

int		ft_brg(t_obj *obj, char *str, int ret, char *nbr);
int		ft_wood(t_obj *obj, char *str, int ret, char *nbr);
int		ft_perl(t_obj *obj, char *str, int ret, char *nbr);
int		ft_rvb(t_obj *obj, char *str, int ret, char *nbr);
int		ft_rvb2(t_obj *obj, char *str, int ret, char *nbr);

/*
** ft_file_paramn4.c
*/

int		ft_tab3(int file[3], char *str, int ret, char *nbr);
int		ft_tab2(int file[2], char *str, int ret, char *nbr);
int		ft_tab1(int *file, char *str, int ret, char *nbr);
int		ft_tab1v(double *file, char *str, int ret, char *nbr);

/*
**	rotate.c
*/

void	rotate(t_ba *ba, t_obj *obj, double ray[3], double cam[3]);
void	xrotate(double ray[3], double ang);
void	yrotate(double ray[3], double ang);
void	zrotate(double ray[3], double ang);

/*
**	lib.c
*/

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *nptr);
void	ft_putstr(char *s);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char const *s, char const *s2);

/*
**	lib2.c
*/

char	*ft_strcat(char *dest, const char *src);
size_t	ft_strlen(const char *s);

/*
**	ft_misc.c
*/

void	ft_reset_col(t_ba *ba);
void	ft_do_the_light(t_ba *ba, t_obj *obj);
void	ft_finish_bmp(int fd, char *bmp);
int		ft_file_param_next(t_obj *obj, char *str, char *tmp, int ret);

#endif
