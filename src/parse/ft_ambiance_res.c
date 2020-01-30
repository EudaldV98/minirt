/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ambiance_res.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 18:35:38 by jvaquer           #+#    #+#             */
/*   Updated: 2020/01/30 16:18:40 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int		ft_parse_render(char *s, int i)
{
	while (s[i] == ' ')
		i++;
	if (s[i] > '9' || s[i] < '0')
		return (-1);
	g_data->render[0] = ft_atoi(&s[i]);
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	while (s[i] == ' ')
		i++;
	if (s[i] > '9' || s[i] < '0')
		return (-1);
	g_data->render[1] = ft_atoi(&s[i]);
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if (s[i] != '\n')
		return (-1);
	i++;
	return (i);
}

int		ft_parse_ambiance(char *s, int i)
{
	int		k;
	double	aux[3];

	while (s[i] == ' ')
		i++;
	if (s[i] < '0' || s[i] > '9')
		return (-1);
	g_data->amb.ratio = ft_atod(&s[i]);
	if (g_data->amb.ratio < 0.0 || g_data->amb.ratio > 1.0)
		return (-1);
	i = ft_pass_double(s, i);
	k = -1;
	while (s[i] == ' ')
		i++;
	i = ft_get_color(aux, s, i);
	if (ft_set_ori(&g_data->amb.color, aux, 2) == -1)
		return (-1);
	g_data->amb.color.x = g_data->amb.color.x == 0 ? 1 : g_data->amb.color.x;
	g_data->amb.color.y = g_data->amb.color.x == 0 ? 1 : g_data->amb.color.y;
	g_data->amb.color.z = g_data->amb.color.x == 0 ? 1 : g_data->amb.color.z;
	return ((s[i++] == '\n' ? i : -1));
}

int		ft_ambiance_res(char *s, int i)
{
	static int		check;

	if (check >= 2)
		return (-1);
	check = 0;
	if (s[i] == 'R')
	{
		check = 1;
		i = ft_parse_render(s, i + 1);
	}
	else
		i = ft_parse_render(s, i + 1);
	if (i == -1 || (s[i] == 'R' && check == 1) || (check == 0 && s[i] == 'A'))
		return (-1);
	i = (check == 1) ? ft_parse_ambiance(s, i + 1) : ft_parse_render(s, i + 1);
	check += 2;
	g_data->render[0] = g_data->render[0] > 2560 ? 2560 : g_data->render[0];
	g_data->render[1] = g_data->render[1] > 1395 ? 1395 : g_data->render[1];
	return (i);
}
