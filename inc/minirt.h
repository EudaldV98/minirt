/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 15:44:09 by jvaquer           #+#    #+#             */
/*   Updated: 2020/01/28 13:25:58 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "objs.h"
# include "../minilibx_opengl/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFF_SIZE 1024
# define ESC_KEY 0x35
# define EPS 0.000001
# define INTENSITY 100000000
# define COLOR_MAX 255
# define ERROR_MEM "Error : memory error."
# define ERROR_FILENAME "Error : invalid file name."
# define ERROR_SCENE "Error : scene description invalid."
# define ERROR_MLX "Error : mlx intitialization."
# define ERROR_WINDOW "Error : window creation."
# define ERROR_ARG "Error : invalid arg number."
# define ERROR_BMP "Error : open bmp."
# define ERROR_IMG "Error : image creation."

typedef struct		s_image
{
	void			*image;
	char			*ptr;
	int				bpp;
	int				stride;
	int				endian;
}					t_image;

typedef	struct		s_intersec
{
	t_vect3			p;
	t_vect3			n;
	double			pos;
}					t_intersec;

typedef struct		s_data
{
	int				render[2];
	t_image			*image;
	t_ambience		amb;
	t_camera		*cam;
	t_light			*li;
	t_sphere		*sp;
	t_plane			*pl;
	t_square		*sq;
	t_cylinder		*cy;
	t_triangle		*tr;
	t_image			*im;
	t_ray			ray;
	t_ray			ray_spec;
	t_ray			ray_tran;
	t_vect3			tmp_pix;
	t_vect3			pixel;
	t_vect3			color;
	t_intersec		inter;
	double			ratio_tran;
	double			ratio_spec;
	char			*obj;
	int				check;
}					t_data;

typedef	struct		s_minirt
{
	void			*mlx;
	void			*win;
	int				bpp;
	int				len_line;
	char			*str;
}					t_minirt;

t_minirt			g_mlx;
t_data				*g_data;

int					ft_parse_render(char *s, int i);
int					ft_parse_ambiance(char *s, int i);
int					ft_ambiance_res(char *s, int i);
int					ft_parse_camera(char *s, int i);
int					ft_parse_light(char *s, int i);
int					ft_camera_light(char *s, int i);
int					ft_check_valid_obj(char *s, int i);
int					ft_check_file(char *s);
int					ft_parse_cy(char *s, int i);
int					ft_parse_obj(char *s, int i);
int					ft_parse_pl(char *s, int i);
int					ft_parse_sp(char *s, int i);
int					ft_parse_sq(char *s, int i);
int					ft_parse_tr(char *s, int i);
int					ft_pass_double(char *s, int i);
int					ft_get_color(double color[], char *s, int i);
int					ft_get_ori(double ori[3], const char *s, int i);
int					ft_get_pos(double pos[3], char *s, int i);
int					ft_set_ori(t_vect3 *pos, double aux[3], int param);
void				ft_set_color_ori(t_vect3 *c, const double a[3]);
int					ft_init_tr_in_sq(t_square *sq);

char				*ft_read_file(char *av);
int					ft_set_color(t_vect3 color);
void				ft_init(void);
int					ft_malloc_data(void);

int					esc_key(int key);
int					close_win();

void				ft_new_img();
void				ft_put_pixel_to_image(const int coord[2], int color);
void				ft_reset_values(t_vect3 *pixel);
t_vect3				ft_set_pixel_color();
void				ft_pixel_cmp(t_vect3 *max_pixel, t_vect3 *pixel);

double				to_rad(const double deg);
t_vect3				ft_normal_vector(t_vect3 v);
t_vect3				ft_cross_product(t_vect3 a, t_vect3 b);
double				ft_dot_product(t_vect3 a, t_vect3 b);
t_vect3				ft_vec_diff(t_vect3 v1, t_vect3 v2);
t_vect3				ft_vec_add(t_vect3 v1, t_vect3 v2);
t_vect3				ft_vec_mult_scalar(t_vect3 v1, double d);
t_vect3				ft_vec_div_scalar(t_vect3 v1, double d);
double				ft_get_norm2(t_vect3 v1);
t_vect3				ft_vect_mult(t_vect3 v1, t_vect3 v2);
t_vect3				ft_vnegative(t_vect3 v);
t_vect3				ft_vec_sub(t_vect3 v1, double d);
double				ft_distance(t_vect3 v1, t_vect3 v2);
t_vect3				ft_vect_div(t_vect3 v1, t_vect3 v2);
double				sqr(double x);
void				ft_set_4vec(t_vect3 *p, t_vect3 *n, t_vect3 aux_p,
								t_vect3 aux_n);

t_vect3				ft_ray_trace(t_ray ray, const int coord[2], int num);
void				ft_draw();
double				ft_for_each_sphere(const t_ray ray, t_vect3 *p, t_vect3 *n);
double				ft_for_each_pl(const t_ray ray, t_vect3 *p, t_vect3 *n);
double				ft_for_each_tr(const t_ray ray, t_vect3 *p, t_vect3 *n);
double				ft_for_each_square(t_ray ray, t_vect3 *p, t_vect3 *n);
void				ft_reset_pixel(t_vect3 *pixel);
double				ft_for_each_cy(t_ray ray, t_vect3 *p, t_vect3 *n);
int					ft_for_each_obj(t_ray ray, t_vect3 *p, t_vect3 *n);
double				ft_intersection_ray_tr(const t_ray ray, t_triangle *tr,
											t_vect3 *p, t_vect3 *n);
void				ft_reset_lst(char *lst);
int					ft_check_specular(t_ray ray);
t_vect3				ft_check_transparence(t_ray ray);
void				ft_create_bmp(char *name, int len_name);

int					ft_isdigit(int c);
int					ft_atoi(const char *str);
double				ft_atod(char *s);
void				ft_print_error(int	err);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, unsigned int n);
unsigned int		ft_strlen(const char *str);
int					ft_strlen_nb(int nb);
t_vect3				ft_vect_add_scalar(t_vect3 v, double d);

#endif
