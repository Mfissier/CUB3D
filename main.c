/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:03:16 by mafissie          #+#    #+#             */
/*   Updated: 2023/01/16 10:05:58 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	int		fd;
	char	*str;
	char	**sstr;
	t_args	args;

	if (ac != 2)
		send_error_exit("Need 2 args for exec cub3d !\n");
	init_list_args(&args);
	check_file(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		send_error_exit("Failed open file !\n");
	str = read_file(fd);
	sstr = ft_split(str, '\n');
	if (str == NULL || sstr == NULL)
		send_error_exit("Malloc Failed \n");
	free(str);
	str = NULL;
	parse_texture(sstr, &args);
	take_map(&sstr, &args);
	free_all(&sstr, &args, &str);
	return (0);
}
