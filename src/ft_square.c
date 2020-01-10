/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:49:02 by jvaquer           #+#    #+#             */
/*   Updated: 2020/01/10 17:02:00 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

double		ft_for_each_square(t_ray ray, t_vect3 *p, t_vect3 *n)
{
	double		inter;
	int			pos[2];
	double		min;

	min = -1;
	while(1)
	{
		while (1)
		{
			inter = ft_intersection_ray_tr(ray, g_data->sq->tr, p, n);
			if (inter != 0)
				if (min == -1 || fmin(inter, min) == inter)
				{
					min = inter;
					pos[0] = g_data->sq->id;
					pos[1] = g_data->sq->tr->id;
				}
			if (g_data->sq->tr->id == -1)
				break ;
			g_data->sq->tr = g_data->sq->tr->next;
		}
		g_data->sq->tr = g_data->sq->tr->next;
		if (g_data->sq->id == -1)
			break ;
		g_data->sq = g_data->sq->next;
	}
	if (min > 0)
	{
		while (g_data->sq->id != pos[0])
			g_data->sq = g_data->sq->next;
	}
	if (min > 0)
		while (g_data->sq->tr->id != pos[1])
			g_data->sq->tr = g_data->sq->tr->next;
	return (ft_intersection_ray_tr(ray, g_data->sq->tr, p, n));
}
