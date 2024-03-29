/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:13:36 by jvaquer           #+#    #+#             */
/*   Updated: 2020/01/23 19:38:46 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_vect3		ft_vec_add(t_vect3 v1, t_vect3 v2)
{
	t_vect3 res;

	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	res.z = v1.z + v2.z;
	return (res);
}

t_vect3		ft_vec_diff(t_vect3 v1, t_vect3 v2)
{
	t_vect3 res;

	res.x = v1.x - v2.x;
	res.y = v1.y - v2.y;
	res.z = v1.z - v2.z;
	return (res);
}

t_vect3		ft_vec_mult_scalar(t_vect3 v1, double d)
{
	t_vect3 res;

	res.x = v1.x * d;
	res.y = v1.y * d;
	res.z = v1.z * d;
	return (res);
}

double		ft_dot_product(t_vect3 a, t_vect3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vect3		ft_cross_product(t_vect3 a, t_vect3 b)
{
	t_vect3	s;

	s.x = a.y * b.z - a.z * b.y;
	s.y = a.z * b.x - a.x * b.z;
	s.z = a.x * b.y - a.y * b.x;
	return (s);
}
