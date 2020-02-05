/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:18:07 by jvaquer           #+#    #+#             */
/*   Updated: 2020/02/05 16:11:02 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

double		ft_intersection_ray_pl(const t_ray ray, t_plane *pl,
									t_vect3 *p, t_vect3 *n)
{
	double	t;
	double	a;
	double	b;
	t_vect3	x;
	t_vect3 norm;

	norm = ft_normal_vector(pl->ori);
	x = ft_vec_diff(ray.origin, pl->pos);
	a = ft_dot_product(x, norm);
	b = ft_dot_product(ray.dir, norm);
	if (b == 0 || (a < 0 && b < 0) || (a > 0 && b > 0))
		return (0);
	t = -a / b;
	if (t < EPS)
		return (0);
	*p = ft_vec_add(ray.origin, ft_vec_mult_scalar(ray.dir, t));
	if (ft_dot_product(ray.dir, norm) < 0)
		*n = norm;
	else
		*n = ft_vec_mult_scalar(norm, -1);
	return (t);
}

double		ft_for_each_pl(const t_ray ray, t_vect3 *p, t_vect3 *n)
{
	double	inter;
	double	min;
	int		pos;

	min = -1;
	pos = g_data->pl->id;
	ft_reset_lst("plane");
	while (1)
	{
		inter = ft_intersection_ray_pl(ray, g_data->pl, p, n);
		if (inter > EPS)
			if (fmin(inter, min) == inter || min == -1)
			{
				min = inter;
				pos = g_data->pl->id;
			}
		if (g_data->pl->id == -1)
			break ;
		g_data->pl = g_data->pl->next;
	}
	if (min > 0)
		while (g_data->pl->id != pos)
			g_data->pl = g_data->pl->next;
	return (ft_intersection_ray_pl(ray, g_data->pl, p, n));
}
