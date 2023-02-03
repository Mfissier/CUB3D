/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 19:04:27 by mafissie          #+#    #+#             */
/*   Updated: 2023/02/03 19:38:07 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	destroy_img(t_window *win, int check)
{
	int	i;

	i = 0;
	while (i < check)
	{
		mlx_destroy_image(win->mlx, win->graph[i].img);
		i++;
	}
	return (0);
}

void	destroy_event_exit(t_window *win)
{
	destroy_img(win, 4);
	mlx_destroy_window(win->mlx, win->pwin);
	mlx_destroy_display(win->mlx);
	free_sstr(win->map);
	free_args(win->args);
	free(win->mlx);
}
