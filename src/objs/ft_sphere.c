/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 10:37:37 by jvaquer           #+#    #+#             */
/*   Updated: 2020/01/23 23:36:15 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

double		ft_intersection_ray_sp(const t_ray ray, t_sphere *sp, t_vect3 *p,
									t_vect3 *n)
{
	double	norm_2;
	t_vect3	var;
	double	sol[2];
	double	delta;
	double	res;

	var.x = 1;
	var.y = 2 * ft_dot_product(ray.dir, ft_vec_diff(ray.origin, sp->pos));
	norm_2 = ft_get_norm2(ft_vec_diff(ray.origin, sp->pos));
	var.z = norm_2 - (sp->diameter / 2) * (sp->diameter / 2);
	delta = var.y * var.y - 4 * var.x * var.z;
	if (delta < 0)
		return (0);
	sol[0] = (-var.y - sqrt(delta)) / (2 * var.x);
	sol[1] = (-var.y + sqrt(delta)) / (2 * var.x);
	if (sol[1] < 0)
		return (0);
	if (sol[0] > 0)
		res = sol[0];
	else
		res = sol[1];
	*p = ft_vec_add(ray.origin, ft_vec_mult_scalar(ray.dir, res));
	*n = ft_normal_vector(ft_vec_diff(*p, sp->pos));
	return (res);
}

double		ft_for_each_sphere(const t_ray ray, t_vect3 *p, t_vect3 *n)
{
	double	inter;
	double	min;
	int		pos;

	min = -1;
	pos = 2;
	ft_reset_lst("sphere");
	while (1)
	{
		inter = ft_intersection_ray_sp(ray, g_data->sp, p, n);
		if (inter)
			if (inter < min || min == -1)
			{
				min = inter;
				pos = g_data->sp->id;
			}
		if (g_data->sp->id == -1)
			break;
		g_data->sp = g_data->sp->next;
	}
	if (min > 0)
		while (g_data->sp->id != pos)
			g_data->sp = g_data->sp->next;
	return (min);
}
