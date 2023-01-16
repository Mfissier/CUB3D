/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:05:58 by mafissie          #+#    #+#             */
/*   Updated: 2023/01/16 10:47:21 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	fill_take_map(char **map, char ***sstr, size_t x, size_t y)
{
	size_t	j;
	size_t	i;
	size_t  index;
	char	**tmp;

	j = y;
	i = 0;
	index = 0;
	tmp = *sstr;
	while (map[j])
	{
		while (i < x)
		{
			if (i < ft_strlen(map[j]))
				tmp[index][i] = map[j][i];
			else
				tmp[index][i] = ' ';
			i++;
		}
		j++;
		tmp[index][i] = '\0';
		index++;
		i = 0;
	}
	tmp[index] = NULL;
}

char	**create_take_map(char **map, t_args *args)
{
	char	**sstr;
	int		y;
	int		x;
	int		i;

	sstr = NULL;
	y = take_len_y(map) - check_rules_order(map, args);
	x = take_len_x(map);
	i = -1;
	if (y && x)
	{
		sstr = ft_calloc(sizeof(sstr), (take_len_y(map) + 2));
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

int	check_player_and_clean_map(char ***t_map)
{
	int		i;
	int		j;
	int		check_player;
	char	**map;

	i = -1;
	j = -1;
	check_player = 0;
	map = *t_map;
	while (map[++j])
	{
		while (map[j][++i])
		{
			if (map[j][i] == 'N' || map[j][i] == 'S'
					|| map[j][i] == 'E' || map[j][i] == 'W')
			{
				map[j][i] = '0';
				check_player++;
			}
		}
		i = -1;
	}
	if (check_player == 0 || check_player > 1)
		return (-1);
	return (1);
}

void	take_map(char ***map, t_args *args)
{
	char	**t_map;

	t_map = NULL;
	t_map = create_take_map(*map, args);
	fill_take_map(*map, &t_map, take_len_x(*map), \
			check_rules_order(*map, args));
	if (check_player_and_clean_map(&t_map) == -1)
	{
		free_sstr(*map);
		free_sstr(t_map);
		free_args(args);
		send_error_exit("Player location is bad !\n");
	}
	if (check_wall(t_map) == -1)
	{
		free_sstr(*map);
		free_sstr(t_map);
		free_args(args);
		send_error_exit("Map is incorrect !\n");
	}
	display_map(t_map);
	free_sstr(t_map);
}
