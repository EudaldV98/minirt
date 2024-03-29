/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_triangle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:59:35 by jvaquer           #+#    #+#             */
/*   Updated: 2020/02/05 15:51:15 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void		ft_find_inter(double *m, double *b, double *g,
									t_vect3 *u_v_w)
{
	m[0] = ft_get_norm2(u_v_w[0]);
	m[1] = ft_dot_product(u_v_w[0], u_v_w[1]);
	m[2] = ft_get_norm2(u_v_w[1]);
	m[3] = m[0] * m[2] - m[1] * m[1];
	b[0] = ft_dot_product(u_v_w[2], u_v_w[0]);
	b[1] = ft_dot_product(u_v_w[2], u_v_w[1]);
	b[2] = b[0] * m[2] - b[1] * m[1];
	b[3] = b[2] / m[3];
	g[0] = b[0];
	g[1] = b[1];
	g[2] = m[0] * g[1] - m[1] * g[0];
	g[3] = g[2] / m[3];
}

double		ft_intersection_ray_tr(const t_ray ray, t_triangle *tr,
								t_vect3 *p, t_vect3 *n)
{
	double		t_alpha[2];
	t_vect3		u_v_w[3];
	double		m[4];
	double		b[4];
	double		g[4];

	*n = ft_normal_vector(ft_cross_product(ft_vec_diff(tr->p_2, tr->p_1),
			ft_vec_diff(tr->p_3, tr->p_1)));
	if (n->z < 0)
		*n = ft_vec_mult_scalar(*n, -1);
	t_alpha[0] = ft_dot_product(ft_vec_diff(tr->p_3, ray.origin), *n) /
			ft_dot_product(ray.dir, *n);
	if (t_alpha[0] < EPS)
		return (0);
	*p = ft_vec_add(ray.origin, ft_vec_mult_scalar(ray.dir, t_alpha[0]));
	u_v_w[0] = ft_vec_diff(tr->p_2, tr->p_1);
	u_v_w[1] = ft_vec_diff(tr->p_3, tr->p_1);
	u_v_w[2] = ft_vec_diff(*p, tr->p_1);
	ft_find_inter(m, b, g, u_v_w);
	t_alpha[1] = 1 - b[3] - g[3];
	if (t_alpha[1] < 0 || t_alpha[1] > 1 || b[3] < 0 || b[3] > 1 || g[3] < 0 ||
		g[3] > 1)
		return (0);
	return (t_alpha[0]);
}

double		ft_for_each_tr(const t_ray ray, t_vect3 *p, t_vect3 *n)
{
	double	inter;
	double	min;
	int		pos;

	min = -1;
	pos = g_data->tr->id;
	ft_reset_lst("triangle");
	while (1)
	{
		inter = ft_intersection_ray_tr(ray, g_data->tr, p, n);
		if (inter > EPS)
			if (fmin(inter, min) == inter || min == -1)
			{
				min = inter;
				pos = g_data->tr->id;
			}
		if (g_data->tr->id == -1)
			break ;
		g_data->tr = g_data->tr->next;
	}
	if (min > 0)
		while (g_data->tr->id != pos)
			g_data->tr = g_data->tr->next;
	return (ft_intersection_ray_tr(ray, g_data->tr, p, n));
}
