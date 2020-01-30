/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:08:44 by jvaquer           #+#    #+#             */
/*   Updated: 2020/01/30 16:25:33 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	ft_create_all_img(void)
{
	static t_image	*save_img;

	while (g_data->cam->id != -1)
		g_data->cam = g_data->cam->next;
	g_data->cam = g_data->cam->next;
	while (1)
	{
		if (g_data->im->id != 0)
		{
			if (!(g_data->im->next = malloc(sizeof(t_image))))
				ft_print_error(-1);
			g_data->im->next->id = g_data->im->id;
			g_data->im = g_data->im->next;
		}
		ft_new_img();
		ft_draw();
		if (g_data->im->id == 0)
			save_img = g_data->im;
		g_data->im->id++;
		if (g_data->cam->id == -1)
			break ;
		g_data->cam = g_data->cam->next;
	}
	g_data->im->id = -1;
	g_data->im->next = save_img;
}

void	ft_new_img(void)
{
	g_data->im->image = mlx_new_image(g_mlx.mlx, g_data->render[0],
						g_data->render[1]);
	if (g_data->im->image == NULL)
		ft_print_error(-8);
	g_data->im->ptr = mlx_get_data_addr(g_data->im->image, &g_data->im->bpp,
									&g_data->im->stride, &g_data->im->endian);
	g_data->im->bpp /= 8;
}

void	ft_put_pixel_to_image(const int coord[2], int color)
{
	if (coord[0] < 0 || coord[0] >= g_data->render[0] ||
		coord[1] < 0 || coord[1] >= g_data->render[1])
		return ;
	*(int *)(g_data->im->ptr + ((coord[0] + coord[1] * g_data->render[0]) *
			g_data->im->bpp)) = color;
}

void	ft_change_cam(int key)
{
	int		pos;

	pos = g_data->im->id;
	if (key == 123)
		while (g_data->im->next->id != pos)
			g_data->im = g_data->im->next;
	else if (key == 124)
		g_data->im = g_data->im->next;
	mlx_put_image_to_window(g_mlx.mlx, g_mlx.win, g_data->im->image, 0, 0);
}
