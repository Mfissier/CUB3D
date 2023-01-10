/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:50:38 by mafissie          #+#    #+#             */
/*   Updated: 2022/05/25 19:14:10 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_malloc(char **str, int size)
{
	*str = malloc(sizeof(char) * size + 1);
	if (*str == NULL)
		return (-1);
	**str = 0;
	return (1);
}

size_t	ft_bslash(const char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

int	ft_read(char **line, int fd)
{
	char	*buff;
	int		size;

	if (fd < 0)
		return (-1);
	if (ft_malloc(&buff, (32 + 1)) == -1)
		return (-1);
	size = 1;
	while (size)
	{
		size = read(fd, buff, 32);
		if (size == -1)
			return (free(buff), -1);
		buff[size] = 0;
		*line = ft_strjoin(*line, buff);
		if (*line == NULL)
			return (free(buff), -1);
		if (ft_strchr(*line, '\n'))
			break ;
	}
	return (free(buff), 1);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	char		*str;

	if (ft_malloc(&str, 1) == -1)
		return (NULL);
	if (read(fd, str, 0) < 0 || fd < 0)
		return (free(str), NULL);
	if (!save)
		if (ft_malloc(&save, 1) == -1)
			return (free(str), NULL);
	str = ft_strjoin(str, save);
	if (str == NULL)
		return (free(save), NULL);
	free(save);
	if (ft_read(&str, fd) == -1 || fd < 0)
		return (free(str), NULL);
	save = ft_substr(str, ft_bslash(str) + 1, ft_strlen(str));
	if (save == NULL)
		return (free(str), NULL);
	line = ft_substr(str, 0, ft_bslash(str) + 1);
	if (line == NULL)
		return (free(save), NULL);
	return (free(str), line);
}
