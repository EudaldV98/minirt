/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 11:07:43 by jvaquer           #+#    #+#             */
/*   Updated: 2020/02/08 11:08:32 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int		ft_get_ori2(const char *s, int i, double *ori, int k)
{
	if (s[i] < '0' || s[i] > '9')
		return (-1);
	ori[k] = ft_atod((char *)&s[i]);
	if (ori[k] > 1.0 || ori[k] < -1.0)
		return (-1);
	return (0);
}
