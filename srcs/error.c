/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:09:52 by mafissie          #+#    #+#             */
/*   Updated: 2023/01/11 19:13:32 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	send_error_exit(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	exit(2);
}

int	is_err_map_args(char **map)
{
	(void)map;
	return (0);
}

int	is_err_map_wall(char **map)
{
	char	**sstr;

	sstr = NULL;
	sstr = create_map_check(map);
	fill_map_check(map, &sstr, take_len_x(map));
	printf("map start :\n");
	display_map(map);
	printf("\n");
	printf("map check :\n");
	display_map(sstr);
	if (sstr == NULL)
		send_error_exit("Malloc failed !");
	(void)map;
	return (0);
}

/*
 * 111111111.
 * .1xxxxxxx1
 * 1.1xx1111
 * 111111
 *
 */
