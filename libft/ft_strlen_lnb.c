/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_lnb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:49:12 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/09 19:56:15 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlen_lnb(long long nb)
{
	char	*lnb;
	int		size;

	lnb = ft_itoa_lng(nb);
	size = ft_strlen(lnb);
	free(lnb);
	return (size);
}
