/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayagmur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:56:38 by ayagmur           #+#    #+#             */
/*   Updated: 2022/11/20 12:56:39 by ayagmur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int get_line(int line, int fd)
{
	int c;
	int i;

	c = 0;
	i = 0;
	if (line == 0)
		return (fd);
	while (read(fd, &c, 1) == 1 /*&& i < BUFFER_SIZE*/)
	{
		//printf("oui");
		if (c == '\n')
		{
			i = 0;
			line--;
		}
		if (line == 0)
			break;
		i++;
	}
	return (fd);
}

char	*get_next_line(int fd)
{
	char lineStr[BUFFER_SIZE + 1];
	static int	line;
	int	i = 0;
	int c = 0;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (0);
	fd = get_line(line, fd);
	while (read(fd, &c, 1) == 1 && i < BUFFER_SIZE)
	{
		lineStr[i] = c;
		i++;
	}
	printf("%s\n", lineStr);
	line++;
	return (0);
}

int main()
{
	int fd = open("file", O_RDWR);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);

}
