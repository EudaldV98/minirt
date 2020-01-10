/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:20:58 by jvaquer           #+#    #+#             */
/*   Updated: 2019/10/17 11:28:57 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		is_set(const char *set, const char c)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char			*ft_strtrim(const char *s1, const char *set)
{
	int		i;
	int		start;
	int		end;
	char	*new;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (is_set(set, s1[i]) == 1 && s1[i])
		i++;
	start = i;
	while (s1[i])
		i++;
	if (i-- != start)
		while (is_set(set, s1[i]) == 1)
			i--;
	end = i + 1;
	if (!(new = malloc(sizeof(char) * (end - start + 1))))
		return (NULL);
	i = 0;
	while (end > start)
		new[i++] = s1[start++];
	new[i] = '\0';
	return (new);
}
