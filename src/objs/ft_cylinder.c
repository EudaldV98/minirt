/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:49:20 by jvaquer           #+#    #+#             */
/*   Updated: 2020/02/02 19:21:43 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void			ft_get_norm_cy(t_vect3 *n, t_ray ray)
{
	t_vect3		temp;

	*n = ft_vec_diff(ray.origin, g_data->cy->pos);
	temp = ft_vec_mult_scalar(*n, ft_dot_product(*n, g_data->cy->pos));
	*n = ft_vec_diff(ray.origin, ft_vec_add(temp, g_data->cy->pos));
	*n = ft_normal_vector(*n);
	if (ft_dot_product(*n, ray.dir) > 0)
		*n = ft_vec_mult_scalar(*n, -1);
}

double			ft_intersection_ray_cy_2(t_vect3 hty, t_vect3 abc,
		t_vect3 cardoc)
{
	hty.x = sqrt(hty.x);
	hty.y = (-abc.y - hty.x) / abc.x;
	hty.z = cardoc.z + (hty.y * cardoc.y);
	if (hty.z > 0 && hty.z < cardoc.x)
		return (hty.y);
	hty.y = (((hty.z < 0) ? 0 : cardoc.x) - cardoc.z) / cardoc.y;
	hty.y = ((fabs(abc.y + (abc.x * hty.y)) < hty.x) && hty.y > 0) ? hty.y : 0;
	if (hty.y != 0)
		return (hty.y);
	return (0);
}

double			ft_intersection_ray_cy(const t_ray ray, t_cylinder *cy)
{
	t_vect3		ca;
	t_vect3		oc;
	t_vect3		abc;
	t_vect3		hty;
	t_vect3		cardoc;

	ca = ft_vec_diff(ft_vec_add(cy->pos, ft_vec_mult_scalar(cy->ori,
		cy->height)), cy->pos);
	oc = ft_vec_diff(ray.origin, cy->pos);
	cardoc.x = ft_dot_product(ca, ca);
	cardoc.y = ft_dot_product(ca, ray.dir);
	cardoc.z = ft_dot_product(ca, oc);
	abc.x = cardoc.x - (cardoc.y * cardoc.y);
	abc.y = cardoc.x * ft_dot_product(oc, ray.dir) - (cardoc.z * cardoc.y);
	abc.z = cardoc.x * ft_dot_product(oc, oc) - (cardoc.z * cardoc.z)
			- ((cy->diameter / 2) * (cy->diameter / 2) * cardoc.x);
	hty.x = (abc.y * abc.y) - (abc.x * abc.z);
	if (hty.x < EPS)
		return (0);
	return (ft_intersection_ray_cy_2(hty, abc, cardoc));
}

double			ft_for_each_cy(t_ray ray, t_vect3 *p, t_vect3 *n)
{
	double		hit;
	double		min;
	int			pos;

	min = -1;
	ft_reset_lst("cylinder");
	while (1)
	{
		hit = ft_intersection_ray_cy(ray, g_data->cy);
		if (hit > EPS)
			if (min == -1 || hit < min)
			{
				*p = ft_vec_add(ft_vec_mult_scalar(ray.dir, hit), ray.origin);
				ft_get_norm_cy(n, ray);
				min = hit;
				pos = g_data->cy->id;
			}
		if (g_data->cy->id == -1)
			break ;
		g_data->cy = g_data->cy->next;
	}
	if (min > 0)
		while (g_data->cy->id != pos)
			g_data->cy = g_data->cy->next;
	return (min);
}
