/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_lng.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 19:54:35 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/15 19:53:41 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			get_size(unsigned long long n)
{
	unsigned int		size;

	size = 0;
	while (n >= 10)
	{
		n /= 10;
		++size;
	}
	return (size + 1);
}

char				*ft_itoa_lng(long long n)
{
	char				*res;
	int					size;
	int					index;
	unsigned long long	nb;

	if (n < 0)
		nb = (unsigned long long)-n;
	else
		nb = (unsigned long long)n;
	size = get_size(nb);
	index = 0;
	if (!(res = (char *)malloc(sizeof(char) * size + 1 + (n < 0 ? 1 : 0))))
		return (NULL);
	if (n < 0 && (res[index] = '-'))
		size++;
	index = size - 1;
	while (nb >= 10)
	{
		res[index--] = (char)(nb % 10 + 48);
		nb /= 10;
	}
	res[index] = (char)(nb % 10 + 48);
	res[size] = '\0';
	return (res);
}
