/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:01:03 by jvaquer           #+#    #+#             */
/*   Updated: 2019/10/08 17:47:48 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char		*psrc;
	char			*pdst;

	psrc = src;
	pdst = dst;
	if (!len)
		return (dst);
	if (dst <= src)
		return (ft_memcpy(dst, src, len));
	psrc += len;
	pdst += len;
	while (len > 0)
	{
		*--pdst = *--psrc;
		len--;
	}
	return (dst);
}
