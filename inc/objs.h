/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 15:00:54 by jvaquer           #+#    #+#             */
/*   Updated: 2020/01/10 17:07:29 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJS_H
# define OBJS_H

typedef struct			s_vect3
{
	double				x;
	double				y;
	double				z;
}						t_vect3;	


typedef struct			s_ambience
{
	double				ratio;
	t_vect3				color;
}						t_ambience;

typedef struct 			s_camera
{
	t_vect3				pos;
	t_vect3				ori;
	int					fov;
	int					id;
	struct s_camera		*next;
}						t_camera;

typedef struct			s_light
{
	t_vect3				pos;
	double				ratio;
	t_vect3				color;
	int					id;
	struct s_light		*next;
}						t_light;

typedef	struct			s_sphere
{
	t_vect3				pos;
	double				diameter;
	t_vect3				color;
	int					id;
	struct s_sphere		*next;
	int					spec;
	int					tran;
	double				ratio_tran;
}						t_sphere;

typedef	struct			s_plane
{
	t_vect3				pos;
	t_vect3				ori;
	t_vect3				color;
	int					id;
	struct s_plane		*next;
	int					spec;
	int					tran;
	double				ratio_tran;
}						t_plane;

typedef struct 			s_triangle
{
	t_vect3 			p_1;
	t_vect3				p_2;
	t_vect3 			p_3;
	t_vect3 			color;
	int 				id;
	struct s_triangle	*next;
	int					spec;
	int					tran;
	double				ratio_tran;
}						t_triangle;

typedef	struct			s_square 
{
	t_vect3				pos;
	t_vect3				ori;
	double				height;
	t_vect3				color;
	int					id;
	t_triangle			*tr;
	int					spec;
	int					tran;
	struct s_square		*next;
	double				ratio_tran;
}						t_square;

typedef struct 			s_cylinder
{
	t_vect3				pos;
	t_vect3				ori;
	double				diameter;
	double				height;
	t_vect3				color;
	int					id;
	struct s_cylinder	*next;
	int					spec;
	int					tran;
	double				ratio_tran;
}						t_cylinder;

typedef struct			s_ray 
{
	t_vect3				origin;
	t_vect3				dir;
}						t_ray;

#endif
