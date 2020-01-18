/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:59:24 by jvaquer           #+#    #+#             */
/*   Updated: 2020/01/18 22:06:22 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include <time.h>

void		ft_generate_ray(const int coord[2])
{
	g_data->ray.origin.x = g_data->cam->pos.x;
	g_data->ray.origin.y = g_data->cam->pos.y;
	g_data->ray.origin.z = g_data->cam->pos.z;
	g_data->ray.dir.y = coord[1] - (g_data->render[1] / 2) * g_data->cam->ori.y;
	g_data->ray.dir.x = coord[0] - (g_data->render[0] / 2) * g_data->cam->ori.x;
	g_data->ray.dir.z = (-g_data->render[1] /
						(2 * tan((to_rad(g_data->cam->fov) / 2))));
	g_data->ray.dir = ft_normal_vector(g_data->ray.dir);
}

int		ft_for_each_obj(t_ray ray, t_vect3 *p, t_vect3 *n)
{
	double		tmp;
	t_vect3		tmp_p;
	t_vect3		tmp_n;
	
	g_data->inter.pos = 0;
	ft_reset_lst("all obj");
	if (g_data->sp->next)
		g_data->inter.pos = ft_for_each_sphere(ray, p, n);
	g_data->color = g_data->sp->color;
	g_data->obj = "sp";
	if (g_data->pl->next)
		tmp = ft_for_each_pl(ray, &tmp_p, &tmp_n);
	if (!g_data->inter.pos || (tmp > 0 && tmp < g_data->inter.pos && g_data->inter.pos > 0) ||
		(g_data->inter.pos <= 0 && tmp > 0))
	{
		g_data->inter.pos = tmp;
		*p = tmp_p;
		*n = tmp_n;
		g_data->color = g_data->pl->color;
		g_data->obj = "pl";
	}
	if (g_data->tr->next)
		tmp = ft_for_each_tr(ray, &tmp_p, &tmp_n);
	if (!g_data->inter.pos || (tmp > 0 && tmp < g_data->inter.pos && g_data->inter.pos > 0) ||
		(g_data->inter.pos <= 0 && tmp > 0))
	{
		g_data->inter.pos = tmp;
		*p = tmp_p;
		*n = tmp_n;
		g_data->color = g_data->tr->color;
		g_data->obj = "tr";
	}
	if (g_data->sq->next)
		tmp = ft_for_each_square(ray, &tmp_p, &tmp_n);
	if (!g_data->inter.pos || (tmp > 0 && tmp < g_data->inter.pos && g_data->inter.pos > 0) ||
		(g_data->inter.pos <= 0 && tmp > 0))
	{
		g_data->inter.pos = tmp;
		*p = tmp_p;
		*n = tmp_n;
		g_data->obj = "sq";
		g_data->color = g_data->sq->color;
	}
	if (g_data->cy->next)
		tmp = ft_for_each_cy(ray, &tmp_p, &tmp_n);
	if (!g_data->inter.pos || (tmp > 0 && tmp < g_data->inter.pos && g_data->inter.pos > 0) ||
		(g_data->inter.pos <= 0 && tmp > 0))
	{
		g_data->inter.pos = tmp;
		*p = tmp_p;
		*n = tmp_n;
		g_data->obj = "cy";
		g_data->color = g_data->cy->color;
	}
	if (g_data->inter.pos > EPS)
		return (1);
	return (0);
}

int			ft_check_shadow(t_vect3 *p, t_vect3 *n)
{
	t_ray	ray_light;
	t_vect3	tmp_p;
	t_vect3	tmp_n;

	ft_reset_lst("light");
	while (1)
	{
		ray_light.origin = ft_vec_add(*p, ft_vec_mult_scalar(*n, EPS));
		ray_light.dir = ft_normal_vector(ft_vec_diff(g_data->li->pos, *p));
		if (ft_for_each_obj(ray_light, &tmp_p, &tmp_n) &&
		(g_data->inter.pos < EPS ||
		g_data->inter.pos * g_data->inter.pos > ft_get_norm2(ft_vec_diff(
		g_data->li->pos, *p))))
			return (0);
		if (g_data->li->id == -1)
			break ;
		g_data->li = g_data->li->next;
	}
	ft_reset_lst("light");
	if ((g_data->sp->tran == 1 && ft_strncmp(g_data->obj, "sp", 2) == 0) ||
	(g_data->pl->tran == 1 && ft_strncmp(g_data->obj, "pl", 2) == 0) ||
	(g_data->tr->tran == 1 && ft_strncmp(g_data->obj, "tr", 2) == 0) ||
	(g_data->sq->tran == 1 && ft_strncmp(g_data->obj, "sq", 2) == 0) ||
	(g_data->cy->tran == 1 && ft_strncmp(g_data->obj, "cy", 2) == 0))
		return (0);
	return (1);
}

t_vect3		ft_ray_trace(t_ray ray, const int coord[2], int num)
{
	double	inter;
	t_vect3	tmp_pix;

	g_data->ratio_tran = 0;
	inter = ft_for_each_obj(ray, &g_data->inter.p, &g_data->inter.n);
	if (inter)
	{
		tmp_pix = ft_check_transparence(ray, coord, num);
		if (num >= 0 && ft_check_specular(ray, coord, num))
			g_data->pixel = ft_ray_trace(g_data->ray_spec, coord, num - 1);
		else if (num >= 0 && tmp_pix.x != -1)
		{
			g_data->pixel = ft_vec_add(ft_vec_mult_scalar(tmp_pix, 0.2), ft_ray_trace(g_data->ray_tran, coord, num - 1));
			ft_reset_pixel(&g_data->pixel);
		}
		else
		{
			g_data->pixel = ft_set_pixel_color();
			if (g_data->ratio_tran != 1 && ft_check_shadow(&g_data->inter.p, &g_data->inter.n))
				ft_reset_values(&g_data->pixel);
		}
	}
	else
		g_data->pixel = ft_vec_mult_scalar(ft_vec_mult_scalar(
						g_data->amb.color, g_data->amb.ratio), 0.8);
	return (g_data->pixel);
}

void		ft_draw(void)
{
	int coord[2];

	coord[0] = 0;
	while (coord[0] < (g_data->render[0]))
	{
		coord[1] = 0;
		while (coord[1] < (g_data->render[1]))
		{
			g_data->check = 0;
			if (coord[0] == 1259 && coord[1] == 652)
				g_data->check = 1;
			ft_reset_values(&g_data->pixel);
			ft_generate_ray(coord);
			g_data->pixel = ft_ray_trace(g_data->ray, coord, 5);
			ft_put_pixel_to_image(coord, ft_set_color(g_data->pixel));
			coord[1]++;
		}
		coord[0]++;
	}
}
