/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:51:56 by jvaquer           #+#    #+#             */
/*   Updated: 2020/02/02 17:15:06 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int		ft_pass_double(char *s, int i)
{
	if (s[i] == '-' && s[i + 1] <= '9' && s[i + 1] >= '0')
		i++;
	while (ft_isdigit(s[i]))
		i++;
	if (s[i] == '.')
		i++;
	while (ft_isdigit(s[i]))
		i++;
	return (i);
}

int		ft_get_color(double color[], char *s, int i)
{
	int		j;

	j = 0;
	while (j <= 2)
	{
		if (j == 0)
			while (s[i] == ' ')
				i++;
		if (!ft_isdigit(s[i]))
			return (-1);
		color[j] = ft_atoi(&s[i]);
		i += ft_strlen_nb(color[j]);
		if (s[i] != ',' && j < 2)
			return (-1);
		i++;
		j++;
	}
	while (--j >= 0)
		if (color[j] > 255 || color[j] < 0)
			return (-1);
	return (i - 1);
}

int		ft_get_ori(double ori[3], const char *s, int i)
{
	int		k;

	k = 0;
	while (k <= 2)
	{
		while (s[i] == ' ')
			i++;
		if (s[i] == '-')
			i++;
		if (s[i] < '0' || s[i] > '9')
			return (-1);
		ori[k] = ft_atod((char *)&s[i]);
		if (ori[k] > 1.0 || ori[k] < -1.0)
			return (-1);
		if (ori[k] < 0.0)
			i++;
		i = ft_pass_double((char *)s, i);
		if (s[i] == ',' && k != 2)
			i++;
		k++;
	}
	return (i);
}

int		ft_get_pos(double pos[3], char *s, int i)
{
	int		j;

	j = 0;
	while (j <= 2)
	{
		if ((s[i] < '0' || s[i] > '9') && (s[i] == '-' &&
			(s[i] < '0' && s[i] > '9')))
			return (-1);
		pos[j] = ft_atod(&s[i]);
		if (pos[j] < 0.0)
			i++;
		while (s[i] >= '0' && s[i] <= '9')
			i++;
		if (s[i] == '.')
			i++;
		while (s[i] >= '0' && s[i] <= '9')
			i++;
		if (s[i] == ',' && j < 2)
			i++;
		j++;
	}
	return (i);
}

int		ft_init_tr_in_sq(t_square *sq)
{
	if (!(sq->tr = malloc(sizeof(t_triangle))))
		return (-1);
	if (!(sq->tr->next = malloc(sizeof(t_triangle))))
		return (-1);
	sq->tr->id = 1;
	sq->tr->next->next = sq->tr;
	sq->tr->next->id = -1;
	sq->tr->color = sq->color;
	sq->tr->next->color = sq->color;
	return (1);
}
