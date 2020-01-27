/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_each_obj.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 06:32:03 by janeudaldva       #+#    #+#             */
/*   Updated: 2020/01/27 19:14:54 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void			ft_for_each_obj_2(t_ray ray, t_vect3 *p, t_vect3 *n,
								t_vect3 *vec_tmp)
{
	double		tmp;

	if (g_data->pl->next)
		tmp = ft_for_each_pl(ray, &vec_tmp[0], &vec_tmp[1]);
	if (!g_data->inter.pos || (tmp > 0 && tmp < g_data->inter.pos &&
		g_data->inter.pos > 0) || (g_data->inter.pos <= 0 && tmp > 0))
	{
		g_data->inter.pos = tmp;
		*p = vec_tmp[0];
		*n = vec_tmp[1];
		g_data->color = g_data->pl->color;
		g_data->obj = "pl";
	}
	if (g_data->tr->next)
		tmp = ft_for_each_tr(ray, &vec_tmp[0], &vec_tmp[1]);
	if (!g_data->inter.pos || (tmp > 0 && tmp < g_data->inter.pos &&
		g_data->inter.pos > 0) || (g_data->inter.pos <= 0 && tmp > 0))
	{
		g_data->inter.pos = tmp;
		*p = vec_tmp[0];
		*n = vec_tmp[1];
		g_data->color = g_data->tr->color;
		g_data->obj = "tr";
	}
}

void			ft_for_each_obj_3(t_ray ray, t_vect3 *p, t_vect3 *n,
								t_vect3 *vec_tmp)
{
	double		tmp;

	if (g_data->sq->next)
		tmp = ft_for_each_square(ray, &vec_tmp[0], &vec_tmp[1]);
	if (!g_data->inter.pos || (tmp > 0 && tmp < g_data->inter.pos &&
		g_data->inter.pos > 0) || (g_data->inter.pos <= 0 && tmp > 0))
	{
		g_data->inter.pos = tmp;
		*p = vec_tmp[0];
		*n = vec_tmp[1];
		g_data->obj = "sq";
		g_data->color = g_data->sq->color;
	}
	if (g_data->cy->next)
		tmp = ft_for_each_cy(ray, &vec_tmp[0], &vec_tmp[1]);
	if (!g_data->inter.pos || (tmp > 0 && tmp < g_data->inter.pos &&
		g_data->inter.pos > 0) || (g_data->inter.pos <= 0 && tmp > 0))
	{
		g_data->inter.pos = tmp;
		*p = vec_tmp[0];
		*n = vec_tmp[1];
		g_data->obj = "cy";
		g_data->color = g_data->cy->color;
	}
}

int				ft_for_each_obj(t_ray ray, t_vect3 *p, t_vect3 *n)
{
	t_vect3		vec_tmp[2];

	g_data->inter.pos = 0;
	ft_reset_lst("all obj");
	if (g_data->sp->next)
		g_data->inter.pos = ft_for_each_sphere(ray, p, n);
	g_data->color = g_data->sp->color;
	g_data->obj = "sp";
	ft_for_each_obj_2(ray, p, n, vec_tmp);
	ft_for_each_obj_3(ray, p, n, vec_tmp);
	if (g_data->inter.pos > EPS)
		return (1);
	return (0);
}
