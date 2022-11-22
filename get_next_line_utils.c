/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:56:48 by ayagmur           #+#    #+#             */
/*   Updated: 2022/11/20 12:56:49 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(const char *str, int strchar)
{
	int	i;

	i = 0;
	if (((char)strchar) == 0 || !str)
		return (0);
	while (str[i])
	{
		if (str[i] == ((char)(strchar)))
			return (i);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	if (c == 0)
		return (0);
	while (c[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*c;

	c = malloc(count * size);
	if (c == NULL)
		return (0);
	ft_memset(c, '\0', count * size);
	return (((char *)c));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		x;
	char	*dst;

	if (!s1)
		s1 = ft_calloc(1, 1);
	i = ft_strlen(((char *)s1)) + ft_strlen(((char *)s2));
	x = 0;
	dst = (char *) malloc((i + 1) * sizeof(char));
	if (dst == NULL)
		return (0);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
		x++;
	}
	i = 0;
	while (s2[i])
	{
		dst[x] = s2[i];
		i++;
		x++;
	}
	dst[x] = '\0';
	return (dst);
}

void	*ft_memset(void *pointer, int value, size_t size)
{
	int	i;

	i = 0;
	while (size > 0)
	{
		((unsigned char *) pointer)[i++] = (unsigned char) value;
		size--;
	}
	return (pointer);
}
