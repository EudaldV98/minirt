/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_close_win.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:02:17 by jvaquer           #+#    #+#             */
/*   Updated: 2020/01/28 11:36:20 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int		esc_key(int key)
{
	if (key == ESC_KEY)
	{
		mlx_destroy_window(g_mlx.mlx, g_mlx.win);
		exit(0);
	}
	return (0);
}

int		close_win()
{
	mlx_destroy_window(g_mlx.mlx, g_mlx.win);
	exit(0);
}
