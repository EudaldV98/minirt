/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_effects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:05:08 by jvaquer           #+#    #+#             */
/*   Updated: 2020/01/23 23:55:04 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int			ft_check_specular(t_ray ray)
{
	t_vect3	dir_miroir;
	t_vect3	d;

	if ((g_data->sp->tran == 1 && ft_strncmp(g_data->obj, "sp", 2) == 0) ||
	(g_data->pl->tran == 1 && ft_strncmp(g_data->obj, "pl", 2) == 0) ||
	(g_data->tr->tran == 1 && ft_strncmp(g_data->obj, "tr", 2) == 0) ||
	(g_data->sq->tran == 1 && ft_strncmp(g_data->obj, "sq", 2) == 0) ||
	(g_data->cy->tran == 1 && ft_strncmp(g_data->obj, "cy", 2) == 0))
		return (0);
	if ((ft_strncmp(g_data->obj, "sp", 2) == 0 && g_data->sp->spec == 1)
		|| (ft_strncmp(g_data->obj, "pl", 2) == 0 && g_data->pl->spec == 1)
		|| (ft_strncmp(g_data->obj, "tr", 2) == 0 && g_data->tr->spec == 1)
		|| (ft_strncmp(g_data->obj, "sq", 2) == 0 && g_data->tr->spec == 1)
		|| (ft_strncmp(g_data->obj, "cy", 2) == 0 && g_data->cy->spec == 1))
	{
		d = ft_vec_mult_scalar(g_data->inter.n,
			ft_dot_product(g_data->inter.n, ray.dir));
		dir_miroir = ft_vec_diff(ray.dir, ft_vec_mult_scalar(d, 2));
		g_data->ray_spec.origin = ft_vec_add(g_data->inter.p,
								ft_vec_mult_scalar(g_data->inter.n, EPS));
		g_data->ray_spec.dir = dir_miroir;
		return (1);
	}
	return (0);
}

void		ft_filter_color(t_vect3 *color)
{
	if (g_data->sp->tran == 1 && ft_strncmp(g_data->obj, "sp", 2) == 0)
	{
		g_data->ratio_tran = g_data->sp->ratio_tran;
		*color = g_data->sp->color;
	}
	if (g_data->pl->tran == 1 && ft_strncmp(g_data->obj, "pl", 2) == 0)
	{
		g_data->ratio_tran = g_data->pl->ratio_tran;
		*color = g_data->pl->color;
	}
	if (g_data->sq->tran == 1 && ft_strncmp(g_data->obj, "sq", 2) == 0)
	{
		g_data->ratio_tran = g_data->sq->ratio_tran;
		*color = g_data->sq->color;
	}
	if (g_data->tr->tran == 1 && ft_strncmp(g_data->obj, "tr", 2) == 0)
	{
		g_data->ratio_tran = g_data->tr->ratio_tran;
		*color = g_data->tr->color;
	}
	if (g_data->cy->tran == 1 && ft_strncmp(g_data->obj, "cy", 2) == 0)
	{
		g_data->ratio_tran = g_data->cy->ratio_tran;
		*color = g_data->cy->color;
	}
}

void			ft_set_tran_values(t_ray ray, double *n, t_vect3 *n_tran)
{
	n[0] = 1;
	n[1] = g_data->ratio_tran;
	*n_tran = g_data->inter.n;
	if (ft_dot_product(ray.dir, g_data->inter.n) > 0)
	{
		n[0] = g_data->ratio_tran;
		n[1] = 1;
		*n_tran = ft_vec_mult_scalar(g_data->inter.n, -1);
	}
	n[2] = 1 - sqr(n[0] / n[1]) * (1 - sqr(ft_dot_product(*n_tran, ray.dir)));
}

t_vect3			ft_check_transparence(t_ray ray)
{
	t_vect3		tmp;
	t_vect3		aux_dir;
	double		n[3];
	t_vect3		n_tran;
	t_vect3		color;

	color.x = -1;
	ft_filter_color(&color);
	if (g_data->ratio_tran)
	{
		ft_set_tran_values(ray, n, &n_tran);
		if (n[2] > 0)
		{
			g_data->ray_tran.origin = ft_vec_diff(g_data->inter.p,
					ft_vec_mult_scalar(n_tran, EPS));
			tmp = ft_vec_mult_scalar(ft_vec_diff(ray.dir, ft_vec_mult_scalar(n_tran,
					ft_dot_product(ray.dir, n_tran))), (n[0] / n[1]));
			aux_dir = ft_vec_mult_scalar(n_tran, sqrt(n[2]));
			g_data->ray_tran.dir = ft_vec_diff(tmp,aux_dir);
			return (color);
		}
	}
	return (color);
}
