/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 15:57:11 by jvaquer           #+#    #+#             */
/*   Updated: 2020/02/02 12:50:17 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

int			ft_set_color(t_vect3 c)
{
	return (((((int)c.x << 8) + (int)c.y) << 8) + (int)c.z);
}

char		*ft_read_file(char *av)
{
	int		r;
	int		fd;
	int		size;
	char	buff[BUFF_SIZE + 1];
	char	*ret;

	fd = open(av, O_RDONLY);
	size = 0;
	while ((r = read(fd, buff, BUFF_SIZE)) > 0)
		size += r;
	close(fd);
	if (size == 0)
		ft_print_error(-3);
	fd = open(av, O_RDONLY);
	if (!(ret = malloc(sizeof(char) * (size + 1))))
		ft_print_error(-1);
	r = read(fd, ret, size);
	ret[size] = '\0';
	return (ret);
}

int			ft_malloc_data(void)
{
	if (!(g_data->cam = malloc(sizeof(t_camera) * 1)))
		ft_print_error(-1);
	if (!(g_data->li = malloc(sizeof(t_light) * 1)))
		ft_print_error(-1);
	if (!(g_data->sp = malloc(sizeof(t_sphere) * 1)))
		ft_print_error(-1);
	if (!(g_data->pl = malloc(sizeof(t_plane) * 1)))
		ft_print_error(-1);
	if (!(g_data->sq = malloc(sizeof(t_square) * 1)))
		ft_print_error(-1);
	if (!(g_data->cy = malloc(sizeof(t_cylinder) * 1)))
		ft_print_error(-1);
	if (!(g_data->tr = malloc(sizeof(t_triangle) * 1)))
		ft_print_error(-1);
	if (!(g_data->im = malloc(sizeof(t_image) * 1)))
		ft_print_error(-1);
	return (0);
}

void		ft_init(void)
{
	g_data->cam->next = NULL;
	g_data->cam->id = 0;
	g_data->li->next = NULL;
	g_data->li->id = 0;
	g_data->sp->next = NULL;
	g_data->sp->id = 0;
	g_data->pl->next = NULL;
	g_data->pl->id = 0;
	g_data->sq->next = NULL;
	g_data->sq->id = 0;
	g_data->cy->next = NULL;
	g_data->cy->id = 0;
	g_data->tr->next = NULL;
	g_data->tr->id = 0;
	g_data->obj = "";
	g_data->ratio_tran = 0;
	g_data->ratio_spec = 0;
	g_data->im->id = 0;
	g_data->im->next = NULL;
}
