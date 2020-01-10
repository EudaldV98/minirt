/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 18:18:14 by jvaquer           #+#    #+#             */
/*   Updated: 2020/01/10 17:59:05 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int		ft_parse_tr_3(char *s, int i)
{
	g_data->tr->tran = 1;
	i++;
	while (s[i] == ' ')
		i++;
	if ((s[i] > '9' || s[i] < '0') && s[i] != ' ' && s[i] != '\n')
		return (-1);
	g_data->tr->ratio_tran = ft_atod(&s[i]);
	i = ft_pass_double(s, i);
	g_data->tr->ratio_tran = (g_data->tr->ratio_tran == 0) ? 1 :
							g_data->tr->ratio_tran;
	return (i);
}

int		ft_parse_tr_2(char *s, int i, double aux[3])
{
	if (g_data->tr->id != 0)
	{
		if (!(g_data->tr->next = malloc(sizeof(t_triangle))))
			ft_print_error(-1);
		g_data->tr->next->id = g_data->tr->id;
		g_data->tr = g_data->tr->next;
	}
	g_data->tr->ratio_tran = 0;
	while (s[i] == ' ')
		i++;
	i = ft_get_pos(aux, s, i);
	ft_set_ori(&g_data->tr->p_1, aux, 0);
	while (i != -1 && s[i] == ' ')
		i++;
	i = ft_get_pos(aux, s, i);
	ft_set_ori(&g_data->tr->p_2, aux, 0);
	while (i != -1 && s[i] == ' ')
		i++;
	if (i == -1 || (i = ft_get_pos(aux, s, i)) == -1)
		return (-1);
	ft_set_ori(&g_data->tr->p_3, aux, 0);
	i = ft_get_color(aux, s, i);
	if (ft_set_ori(&g_data->tr->color, aux, 2) == -1)
		return (-1);
	return (i);
}

int		ft_parse_tr(char *s, int i)
{
	double				aux[3];
	static t_triangle	*save_tr;

	i = ft_parse_tr_2(s, i, aux);
	while (s[i] == ' ')
		i++;
	if (s[i] == 's')
		g_data->tr->spec = 1;
	else if (s[i] == 't')
		i = ft_parse_tr_3(s, i);
	if (i == -1)
		return (-1);
	if (g_data->tr->id == 0)
		save_tr = g_data->tr;
	g_data->tr->id++;
	g_data->tr->next = save_tr;
	return (i);
}
