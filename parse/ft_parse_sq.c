/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_sq.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:55:34 by jvaquer           #+#    #+#             */
/*   Updated: 2020/01/19 12:40:09 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void		ft_create_square_point(t_square *sq)
{
	sq->tr->p_1.x = sq->pos.x - ((sq->height / 2)) * sq->ori.x;
	sq->tr->p_1.y = sq->pos.y - ((sq->height / 2)) * sq->ori.y;
	sq->tr->p_1.z = sq->pos.z - ((sq->height / 2)) * sq->ori.z;
	sq->tr->p_2.x = sq->pos.x - ((sq->height / 2)) * sq->ori.x;
	sq->tr->p_2.y = sq->pos.y + ((sq->height / 2)) * sq->ori.y;
	sq->tr->p_2.z = sq->pos.z + ((sq->height / 2)) * sq->ori.z;
	sq->tr->p_3.x = sq->pos.x + ((sq->height / 2)) * sq->ori.x;
	sq->tr->p_3.y = sq->pos.y + ((sq->height / 2)) * sq->ori.y;
	sq->tr->p_3.z = sq->pos.z + ((sq->height / 2)) * sq->ori.z;
	sq->tr = sq->tr->next;
	sq->tr->p_3.x = sq->pos.x + ((sq->height / 2)) * sq->ori.x;
	sq->tr->p_3.y = sq->pos.y - ((sq->height / 2)) * sq->ori.y;
	sq->tr->p_3.z = sq->pos.z - ((sq->height / 2)) * sq->ori.z;
	sq->tr->p_1 = sq->tr->next->p_1;
	sq->tr->p_2 = sq->tr->next->p_3;
	sq->tr = sq->tr->next;
	sq->tr = sq->tr->next;
	sq->tr = sq->tr->next;
}

int		ft_parse_sq_3(char *s, int i)
{
	if (s[i] == 'm')
		g_data->sq->spec = 1;
	else if (s[i] == 't')
	{
		g_data->sq->tran = 1;
		while (s[++i] == ' ')
			;
		if (!(s[i] <= '9' && s[i] >= '0') && s[i] != ' ' && s[i] != '\n')
			return (-1);
		g_data->sq->ratio_tran = ft_atod(&s[i]);
		i = ft_pass_double(s, i);
		g_data->sq->ratio_tran = (g_data->sq->ratio_tran == 0) ? 1 :
														g_data->sq->ratio_tran;
	}
	return (i);
}

int		ft_parse_sq_2(char *s, int i, double aux[3])
{
	if (g_data->sq->id != 0)
	{
		if (!(g_data->sq->next = malloc(sizeof(t_square))))
			ft_print_error(-1);
		g_data->sq->next->id = g_data->sq->id;
		g_data->sq = g_data->sq->next;
	}
	while (s[i] == ' ')
		i++;
	if ((i = ft_get_pos(aux, s, i)) == -1)
		return (-1);
	ft_set_ori(&g_data->sq->pos, aux, 0);
	while (s[i] == ' ')
		i++;
	i = ft_get_ori(aux, s, i);
	if (i == -1 || ft_set_ori(&g_data->sq->ori, aux, 1) == -1)
		return (-1);
	while (s[i] == ' ')
		i++;
	g_data->sq->height = ft_atod(&s[i]);
	i = ft_pass_double(s, i);
	i = ft_get_color(aux, s, i);
	if (i == -1 || ft_set_ori(&g_data->sq->color, aux, 2) == -1)
		return (-1);
	return (i);
}

int		ft_parse_sq(char *s, int i)
{
	double				aux[3];
	static t_square		*save_sq;

	g_data->sq->ratio_tran = 0;
	i = ft_parse_sq_2(s, i, aux);
	while (s[i] == ' ')
		i++;
	i = ft_parse_sq_3(s, i);
	i = g_data->sq->spec == 1 && i != -1 ? i + 1 : i;
	if ((s[i] != '\n' && s[i] != '\0') || ft_init_tr_in_sq(g_data->sq) == -1)
		return (-1);
	ft_create_square_point(g_data->sq);
	if (g_data->sq->id == 0)
		save_sq = g_data->sq;
	g_data->sq->id++;
	g_data->sq->next = save_sq;
	return (i);
}
