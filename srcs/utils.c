/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:47:31 by mafissie          #+#    #+#             */
/*   Updated: 2023/01/10 11:47:53 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	display_map(char **map)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	while (map[++y])
	{
		while (map[y][++x])
			printf("%c", map[y][x]);
		printf("\n");
		x = -1;
	}
}

int	take_len_x(char **map)
{
	int	count;
	int	y;
	int	x;

	y = -1;
	x = -1;
	count = 0;
	while (map[++y])
	{
		while (map[y][++x])
			;
		if (x > count)
			count = x;
		x = -1;
	}
	return (count);
}

int	take_len_y(char **map)
{
	int	y;

	y = -1;
	while (map[++y])
		;
	return (y);
}

char	**create_map_check(char **map)
{
	char	**sstr;
	int		y;
	int		x;
	int		i;

	sstr = NULL;
	y = take_len_y(map);
	x = take_len_x(map);
	i = -1;
	if (y && x)
	{
		sstr = ft_calloc(sizeof(sstr), (take_len_y(map) + 1));
		if (sstr == NULL)
			send_error_exit("Malloc failed !");
		while (++i < y)
		{
			sstr[i] = ft_calloc(sizeof(*sstr), (x + 1));
			if (sstr[i] == NULL)
				send_error_exit("Malloc failed !");
		}
		sstr[i] = NULL;
	}
	return (sstr);
}

void	fill_map_check(char **map, char ***sstr, size_t x)
{
	size_t	j;
	size_t	i;
	char	**tmp;

	j = -1;
	i = -1;
	tmp = *sstr;
	while (map[++j])
	{
		while (++i < x)
		{
			if (i < ft_strlen(map[j]))
				tmp[j][i] = map[j][i];
			else
				tmp[j][i] = ' ';
		}
		tmp[j][i] = '\0';
		i = -1;
	}
}
// ADD FREE FOR sstr[i] failed malloc
