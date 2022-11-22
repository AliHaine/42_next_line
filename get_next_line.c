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

int	size(char *tmp)
{
	int 	i;

	i = 0;
	while(tmp[i] != '\n')
		i++;
	return (i);
}

char *get_line(char *line, char *tmp)
{
	int 	i;

	i = 0;
	while(tmp[i] != '\n')
		i++;
	//line[i + 1] = '\n';
	while(i > 0)
	{
		line[i] = tmp[i];
		i--;
	}
	line[i] = tmp[i];
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*tmp = 0;
	char	*buffer[BUFFER_SIZE + 1];
	char	*line;
	int i;

	i = 0;
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (0);
	while (ft_strchr(tmp, '\n') == 0)
	{
		read(fd, &buffer, BUFFER_SIZE);
		tmp = ft_strjoin(tmp, (((char *)buffer) + i));
	}
	line = malloc(sizeof(char) * size(tmp));
	line = get_line(line, tmp);
	return (line);
	//return (tmp);
}

int main()
{
	int fd = open("file", O_RDWR);
	printf("result = %s\n//", get_next_line(fd));
	//printf("result = %s\n", get_next_line(fd));
	//printf("%s", get_next_line(fd));
	//get_next_line(fd);*/

}
