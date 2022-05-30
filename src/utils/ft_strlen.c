/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:33:29 by jvaquer           #+#    #+#             */
/*   Updated: 2020/01/23 19:38:17 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		ft_strlen(const char *str)
{
	unsigned int	count;

	if (!str)
		return (0);
	count = 0;
	while (str[count])
	{
		count++;
	}
	return (count);
}
