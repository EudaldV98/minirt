/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:43:38 by jvaquer           #+#    #+#             */
/*   Updated: 2019/10/08 19:38:31 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char *c_val;

	c_val = 0;
	while (*s)
	{
		if (*s == c)
			c_val = (char *)s;
		s++;
	}
	if (c_val)
		return (c_val);
	if (c == '\0')
		return ((char*)s);
	return (0);
}
