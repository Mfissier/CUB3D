/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 23:39:52 by mafissie          #+#    #+#             */
/*   Updated: 2023/01/10 11:35:37 by mafissie         ###   ########.fr       */
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
# include "minilibx-linux/mlx.h"

# define EVENT_KEY_PRESS	2
# define EVENT_KEY_EXIT		17
# define A_KEY		97
# define W_KEY		119
# define S_KEY		115
# define D_KEY		100
# define ESC		65307

// CHECK ERROR
int		is_err_map_args(char **map);
int		is_err_map_wall(char **map);
void	send_error_exit(char *str);

// utils.c
void	display_map(char **map);
int		take_len_y(char **map);
int		take_len_x(char **map);
char	**create_map_check(char **map);
void	fill_map_check(char **map, char ***sstr, size_t x);

#endif
