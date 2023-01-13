/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:05:58 by mafissie          #+#    #+#             */
/*   Updated: 2023/01/13 18:23:56 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	take_map(char ***map, t_args *args)
{
	char	**t_map;
	int		y;

	t_map = NULL;
	(void)t_map;
	y = check_rules_order(*map, args);
	t_map = create_map_check(*map, y);
	fill_map_check(*map, &t_map, take_len_x(*map, y), y);
	display_map(t_map);
}
