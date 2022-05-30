/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 16:47:32 by jvaquer           #+#    #+#             */
/*   Updated: 2020/01/23 19:38:09 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void		ft_reset_lst_3(char *lst)
{
	if (ft_strncmp(lst, "plane", 5) == 0 && g_data->pl->next)
	{
		while (g_data->pl->id != -1)
			g_data->pl = g_data->pl->next;
		g_data->pl = g_data->pl->next;
	}
	else if (ft_strncmp(lst, "square", 6) == 0 && g_data->sq->next)
	{
		while (g_data->sq->id != -1)
			g_data->sq = g_data->sq->next;
		g_data->sq = g_data->sq->next;
	}
}

void		ft_reset_lst_2(char *lst)
{
	if (ft_strncmp(lst, "cylinder", 8) == 0 && g_data->cy->next)
	{
		while (g_data->cy->id != -1)
			g_data->cy = g_data->cy->next;
		g_data->cy = g_data->cy->next;
	}
	else if (ft_strncmp(lst, "triangle", 8) == 0 && g_data->tr->next)
	{
		while (g_data->tr->id != -1)
			g_data->tr = g_data->tr->next;
		g_data->tr = g_data->tr->next;
	}
	else if (ft_strncmp(lst, "square", 6) == 0 && g_data->sq->next)
	{
		while (g_data->sq->id != -1)
			g_data->sq = g_data->sq->next;
		g_data->sq = g_data->sq->next;
	}
	ft_reset_lst_3(lst);
}

void		ft_reset_lst(char *lst)
{
	if (ft_strncmp(lst, "light", 5) == 0 && g_data->li->id != 0)
	{
		if (g_data->li->id == 0)
			return ;
		while (g_data->li->id != -1)
			g_data->li = g_data->li->next;
		g_data->li = g_data->li->next;
	}
	else if (ft_strncmp(lst, "camera", 6) == 0 && g_data->cam->next)
	{
		while (g_data->cam->id != -1)
			g_data->cam = g_data->cam->next;
		g_data->cam = g_data->cam->next;
	}
	else if (ft_strncmp(lst, "sphere", 6) == 0 && g_data->sp->next)
	{
		while (g_data->sp->id != -1)
			g_data->sp = g_data->sp->next;
		g_data->sp = g_data->sp->next;
	}
	ft_reset_lst_2(lst);
}
