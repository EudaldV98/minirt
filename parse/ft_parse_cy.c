/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 18:10:31 by jvaquer           #+#    #+#             */
/*   Updated: 2020/01/19 12:37:32 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int		ft_parse_cy_3(char *s, int i)
{
	g_data->cy->tran = 1;
	while (s[++i] == ' ')
		;
	if (!(s[i] <= '9' && s[i] >= '0') && s[i] != ' ' && s[i] != '\n')
		return (-1);
	g_data->cy->ratio_tran = ft_atod(&s[i]);
	i = ft_pass_double(s, i);
	g_data->cy->ratio_tran = (g_data->cy->ratio_tran == 0) ? 1 :
													g_data->cy->ratio_tran;
	return (i);
}

int		ft_parse_cy_2(char *s, int i, double aux[3])
{
	if (g_data->cy->id != 0)
	{
		if (!(g_data->cy->next = malloc(sizeof(t_cylinder))))
			ft_print_error(-1);
		g_data->cy->next->id = g_data->cy->id;
		g_data->cy = g_data->cy->next;
	}
	while (s[i] == ' ')
		i++;
	i = ft_get_pos(aux, s, i);
	ft_set_ori(&g_data->cy->pos, aux, 0);
	while (i != -1 && s[i] == ' ')
		i++;
	if (i == -1 || (i = ft_get_ori(aux, s, i)) == -1)
		return (-1);
	if (ft_set_ori(&g_data->cy->ori, aux, 1) == -1)
		return (-1);
	while (s[i] == ' ')
		i++;
	g_data->cy->diameter = ft_atod(&s[i]);
	i = ft_pass_double(s, i);
	while (s[i] == ' ')
		i++;
	g_data->cy->height = ft_atod(&s[i]);
	return (i);
}

int		ft_parse_cy(char *s, int i)
{
	double				aux[3];
	static t_cylinder	*save_cy;

	i = ft_parse_cy_2(s, i, aux);
	i = ft_pass_double(s, i);
	i = ft_get_color(aux, s, i);
	if (ft_set_ori(&g_data->cy->color, aux, 2) == -1)
		return (-1);
	while (s[i] == ' ')
		i++;
	if (s[i] == 'm')
		g_data->cy->spec = 1;
	else if (s[i] == 't')
		i = ft_parse_cy_3(s, i);
	if (i == -1 || (s[i] != '\n' && s[i] != '\0'))
		return (-1);
	if (g_data->cy->id == 0)
		save_cy = g_data->cy;
	g_data->cy->id++;
	g_data->cy->next = save_cy;
	return (i);
}
