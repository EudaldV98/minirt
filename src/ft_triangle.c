/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_triangle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:59:35 by jvaquer           #+#    #+#             */
/*   Updated: 2020/01/10 17:02:18 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

double		ft_for_each_tr(const t_ray ray, t_vect3 *p, t_vect3 *n)
{
	double	inter;
	double	min;
	int		pos;
	int		check;

	check = 1;
	min = -1;
	pos = g_data->tr->id;
	ft_reset_lst("triangle");
	while (check)
	{
		inter = ft_intersection_ray_tr(ray, g_data->tr, p, n);
		if (inter != 0)
			if (fmin(inter, min) == inter || min == -1)
			{
				min = inter;
				pos = g_data->tr->id;
			}
		if (g_data->tr->id == -1)
			check = 0;
		g_data->tr = g_data->tr->next;
	}
	if (min > 0)
		while (g_data->tr->id != pos)
			g_data->tr = g_data->tr->next;
	return (ft_intersection_ray_tr(ray, g_data->tr, p, n));
}

double		ft_intersection_ray_tr(const t_ray ray, t_triangle *tr,
								t_vect3 *p, t_vect3 *n)
{
	double	t;
	t_vect3	u;
	t_vect3 v;
	t_vect3 w;
	double m11;
	double m12;
	double m22;
	double detm;
	double b11;
	double b21;
	double detb;
	double beta;
	double g12;
	double g22;
	double detg;
	double gamma;
	double alpha;

	*n = ft_normal_vector(ft_cross_product(ft_vec_diff(tr->p_2, tr->p_1), ft_vec_diff(tr->p_3, tr->p_1)));
	if (n->z < 0)
		*n = ft_vec_mult_scalar(*n, -1);
	t = ft_dot_product(ft_vec_diff(tr->p_3, ray.origin), *n) / ft_dot_product(ray.dir, *n);
	if (t < 0)
		return (0);
	*p = ft_vec_add(ray.origin, ft_vec_mult_scalar(ray.dir, t));
	u = ft_vec_diff(tr->p_2, tr->p_1);
	v = ft_vec_diff(tr->p_3, tr->p_1);
	w = ft_vec_diff(*p, tr->p_1);
	m11 = ft_get_norm2(ft_vec_diff(tr->p_2, tr->p_1));
	m12 = ft_dot_product(u, v);
	m22 = ft_get_norm2(v);
	detm = m11 * m22 - m12 * m12;

	b11 = ft_dot_product(w, u);
	b21 = ft_dot_product(w, v);
	detb = b11 * m22 - b21 * m12;
	beta = detb / detm;

	g12 = b11;
	g22 = b21;
	detg = m11 * g22 - m12 * g12;

	gamma = detg / detm;

	alpha = 1 - beta - gamma;
	if (alpha < 0 || alpha > 1)
		return (0);
	if (beta < 0 || beta > 1)
		return (0);
	if (gamma < 0 || gamma > 1)
		return (0);
	return(t);
}
