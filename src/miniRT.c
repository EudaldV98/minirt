/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janeudaldvaquer <janeudaldvaquer@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 15:44:18 by jvaquer           #+#    #+#             */
/*   Updated: 2020/01/16 23:06:45 by janeudaldva      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include <stdio.h>
#include <time.h>

void	ft_put_scene(void)
{
	mlx_put_image_to_window(g_mlx.mlx, g_mlx.win, g_data->im->image, 0, 0);
	mlx_key_hook(g_mlx.win, esc_key, 0);
	mlx_hook(g_mlx.win, 17, 0, close_win, g_mlx.win);
	mlx_loop(g_mlx.mlx);
}

void	ft_file(char **av, int *len_name)
{
	char	*file;

	*len_name = 0;
	while (av[1][*len_name] && av[1][*len_name] != '.')
		*len_name += 1;
	if (ft_strcmp(&av[1][*len_name], ".rt"))
		ft_print_error(-2);
	file = ft_read_file(av[1]);
	ft_init();
	if (ft_check_file(file) == -1)
		ft_print_error(-3);
	if (!(g_mlx.mlx = mlx_init()))
		ft_print_error(-4);
	if (!(g_mlx.win = mlx_new_window(g_mlx.mlx, g_data->render[0], g_data->render[1], "miniRT")))
		ft_print_error(-5);
}

void	ft_check_error(int ac)
{
	if (ac <= 1 || ac >= 4)
		ft_print_error(-6);
	if (!(g_data = malloc(sizeof(struct s_data) * 1)))
		ft_print_error(-1);
	if (!(g_mlx.mlx = malloc(sizeof(void*) * 1)))
		ft_print_error(-1);
	if (!(g_mlx.win = malloc(sizeof(void*) * 1)))
		ft_print_error(-1);
	if (ft_malloc_data() == -1)
		ft_print_error(-1);
}

int     main(int ac, char **av)
{
	char        *file;
	int			len_name;

	ft_check_error(ac);
	ft_file(av, &len_name);
	ft_new_img(g_data);
	ft_draw(g_data);
	if (ac == 2)
		ft_put_scene();
	else if (ac == 3 && !(ft_strcmp(av[2], "-save")))
		ft_create_bmp(av[1], len_name);
	return (0);
}
