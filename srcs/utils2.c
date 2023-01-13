/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:50:12 by mafissie          #+#    #+#             */
/*   Updated: 2023/01/13 12:02:00 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_file(char *str)
{
	int	fd;

	if (str == NULL)
		send_error_exit("Error name file !\n");
	if ((ft_strlen(str) == 4) && ft_strnstr(str, ".cub", ft_strlen(str)))
		send_error_exit("Is .cub, juste need name for win !\n");
	if (ft_strlen(str) < 4)
		send_error_exit("Name map incorrect !\n");
	if (ft_strlen(str) > 4 && (str[ft_strlen(str) - 1] != 'b'
			|| str[ft_strlen(str) - 2] != 'u'
			|| str[ft_strlen(str) - 3] != 'c'
			|| str[ft_strlen(str) - 4] != '.'))
		send_error_exit("Name map incorrect !\n");
	fd = open(str, O_DIRECTORY);
	if (fd < 0)
		return ;
	close(fd);
	send_error_exit("File is a directory !\n");
}

char	*read_file(int fd)
{
	char	*str;
	char	*tmp;
	char	buff[5];
	int		size;	

	str = NULL;
	tmp = NULL;
	if (fd < 0)
		send_error_exit("Error open files !\n");
	size = read(fd, buff, 5);
	buff[size] = '\0';
	str = ft_strdup(buff);
	while (size)
	{
		size = read(fd, buff, 5);
		if (!size)
			break ;
		buff[size] = '\0';
		tmp = ft_strjoin(str, buff);
		str = ft_strdup(tmp);
		free(tmp);
	}
	close(fd);
	return (str);
}
