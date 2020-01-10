/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 20:48:35 by jvaquer           #+#    #+#             */
/*   Updated: 2019/10/24 21:23:23 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			get_size(unsigned int num)
{
	unsigned int	size;

	size = 0;
	while (num >= 10)
	{
		num /= 10;
		++size;
	}
	return (size + 1);
}

char				*ft_itoa(long n)
{
	char			*res;
	int				size;
	int				i;
	unsigned int	num;

	if (n < 0)
		num = (unsigned int)-n;
	else
		num = (unsigned int)n;
	size = get_size(num);
	i = 0;
	if (!(res = (char *)malloc(sizeof(char) * size + 1 + (n < 0 ? 1 : 0))))
		return (NULL);
	if (n < 0 && (res[i] = '-'))
		size++;
	i = size - 1;
	while (num >= 10)
	{
		res[i--] = (char)(num % 10 + 48);
		num /= 10;
	}
	res[i] = (char)(num % 10 + 48);
	res[size] = '\0';
	return (res);
}
