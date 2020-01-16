/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janeudaldvaquer <janeudaldvaquer@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:08:44 by jvaquer           #+#    #+#             */
/*   Updated: 2020/01/16 22:59:08 by janeudaldva      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	ft_new_img()
{
	t_image *img;

	if (!(img = malloc(sizeof(t_image))))
		ft_print_error(-1);
	img->image = mlx_new_image(g_mlx.mlx, g_data->render[0], g_data->render[1]);
	if (img->image == NULL)
		ft_print_error(-8);
	img->ptr = mlx_get_data_addr(img->image, &img->bpp, &img->stride,
				&img->endian);
	img->bpp /= 8;
	g_data->im = img;
}

void	ft_put_pixel_to_image(const int coord[2], int color)
{
	if (coord[0] < 0 || coord[0] >= g_data->render[0] ||
		coord[1] < 0 || coord[1] >= g_data->render[1])
		return ;
	*(int *)(g_data->im->ptr + ((coord[0] + coord[1] * g_data->render[0]) *
			g_data->im->bpp)) = color;
}
