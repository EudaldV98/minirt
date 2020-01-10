/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlennb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:33:17 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/19 15:14:52 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlennb(int nb)
{
	char	*lnb;
	int		size;

	lnb = ft_itoa(nb);
	size = ft_strlen(lnb);
	free(lnb);
	return (size);
}
