/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:30:53 by jvaquer           #+#    #+#             */
/*   Updated: 2020/01/23 19:38:11 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;
	int				res;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		res = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (res != 0)
			return (res);
		i++;
	}
	return (0);
}
