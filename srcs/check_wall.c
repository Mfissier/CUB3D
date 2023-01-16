/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:11:30 by mafissie          #+#    #+#             */
/*   Updated: 2023/01/16 11:32:45 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_outline(char **map)
{
	size_t	i;
	int		j;

	i = 0;
	j = -1;
	while (map[++j])
	{
		while (map[j][i])
		{
			if (i == 0 && map[j][i] == '0')
				return (-1);
			if (i == ft_strlen(map[j]) && map[j][i] == '0')
				return (-1);
			if (j == 0 && map[j][i] == '0')
				return (-1);
			if (j == take_len_y(map) && map[j][i] == '0')
				return (-1);
			i++;
		}
		i = 0;
	}
	return (1);
}

int	check_wall(char **map)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (check_outline(map) == -1)
		return (-1);
	while (map[++j])
	{
		while (map[j][++i])
		{
			if (map[j][i] == '0')
			{
				if (map[j][i] == '0'
					&& ((map[j][i + 1] != '1' && map[j][i + 1] != '0')
					|| (map[j][i - 1] != '1' && map[j][i - 1] != '0')
					|| (map[j + 1][i] != '1' && map[j + 1][i] != '0')
					|| (map[j - 1][i] != '1' && map[j - 1][i] != '0')))
					return (-1);
			}
		}
		i = -1;
	}
	return (1);
}
