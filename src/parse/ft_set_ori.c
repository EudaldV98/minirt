/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_ori.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 19:48:03 by jvaquer           #+#    #+#             */
/*   Updated: 2020/01/23 19:39:26 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int		ft_set_ori(t_vect3 *pos, double aux[3], int param)
{
	int		k;

	k = 0;
	while (k <= 2)
	{
		if (param == 1 && (aux[k] < -1.0 || aux[k] > 1.0))
			return (-1);
		if (param == 2 && (aux[k] < 0 || aux[k] > 255))
			return (-1);
		k++;
	}
	pos->x = aux[0];
	pos->y = aux[1];
	pos->z = aux[2];
	return (0);
}
