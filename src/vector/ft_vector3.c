/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 16:17:15 by jvaquer           #+#    #+#             */
/*   Updated: 2020/01/28 13:25:43 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	ft_set_4vec(t_vect3 *p, t_vect3 *n, t_vect3 aux_p, t_vect3 aux_n)
{
	*p = aux_p;
	*n = aux_n;
}

t_vect3		ft_vect_add_scalar(t_vect3 v, double d)
{
	v.x += d;
	v.y += d;
	v.z += d;
	return (v);
}
