/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:13:03 by jvaquer           #+#    #+#             */
/*   Updated: 2020/01/23 19:39:05 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int		ft_check_valid_obj(char *s, int i)
{
	if (ft_strncmp(&s[i], "pl", 2) == 0 || ft_strncmp(&s[i], "sp", 2) == 0 ||
		ft_strncmp(&s[i], "sq", 2) == 0 || ft_strncmp(&s[i], "cy", 2) == 0 ||
		ft_strncmp(&s[i], "tr", 2) == 0)
		return (1);
	return (0);
}

int		ft_check_file(char *s)
{
	int		i;

	i = 0;
	if (s[i] == 'R' || s[i] == 'A')
		if ((i = ft_ambiance_res(s, i)) == -1)
			return (-1);
	while (s[i] == '\n')
		i++;
	if (s[i] == 'c' || s[i] == 'l')
		if ((i = ft_camera_light(s, i)) == -1)
			return (-1);
	while (s[i] == '\n')
		i++;
	if (ft_check_valid_obj(s, i) == 1)
		if ((i = ft_parse_obj(s, i)) == -1)
			return (-1);
	return (0);
}
