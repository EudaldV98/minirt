/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_pl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:46:06 by jvaquer           #+#    #+#             */
/*   Updated: 2020/01/23 19:39:15 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int		ft_parse_pl_2(char *s, int i, double aux[3])
{
	g_data->pl->ratio_tran = 0;
	i = ft_get_color(aux, s, i);
	if (i == -1 || ft_set_ori(&g_data->pl->color, aux, 2) == -1)
		return (-1);
	while (s[i] == ' ')
		i++;
	if (s[i] == 's')
		g_data->pl->spec = 1;
	else if (s[i] == 't')
	{
		g_data->pl->tran = 1;
		i++;
		while (s[i] == ' ')
			i++;
		if (!(s[i] <= '9' && s[i] >= '0') && s[i] != ' ')
			return (-1);
		g_data->pl->ratio_tran = ft_atod(&s[i]);
		i = ft_pass_double(s, i);
		g_data->pl->ratio_tran = (g_data->pl->ratio_tran == 0) ? 1 :
								g_data->pl->ratio_tran;
	}
	i = g_data->pl->spec == 1 ? i + 1 : i;
	if (s[i] != '\n' && s[i] != '\0')
		return (-1);
	return (i);
}

int		ft_parse_pl(char *s, int i)
{
	double				aux[3];
	static t_plane		*save_pl;

	if (g_data->pl->id != 0)
	{
		if (!(g_data->pl->next = malloc(sizeof(t_plane))))
			ft_print_error(-1);
		g_data->pl->next->id = g_data->pl->id;
		g_data->pl = g_data->pl->next;
	}
	while (s[i] == ' ')
		i++;
	if ((i = ft_get_pos(aux, s, i)) == -1)
		return (-1);
	ft_set_ori(&g_data->pl->pos, aux, 0);
	if ((i = ft_get_ori(aux, s, i)) == -1)
		return (-1);
	if (ft_set_ori(&g_data->pl->ori, aux, 1) == -1)
		return (-1);
	i = ft_parse_pl_2(s, i, aux);
	if (g_data->pl->id == 0)
		save_pl = g_data->pl;
	g_data->pl->id++;
	g_data->pl->next = save_pl;
	return (i);
}
