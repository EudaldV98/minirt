/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:46:48 by jvaquer           #+#    #+#             */
/*   Updated: 2019/11/20 17:47:11 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_atod(char *s)
{
	double	nb;
	int		div;
	double	temp;
	int		i;
	int		neg;

	i = 0;
	nb = 0;
	neg = 1;
	div = 1;
	if (s[i] == '-' || s[i] == '+')
		neg = (s[i++] == '-') ? -1 : 1;
	while ((s[i] <= '9' && s[i] >= '0'))
		nb = nb * 10 + (s[i++] - '0');
	if (s[i] != '.')
		return (nb * neg);
	i++;
	temp = 0.1;
	while (s[i] >= '0' && s[i] <= '9')
	{
		nb = nb + ((s[i++] - '0') * temp);
		temp /= 10;
	}
	return (nb * neg);
}
