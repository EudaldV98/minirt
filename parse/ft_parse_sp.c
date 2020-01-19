/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_sp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:55:56 by jvaquer           #+#    #+#             */
/*   Updated: 2020/01/19 12:40:01 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int		ft_parse_sp_2(char *s, int i, double aux[3])
{
	i = ft_pass_double(s, i);
	i = ft_get_color(aux, s, i);
	ft_set_ori(&g_data->sp->color, aux, 0);
	while (s[i] == ' ')
		i++;
	if (s[i] == 's')
		g_data->sp->spec = 1;
	else if (s[i] == 't')
	{
		g_data->sp->tran = 1;
		i++;
		while (s[i] == ' ')
			i++;
		if (!(s[i] <= '9' && s[i] >= '0') && s[i] != ' ' && s[i] != '\n')
			return (-1);
		g_data->sp->ratio_tran = ft_atod(&s[i]);
		i = ft_pass_double(s, i);
		g_data->sp->ratio_tran = (g_data->sp->ratio_tran == 0) ? 1 :
								g_data->sp->ratio_tran;
	}
	i = g_data->sp->spec == 1 ? i + 1 : i;
	if (i == -1 || (s[i] != '\n' && s[i] != '\0'))
		return (-1);
	return (i);
}

int		ft_parse_sp(char *s, int i)
{
	double				aux[3];
	static t_sphere		*save_sp;

	if (g_data->sp->id != 0)
	{
		if (!(g_data->sp->next = malloc(sizeof(t_sphere))))
			ft_print_error(-1);
		g_data->sp->next->id = g_data->sp->id;
		g_data->sp = g_data->sp->next;
	}
	g_data->sp->ratio_tran = 0;
	while (s[i] == ' ')
		i++;
	if ((i = ft_get_pos(aux, s, i)) == -1)
		return (-1);
	ft_set_ori(&g_data->sp->pos, aux, 0);
	while (s[i] == ' ')
		i++;
	g_data->sp->diameter = ft_atod(&s[i]);
	i = ft_parse_sp_2(s, i, aux);
	if (g_data->sp->id == 0)
		save_sp = g_data->sp;
	g_data->sp->id++;
	g_data->sp->next = save_sp;
	return (i);
}
