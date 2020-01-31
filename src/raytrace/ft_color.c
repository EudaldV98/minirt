/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 13:13:57 by jvaquer           #+#    #+#             */
/*   Updated: 2020/01/31 14:40:39 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void		ft_reset_values(t_vect3 *pixel)
{
	pixel->x = 0;
	pixel->y = 0;
	pixel->z = 0;
}

void		ft_check_abs_value(t_vect3 *pixel)
{
	pixel->x = pow(pixel->x, 1 / 2.2);
	pixel->y = pow(pixel->y, 1 / 2.2);
	pixel->z = pow(pixel->z, 1 / 2.2);
	if (pixel->x > 255 || pixel->y > 255 || pixel->z > 255)
	{
		pixel->x = pixel->x > 255 ? 255 : pixel->x;
		pixel->y = pixel->y > 255 ? 255 : pixel->y;
		pixel->z = pixel->z > 255 ? 255 : pixel->z;
	}
	else if (pixel->x < 0 || pixel->y < 0 || pixel->z < 0)
	{
		pixel->x = pixel->x < 0 ? 0 : pixel->x;
		pixel->y = pixel->y < 0 ? 0 : pixel->y;
		pixel->z = pixel->z < 0 ? 0 : pixel->z;
	}
}

int			ft_set_ambience_intensity(t_vect3 *intensity, t_vect3 *ambience)
{
	ambience->x = g_data->amb.ratio * (g_data->amb.color.x / COLOR_MAX);
	ambience->y = g_data->amb.ratio * (g_data->amb.color.y / COLOR_MAX);
	ambience->z = g_data->amb.ratio * (g_data->amb.color.z / COLOR_MAX);
	intensity->x = INTENSITY * g_data->li->ratio * (g_data->li->color.x
					/ COLOR_MAX);
	intensity->y = INTENSITY * g_data->li->ratio * (g_data->li->color.y
					/ COLOR_MAX);
	intensity->z = INTENSITY * g_data->li->ratio * (g_data->li->color.z
					/ COLOR_MAX);
	if (ambience->x < 0.001 && ambience->y < 0.001 && ambience->z < 0.001)
		*ambience = ft_vect_add_scalar(*ambience, 0.001);
	return (1);
}

void		ft_color_calc(t_vect3 param[3])
{
	if (g_data->color.x)
		param[2].x = (g_data->color.x / 255) * (param[0].x *
		ft_dot_product(ft_normal_vector(ft_vec_diff(g_data->li->pos,
		g_data->inter.p)), g_data->inter.n) * param[1].x /
		ft_get_norm2(ft_vec_diff(g_data->li->pos, g_data->inter.p)));
	if (g_data->color.y)
		param[2].y = (g_data->color.y / 255) * (param[0].y *
		ft_dot_product(ft_normal_vector(ft_vec_diff(g_data->li->pos,
		g_data->inter.p)), g_data->inter.n) * param[1].y /
		ft_get_norm2(ft_vec_diff(g_data->li->pos, g_data->inter.p)));
	if (g_data->color.z)
		param[2].z = (g_data->color.z / 255) * (param[0].z *
		ft_dot_product(ft_normal_vector(ft_vec_diff(g_data->li->pos,
		g_data->inter.p)), g_data->inter.n) * param[1].z /
		ft_get_norm2(ft_vec_diff(g_data->li->pos, g_data->inter.p)));
}

t_vect3		ft_set_pixel_color(void)
{
	t_vect3		param[3];

	if (g_data->li->id == 0)
	{
		g_data->li->color = g_data->amb.color;
		g_data->li->ratio = g_data->amb.ratio;
	}
	ft_reset_lst("light");
	ft_reset_values(&param[2]);
	while (ft_set_ambience_intensity(&param[1], &param[0]))
	{
		if (g_data->li->id == 0)
			param[2] = ft_vec_mult_scalar(g_data->color,
			g_data->amb.ratio * 10);
		else
			ft_color_calc(param);
		ft_check_abs_value(&param[2]);
		ft_pixel_cmp(&param[2], &g_data->pixel);
		if (g_data->li->id == 0 || g_data->li->id == -1 ||
			!(g_data->li = g_data->li->next))
			break ;
	}
	ft_reset_lst("light");
	return (g_data->pixel);
}
