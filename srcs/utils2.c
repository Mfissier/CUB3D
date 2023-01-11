/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:50:12 by mafissie          #+#    #+#             */
/*   Updated: 2023/01/11 18:57:45 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
