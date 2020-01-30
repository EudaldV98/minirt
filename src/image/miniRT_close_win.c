/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_close_win.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:02:17 by jvaquer           #+#    #+#             */
/*   Updated: 2020/01/30 12:04:41 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int		esc_key(int key)
{
	if (key == 124 || key == 123)
		ft_change_cam(key);
	if (key == ESC_KEY)
	{
		mlx_destroy_window(g_mlx.mlx, g_mlx.win);
		exit(0);
	}
	return (0);
}

int		close_win(void)
{
	mlx_destroy_window(g_mlx.mlx, g_mlx.win);
	exit(0);
}
