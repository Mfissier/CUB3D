/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:27:31 by mafissie          #+#    #+#             */
/*   Updated: 2023/02/03 19:35:42 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_list_args(t_args *args)
{
	args->f_rgb[0] = -1;
	args->c_rgb[0] = -1;
	args->f_rgb[1] = -1;
	args->c_rgb[1] = -1;
	args->f_rgb[2] = -1;
	args->c_rgb[2] = -1;
	args->path_no = NULL;
	args->path_so = NULL;
	args->path_we = NULL;
	args->path_ea = NULL;
	args->map = NULL;
}

int	init_img(t_window *win)
{
	win->graph[0].img = NULL;
	win->graph[1].img = NULL;
	win->graph[2].img = NULL;
	win->graph[3].img = NULL;
	win->graph[0].img = mlx_xpm_file_to_image(win->mlx, win->args->path_no, \
			&(win->graph[0].width), &(win->graph[0].height));
	if (!(win->graph[0].img))
		return (0);
	win->graph[1].img = mlx_xpm_file_to_image(win->mlx, win->args->path_so, \
	&(win->graph[1].width), &(win->graph[1].height));
	if (!(win->graph[1].img))
		return (destroy_img(win, 1));
	win->graph[2].img = mlx_xpm_file_to_image(win->mlx, win->args->path_ea, \
	&(win->graph[2].width), &(win->graph[2].height));
	if (!(win->graph[2].img))
		return (destroy_img(win, 2));
	win->graph[3].img = mlx_xpm_file_to_image(win->mlx, win->args->path_we, \
	&(win->graph[3].width), &(win->graph[3].height));
	if (!(win->graph[3].img))
		return (destroy_img(win, 3));
	return (1);
}
