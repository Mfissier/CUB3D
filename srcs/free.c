/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:19:01 by mafissie          #+#    #+#             */
/*   Updated: 2023/01/12 18:38:53 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_sstr(char **sstr)
{
	int	i;

	i = 0;
	while (sstr[i])
	{
		free(sstr[i]);
		i++;
	}
	free(sstr);
}

void	free_args(t_args *args)
{
	if (args->map != NULL)
		free_sstr(args->map);
	free(args->path_no);
	free(args->path_so);
	free(args->path_we);
	free(args->path_ea);
}
