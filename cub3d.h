/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 23:39:52 by mafissie          #+#    #+#             */
/*   Updated: 2023/02/03 19:45:24 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "minilibx-linux/mlx.h"

# define EVENT_KEY_PRESS	2
# define EVENT_KEY_EXIT		17
# define A_KEY		97
# define W_KEY		119
# define S_KEY		115
# define D_KEY		100
# define ESC		65307

# define WIN_LENW 1000
# define WIN_LENH 1000

typedef struct s_args
{
	int		f_rgb[3];
	int		c_rgb[3];
	char	*path_no;
	char	*path_so;
	char	*path_we;
	char	*path_ea;
	char	**map;
}				t_args;

typedef struct s_graph
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	// int				back;
	// int				left;
	// int				right;
	// int				rotate_left;
	// int				rotate_right;
	// int				minimapechelle;
	// void			*img2;
	// int				*addr2;
}				t_graph;

typedef struct s_window
{
	void		*mlx;
	void		*pwin;
	char		**map;
	t_args		*args;
	t_graph		graph[4];
}				t_window;
// CHECK ERROR
int		is_err_map_args(char **map);
int		is_err_map_wall(char **map);
void	send_error_exit(char *str);

// utils.c
void	display_map(char **map);
int		take_len_y(char **map);
size_t	take_len_x(char **map);
char	**create_map_check(char **map);
void	fill_map_check(char **map, char ***sstr, size_t x);

// utils2.c
void	check_file(char *str);
char	*read_file(int fd);

// free.c
void	free_sstr(char **sstr);
void	free_args(t_args *args);
void	free_all(char ***map, t_args *args, char **str);

// parse_texture.c
int		check_rules_order(char **map, t_args *args);
int		parse_texture(char **map, t_args *args);

// init.c
void	init_list_args(t_args *args);
int		init_img(t_window *win);

// mlx_destroy.c
int		destroy_img(t_window *win, int check);
void	destroy_event_exit(t_window *win);

// parse_map.c
void	take_map(char ***map, t_args *args);

// check_wall.c
int		check_wall(char **map);

// cub.c
void	cub(char **map, t_args *args);

#endif
