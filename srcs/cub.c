#include "../cub3d.h"
#include "../minilibx-linux/mlx.h"

int	ft_close_with_mouse(t_window *win)
{
	mlx_destroy_window(win->mlx, win->pwin);
	mlx_destroy_display(win->mlx);
	free(win->mlx);
	exit(0);
	return (0);
}

int	event_handler(int keycode, t_window *win)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(win->mlx, win->pwin);
		mlx_destroy_display(win->mlx);
		free(win->mlx);
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

void	cub(char **map, t_args *args)
{
	t_window	win;

	(void)args;
	display_map(map);
	// modify map.cub for good test
	// init_win with *->args (with norm)
	// teste if open img.xpm || ERROR ?
	// display img with window
	// Add all hook with valgrind testing
	// take and init all data
	// raycasting
	// testing
	// convert img 2D to 3D
	/* ft_fill_img_data(&win, win.map); */
	win.mlx = NULL;
	win.pwin = NULL;
	win.mlx = mlx_init();
	win.pwin = mlx_new_window(win.mlx, WIN_LENW, WIN_LENH, \
	"cub3d");
	mlx_hook(win.pwin, 2, 1L << 0, event_handler, &win);
	mlx_hook(win.pwin, 17, 1L << 0, event_handler, &win);
	mlx_loop(win.mlx);
}
