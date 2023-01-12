/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:27:31 by mafissie          #+#    #+#             */
/*   Updated: 2023/01/12 18:30:38 by mafissie         ###   ########.fr       */
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
