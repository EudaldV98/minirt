/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:44:13 by jvaquer           #+#    #+#             */
/*   Updated: 2019/10/21 21:22:08 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t dstsize)
{
	size_t		i;
	size_t		len_dst;

	len_dst = 0;
	while (dst[len_dst] && len_dst < dstsize)
		len_dst++;
	i = 0;
	while ((len_dst + i + 1) < dstsize && src[i])
	{
		dst[i + len_dst] = src[i];
		i++;
	}
	if (len_dst != dstsize)
		dst[i + len_dst] = '\0';
	return (len_dst + ft_strlen(src));
}
