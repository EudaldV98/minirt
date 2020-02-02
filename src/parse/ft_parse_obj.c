/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_obj.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:21:38 by jvaquer           #+#    #+#             */
/*   Updated: 2020/02/02 17:58:14 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int		ft_parse_obj(char *s, int i)
{
	while (s[i] && ft_check_valid_obj(s, i))
	{
		if (ft_strncmp(&s[i], "sp", 2) == 0)
			i = ft_parse_sp(s, i + 2);
		else if (ft_strncmp(&s[i], "pl", 2) == 0)
			i = ft_parse_pl(s, i + 2);
		else if (ft_strncmp(&s[i], "sq", 2) == 0)
			i = ft_parse_sq(s, i + 2);
		else if (ft_strncmp(&s[i], "cy", 2) == 0)
			i = ft_parse_cy(s, i + 2);
		else if (ft_strncmp(&s[i], "tr", 2) == 0)
			i = ft_parse_tr(s, i + 2);
		else
			return (-1);
		if (i == -1 || s[i] == '\0')
			break ;
		i++;
	}
	g_data->sp->id = -1;
	g_data->pl->id = -1;
	g_data->sq->id = -1;
	g_data->cy->id = -1;
	g_data->tr->id = -1;
	return (s[i] != '\0' ? -1 : i);
}
