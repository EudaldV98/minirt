/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 11:11:25 by janeudaldva       #+#    #+#             */
/*   Updated: 2020/01/23 19:39:48 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	ft_print_error(int err)
{
	if (err == -1)
		write(STDERR_FILENO, ERROR_MEM, ft_strlen(ERROR_MEM));
	if (err == -2)
		write(STDERR_FILENO, ERROR_FILENAME, ft_strlen(ERROR_FILENAME));
	if (err == -3)
		write(STDERR_FILENO, ERROR_SCENE, ft_strlen(ERROR_SCENE));
	if (err == -4)
		write(STDERR_FILENO, ERROR_MLX, ft_strlen(ERROR_MLX));
	if (err == -5)
		write(STDERR_FILENO, ERROR_WINDOW, ft_strlen(ERROR_WINDOW));
	if (err == -6)
		write(STDERR_FILENO, ERROR_ARG, ft_strlen(ERROR_ARG));
	if (err == -7)
		write(STDERR_FILENO, ERROR_BMP, ft_strlen(ERROR_BMP));
	if (err == -8)
		write(STDERR_FILENO, ERROR_IMG, ft_strlen(ERROR_IMG));
	exit(err);
}
