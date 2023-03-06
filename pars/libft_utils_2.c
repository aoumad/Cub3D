/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoumad <aoumad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:54:36 by aoumad            #+#    #+#             */
/*   Updated: 2023/03/06 18:09:38 by aoumad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	ft_isin(const char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (1);
		s++;
	}
	return (0);
}

static int	get_last_index(char const *s1, char const *set)
{
	int	len;

	len = ft_strlen(s1);
	while (--len >= 0)
		if (!ft_isin(set, s1[len]))
			break ;
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s_trimed;
	int		last;
	int		j;

	if (!s1 || !set)
		return (NULL);
	last = get_last_index(s1, set);
	if (0 >= last)
	{
		s_trimed = (char *)malloc(sizeof(char));
		if (!s_trimed)
			return (NULL);
		s_trimed[0] = 0;
		return (s_trimed);
	}
	else
		s_trimed = (char *)malloc(sizeof(char) * (last + 2));
	if (!s_trimed)
		return (NULL);
	j = 0;
	ft_strlcpy(s_trimed, s1, last + 2);
	return (s_trimed);
}

size_t	ft_strlcpy(char *dest, char const *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
