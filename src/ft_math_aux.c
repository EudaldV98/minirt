/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 11:10:14 by jvaquer           #+#    #+#             */
/*   Updated: 2020/01/10 16:59:48 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

double		to_rad(const double deg)
{
	return (deg * M_PI / 180.0);
}

double		ft_distance(t_vect3 v1, t_vect3 v2)
{
	return (sqrt(pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2) +
			pow(v1.z - v2.z, 2)));
}

t_vect3		ft_vect_div(t_vect3 v1, t_vect3 v2)
{
	t_vect3 res;

	res.x = v1.x / v2.x;
	res.y = v1.y / v2.y;
	res.z = v1.z / v2.z;
	return (res);
}

t_vect3		ft_vec_sub(t_vect3 v1, double d)
{
	t_vect3 res;

	res.x = v1.x - d;
	res.y = v1.y - d;
	res.z = v1.z - d;
	return (res);
}

double		sqr(double x)
{
	return (x * x);
}
