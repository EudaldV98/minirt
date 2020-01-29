/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:01:34 by jvaquer           #+#    #+#             */
/*   Updated: 2020/01/29 13:06:16 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	ft_do_recursive_trans(t_vect3 tmp_pix, const int *coord, int num)
{
	g_data->pixel = ft_vec_add(ft_vec_mult_scalar(tmp_pix, 0.2),
					ft_ray_trace(g_data->ray_tran, coord, num - 1));
	ft_reset_pixel(&g_data->pixel);
}
