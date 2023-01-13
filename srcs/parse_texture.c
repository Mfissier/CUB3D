/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:06:22 by mafissie          #+#    #+#             */
/*   Updated: 2023/01/13 12:23:41 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	find_first_index_map(char **map)
{
	int	i;
	int	ref;

	i = -1;
	ref = -1;
	while (map[++i])
	{
		if (!ft_strnstr(map[i], "NO", ft_strlen(map[i]))
			&& !ft_strnstr(map[i], "SO", ft_strlen(map[i]))
			&& !ft_strnstr(map[i], "WE", ft_strlen(map[i]))
			&& !ft_strnstr(map[i], "EA", ft_strlen(map[i]))
			&& !ft_strnstr(map[i], "F", ft_strlen(map[i]))
			&& !ft_strnstr(map[i], "C", ft_strlen(map[i])))
		{
			ref = i;
			break ;
		}
	}
	return (ref);
}

int	check_rules_order(char **map, t_args *args)
{
	int	index_map;
	int	i;

	index_map = -1;
	i = -1;
	if (find_first_index_map(map) == -1)
	{
		free_args(args);
		free_sstr(map);
		send_error_exit("Map is false\n");
	}
	index_map = find_first_index_map(map);
	while (map[++i])
	{
		if (ft_strnstr(map[i], "NO", ft_strlen(map[i]))
			|| ft_strnstr(map[i], "SO", ft_strlen(map[i]))
			|| ft_strnstr(map[i], "WE", ft_strlen(map[i]))
			|| ft_strnstr(map[i], "EA", ft_strlen(map[i]))
			|| ft_strnstr(map[i], "F", ft_strlen(map[i]))
			|| ft_strnstr(map[i], "C", ft_strlen(map[i])))
			if (i > index_map)
				return (-1);
	}
	return (index_map);
}

char	*take_path_texture(char *str, t_args *args, int check)
{
	int		i;
	int		index_rgb;

	i = -1;
	index_rgb = 0;
	if (check == 1)
		return (ft_strtrim(str, " "));
	while (str[++i] && index_rgb <= 2)
	{
		if (ft_isdigit(str[i]))
		{
			if ((str[i] == '+' || str[i] == '-'))
				return (NULL);
			if (ft_atoi(str + i) > 255 || ft_atoi(str + i) < 0)
				return (NULL);
			if (check == 2)
				args->f_rgb[index_rgb++] = ft_atoi(str + i);
			else
				args->c_rgb[index_rgb++] = ft_atoi(str + i);
			while (str[i] && ft_isdigit(str[i]))
				i++;
		}
	}
	return (NULL);
}

void	check_data_texture(t_args *args, char **map)
{
	int	check;

	check = 1;
	if (args->f_rgb[0] < 0 || args->c_rgb[0] < 0)
		check = -1;
	else if (args->f_rgb[1] < 0 || args->c_rgb[1] < 0)
		check = -1;
	else if (args->f_rgb[2] < 0 || args->c_rgb[2] < 0)
		check = -1;
	else if (args->path_no == NULL)
		check = -1;
	else if (args->path_so == NULL)
		check = -1;
	else if (args->path_we == NULL)
		check = -1;
	else if (args->path_ea == NULL)
		check = -1;
	if (check == -1)
	{
		free_all(&map, args, NULL);
		send_error_exit("Arguments is empty or false\n");
	}
}

int	parse_texture(char **map, t_args *args)
{
	int		i;

	i = -1;
	if (check_rules_order(map, args) == -1)
		return (-1);
	while (map[++i])
	{
		if (ft_strnstr(map[i], "NO", 2))
			args->path_no = take_path_texture(map[i] + 2, args, 1);
		else if (ft_strnstr(map[i], "SO", 2))
			args->path_so = take_path_texture(map[i] + 2, args, 1);
		else if (ft_strnstr(map[i], "WE", 2))
			args->path_we = take_path_texture(map[i] + 2, args, 1);
		else if (ft_strnstr(map[i], "EA", 2))
			args->path_ea = take_path_texture(map[i] + 2, args, 1);
		else if (ft_strnstr(map[i], "F", 1))
			take_path_texture(map[i], args, 2);
		else if (ft_strnstr(map[i], "C", 1))
			take_path_texture(map[i], args, 3);
		else
			break ;
	}
	check_data_texture(args, map);
	return (0);
}
