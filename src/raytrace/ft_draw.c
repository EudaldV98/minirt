/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 11:59:24 by jvaquer           #+#    #+#             */
/*   Updated: 2020/02/02 19:36:34 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void		ft_generate_ray(const int coord[2])
{
	t_vect3	tmp;

	tmp.x = g_data->cam->ori.x * -1 + 1;
	tmp.y = g_data->cam->ori.y * -1 + 1;
	tmp.z = g_data->cam->ori.z > 0 ? 1 : -1;
	g_data->ray.origin.x = g_data->cam->pos.x;
	g_data->ray.origin.y = g_data->cam->pos.y;
	g_data->ray.origin.z = g_data->cam->pos.z;
	g_data->ray.dir.x = coord[0] - (g_data->render[0] / 2) * tmp.x;
	g_data->ray.dir.y = coord[1] - (g_data->render[1] / 2) * tmp.y;
	g_data->ray.dir.z = tmp.z * (-g_data->render[1] /
						(2 * tan((to_rad(g_data->cam->fov) / 2))));
	g_data->ray.dir = ft_normal_vector(g_data->ray.dir);
}

int			ft_check_trans(void)
{
	if ((g_data->sp->tran == 1 && ft_strncmp(g_data->obj, "sp", 2) == 0) ||
		(g_data->pl->tran == 1 && ft_strncmp(g_data->obj, "pl", 2) == 0) ||
		(g_data->tr->tran == 1 && ft_strncmp(g_data->obj, "tr", 2) == 0) ||
		(g_data->sq->tran == 1 && ft_strncmp(g_data->obj, "sq", 2) == 0) ||
		(g_data->cy->tran == 1 && ft_strncmp(g_data->obj, "cy", 2) == 0))
		return (0);
	return (1);
}

int			ft_check_shadow(t_vect3 *p, t_vect3 *n)
{
	t_ray	ray_light;
	t_vect3	tmp_p;
	t_vect3	tmp_n;

	if (g_data->li->id == 0)
		return (0);
	ft_reset_lst("light");
	while (1)
	{
		ray_light.origin = ft_vec_add(*p, ft_vec_mult_scalar(*n, EPS));
		ray_light.dir = ft_normal_vector(ft_vec_diff(g_data->li->pos, *p));
		ft_for_each_obj(ray_light, &tmp_p, &tmp_n);
		if (g_data->inter.pos < EPS || g_data->inter.pos * g_data->inter.pos >
			ft_get_norm2(ft_vec_diff(g_data->li->pos, *p)))
			return (0);
		if (g_data->li->id == -1)
			break ;
		g_data->li = g_data->li->next;
	}
	ft_reset_lst("light");
	return (ft_check_trans());
}

t_vect3		ft_ray_trace(t_ray ray, const int coord[2], int num)
{
	double	inter;
	t_vect3	tmp_pix;

	g_data->ratio_tran = 0;
	inter = ft_for_each_obj(ray, &g_data->inter.p, &g_data->inter.n);
	if (inter)
	{
		tmp_pix = ft_check_transparence(ray);
		if (num >= 0 && ft_check_specular(ray))
			g_data->pixel = ft_ray_trace(g_data->ray_spec, coord, num - 1);
		else if (num >= 0 && tmp_pix.x != -1)
			ft_do_recursive_trans(tmp_pix, coord, num);
		else
		{
			g_data->pixel = ft_set_pixel_color();
			if (g_data->ratio_tran != 1 && ft_check_shadow(&g_data->inter.p,
			&g_data->inter.n))
				g_data->pixel = ft_vec_mult_scalar(g_data->pixel,
				g_data->amb.ratio / 2);
		}
	}
	else
		ft_no_intersection();
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
			if (coord[0] == 900 && coord[1] == 615)
				g_data->check = 1;
			ft_reset_values(&g_data->pixel);
			ft_generate_ray(coord);
			g_data->pixel = ft_ray_trace(g_data->ray, coord, 5);
			ft_put_pixel_to_image(coord, ft_set_color(g_data->pixel));
			coord[1]++;
		}
		coord[0]++;
	}
	coord[0] = 900;
	coord[1] = 615;
	ft_put_pixel_to_image(coord, 0xff0000);
}
