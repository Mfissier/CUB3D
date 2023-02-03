/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:46:39 by mafissie          #+#    #+#             */
/*   Updated: 2023/02/03 19:43:50 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_close_with_mouse(t_window *win)
{
	destroy_event_exit(win);
	exit(0);
}

int	event_handler(int keycode, t_window *win)
{
	if (keycode == ESC)
	{
		destroy_event_exit(win);
		exit(0);
	}
	else if (keycode == A_KEY)
		printf("press A_KEY");
	else if (keycode == W_KEY)
		printf("press W_KEY");
	else if (keycode == S_KEY)
		printf("press S_KEY");
	else if (keycode == D_KEY)
		printf("press D_KEY");
	return (0);
}

t_window	init_data_cub(t_args *args, char **nmap)
{
	t_window	win;

	win.args = args;
	win.mlx = NULL;
	win.pwin = NULL;
	win.mlx = mlx_init();
	if (!win.mlx)
	{
		free_args(args);
		free_sstr(nmap);
		send_error_exit("Init mlx failed !\n");
	}
	if (!init_img(&win))
	{
		free_args(args);
		free_sstr(nmap);
		mlx_destroy_display(win.mlx);
		free(win.mlx);
		send_error_exit("Init img failed !\n");
	}
	win.map = nmap;
	return (win);
}

void	cub(char **map, t_args *args)
{
	t_window	win;
	int			size_x;
	int			size_y;

	(void)args;
	display_map(map);
	win = init_data_cub(args, map);
	mlx_get_screen_size(win.mlx, &size_x, &size_y);
	win.pwin = mlx_new_window(win.mlx, size_x, size_y, \
	"cub3d");
	mlx_hook(win.pwin, 2, 1L << 0, event_handler, &win);
	mlx_hook(win.pwin, 17, 1L << 0, event_handler, &win);
	mlx_loop(win.mlx);
}
