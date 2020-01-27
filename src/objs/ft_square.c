/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 16:49:02 by jvaquer           #+#    #+#             */
/*   Updated: 2020/01/23 19:39:41 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void		ft_save_inter(double inter, int pos[2], double *min)
{
	if (*min == -1 || fmin(inter, *min) == inter)
	{
		*min = inter;
		pos[0] = g_data->sq->id;
		pos[1] = g_data->sq->tr->id;
	}
}

void		ft_good_sq(double min, int pos[2])
{
	if (min > 0)
		while (g_data->sq->id != pos[0])
			g_data->sq = g_data->sq->next;
	if (min > 0)
		while (g_data->sq->tr->id != pos[1])
			g_data->sq->tr = g_data->sq->tr->next;
}

double		ft_for_each_square(t_ray ray, t_vect3 *p, t_vect3 *n)
{
	double	inter;
	int		pos[2];
	double	min;

	min = -1;
	while (1)
	{
		while (1)
		{
			inter = ft_intersection_ray_tr(ray, g_data->sq->tr, p, n);
			if (inter != 0)
				ft_save_inter(inter, pos, &min);
			if (g_data->sq->tr->id == -1)
				break ;
			g_data->sq->tr = g_data->sq->tr->next;
		}
		g_data->sq->tr = g_data->sq->tr->next;
		if (g_data->sq->id == -1)
			break ;
		g_data->sq = g_data->sq->next;
	}
	ft_good_sq(min, pos);
	return (ft_intersection_ray_tr(ray, g_data->sq->tr, p, n));
}
