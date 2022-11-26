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

static char	*next_line(char *tmp, int i)
{
	int		j;
	char	*line;

	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (!tmp[i])
	{
		free(tmp);
		return (0);
	}
	//to cqlloc
	line = malloc(sizeof(char) * ((ft_strlen(tmp) - i) + 1));
	i++;
	j = 0;
	while (tmp[i])
		line[j++] = tmp[i++];
	//printf("j : %d", i);
	//printf("/-%s, %s-/\n", line, tmp);
	free(tmp);
	return (line);
}

static char	*read_file(int fd, char *tmp)
{
	char	*buffer;
	int		read_ret;

	if (!tmp)
		tmp = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	read_ret = 1;
	while (read_ret > 0)
	{
		read_ret = read(fd, buffer, BUFFER_SIZE);
		if (read_ret < 0)
		{
			free(tmp);
			free(buffer);
			return (0);
		}
		buffer[read_ret] = '\0';
		tmp = ft_strjoin(tmp, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (tmp);
}

static char	*get_line(char *line, char *tmp, int i)
{
	if (!tmp)
		return (0);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	i = 0;
	while(tmp[i] && tmp[i] != '\n')
	{
		line[i] = tmp[i];
		i++;
	}
	//ck
	line[i] = '\n';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*tmp = 0;
	char		*line;
	int			i;

	line = 0;
	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	tmp = read_file(fd, tmp);
	if (!tmp)
		return (NULL);
	line = get_line(line, tmp, i);
	tmp = next_line(tmp, i);
	i = 0;
	//printf("line = %s, tmp = %s\n", line, tmp);
	return (line);
}

int main()
{
	int fd = open("file", O_RDWR);
	//get_next_line(fd);
	//get_next_line(fd);
	//get_next_line(fd);
	printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
	//printf("%s", get_next_line(fd));
	//printf("result = %s", get_next_line(fd));

}
