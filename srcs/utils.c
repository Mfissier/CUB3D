/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:47:31 by mafissie          #+#    #+#             */
/*   Updated: 2023/01/13 18:48:10 by mafissie         ###   ########.fr       */
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

size_t	take_len_x(char **map, size_t start)
{
	size_t	count;
	size_t	y;
	size_t	x;

	y = start;
	x = 0;
	count = 0;
	while (map[y])
	{
		while (map[y][x++])
			;
		if (x > count)
			count = x;
		x = 0;
		y++;
	}
	return (count);
}

int	take_len_y(char **map, int start)
{
	int	y;

	y = start - 1;
	while (map[++y])
		;
	return (y);
}

char	**create_map_check(char **map, int start)
{
	char	**sstr;
	int		y;
	int		x;
	int		i;

	sstr = NULL;
	y = start;
	x = take_len_x(map, start);
	i = -1;
	if (y && x)
	{
		sstr = ft_calloc(sizeof(sstr), (take_len_y(map, start) + 2));
		if (sstr == NULL)
			send_error_exit("Malloc failed !");
		while (++i < y)
		{
			sstr[i] = ft_calloc(sizeof(*sstr), (x + 2));
			if (sstr[i] == NULL)
				send_error_exit("Malloc failed !");
		}
		sstr[i] = NULL;
	}
	return (sstr);
}

void	fill_map_check(char **map, char ***sstr, size_t x, int start)
{
	size_t	j;
	size_t	i;
	char	**tmp;
	int		check;
	int		new_y;
	int 	new_x;

	if (start)
		check = 0;
	else
		check = 1;
	j = start - 1;
	i = -1;
	tmp = *sstr;
	new_y = 0;
	new_x = 0;
	while (map[++j])
	{
		while (++i < x)
		{
			if (check)
			{
				if (i < ft_strlen(map[j]))
					tmp[j][i] = map[j][i];
				else
					tmp[j][i] = ' ';
			}
			else
			{
				if (i < ft_strlen(map[j]))
					tmp[new_y][new_x] = map[j][i];
				else
					tmp[new_y][new_x] = ' ';
				new_x++;
			}
		}
		new_x = 0;
		new_y++;
		i = -1;
	}
}
// ADD FREE FOR sstr[i] failed malloc
