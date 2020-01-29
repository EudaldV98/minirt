/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_camera_light.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 18:53:10 by jvaquer           #+#    #+#             */
/*   Updated: 2020/01/29 19:05:26 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int		ft_parse_camera(char *s, int i)
{
	double	aux[3];

	while (s[i] == ' ')
		i++;
	if ((s[i] < '0' && s[i] > '9' && s[i] != '-') ||
		(s[i] == '-' && s[i + 1] > '9' && s[i + 1] < '0'))
		return (-1);
	i = ft_get_pos(aux, s, i);
	ft_set_ori(&g_data->cam->pos, aux, 0);
	if (i == -1)
		return (i);
	while (s[i] == ' ')
		i++;
	if ((i = ft_get_ori(aux, (const char *)s, i)) == -1)
		return (-1);
	if (ft_set_ori(&g_data->cam->ori, aux, 1) == -1)
		return (-1);
	while (s[i] == ' ')
		i++;
	g_data->cam->fov = ft_atoi(&s[i]);
	i += ft_strlen_nb(g_data->cam->fov);
	return ((s[i] == '\n' ? i + 1 : -1));
}

int		ft_parse_light(char *s, int i)
{
	int		j;
	double	aux[3];

	j = -1;
	while (s[i] == ' ')
		i++;
	i = ft_get_pos(aux, s, i);
	ft_set_ori(&g_data->li->pos, aux, 0);
	if (i == -1)
		return (-1);
	while (s[i] == ' ')
		i++;
	g_data->li->ratio = ft_atod(&s[i]);
	i = ft_pass_double(s, i);
	if ((g_data->li->ratio > 1.0 && g_data->li->ratio < 0.0) || i == -1)
		return (-1);
	i = ft_get_color(aux, s, i);
	if (ft_set_ori(&g_data->li->color, aux, 2) == -1)
		return (-1);
	if (i == -1 || s[i] != '\n')
		return (-1);
	i++;
	return (i);
}

int		ft_is_cam(char *s, int i, t_camera **save_cam)
{
	if (g_data->cam->id != 0)
	{
		if (!(g_data->cam->next = malloc(sizeof(t_camera))))
			ft_print_error(-1);
		g_data->cam->next->id = g_data->cam->id;
		g_data->cam = g_data->cam->next;
	}
	i = ft_parse_camera(s, i + 1);
	if (g_data->cam->id == 0)
		*save_cam = g_data->cam;
	g_data->cam->id++;
	return (i);
}

int		ft_is_light(char *s, int i, t_light **save_light)
{
	if (g_data->li->id != 0)
	{
		if (!(g_data->li->next = malloc(sizeof(t_light))))
			ft_print_error(-1);
		g_data->li->next->id = g_data->li->id;
		g_data->li = g_data->li->next;
	}
	i = ft_parse_light(s, i + 1);
	if (g_data->li->id == 0)
		*save_light = g_data->li;
	g_data->li->id++;
	return (i);
}

int		ft_camera_light(char *s, int i)
{
	t_camera	*save_cam;
	t_light		*save_light;

	while (i != -1 && (s[i] == 'l' || s[i] == 'c'))
	{
		if (s[i] == 'c')
			i = ft_is_cam(s, i, &save_cam);
		else if (s[i] == 'l')
			i = ft_is_light(s, i, &save_light);
	}
	if (g_data->li->id != 0)
	{
		g_data->li->next = save_light;
		g_data->li->id = -1;
		g_data->li = save_light;
	}
	if (g_data->cam->id != 0)
	{
		g_data->cam->next = save_cam;
		g_data->cam->id = -1;
		g_data->cam = save_cam;
	}
	return (i);
}
