/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_close_win.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:02:17 by jvaquer           #+#    #+#             */
/*   Updated: 2020/01/10 17:04:06 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int		esc_key(int key, void *p)
{
	if (key == ESC_KEY)
	{
		mlx_destroy_window(g_mlx.mlx, g_mlx.win);
		exit(0);
	}
	return (0);
}

int		close_win(int button, int x, int y, void *p)
{
	mlx_destroy_window(g_mlx.mlx, g_mlx.win);
	exit(0);
}
