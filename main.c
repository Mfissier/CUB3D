/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:03:16 by mafissie          #+#    #+#             */
/*   Updated: 2023/01/11 19:27:12 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	int		fd;
	char	*str;
	char	**sstr;
	int		i;

	i = 0;
	sstr = NULL;
	fd = open(av[1], O_RDONLY);
	str = read_file(fd);
	sstr = ft_split(str, '\n');
	if (str == NULL || sstr == NULL)
		send_error_exit("Malloc Failed \n");
	while (sstr[i])
		printf("%s\n", sstr[i++]);
	free_sstr(sstr);
	is_err_map_wall(av + 1);
	free(str);
	(void)ac;
	(void)av;
	(void)sstr;
	return (0);
}
