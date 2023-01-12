/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:03:16 by mafissie          #+#    #+#             */
/*   Updated: 2023/01/12 18:39:54 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	int		fd;
	char	*str;
	char	**sstr;
	int		i;
	t_args	args;

	init_list_args(&args);
	i = 0;
	sstr = NULL;
	str = NULL;
	fd = open(av[1], O_RDONLY);
	str = read_file(fd);
	sstr = ft_split(str, '\n');
	if (str == NULL || sstr == NULL)
		send_error_exit("Malloc Failed \n");
	while (sstr[i])
		printf("%s\n", sstr[i++]);
	free(str);
	if (parse_texture(sstr, &args) == -1)
	{
		free_sstr(sstr);
		send_error_exit("Rules in the wrong order\n");
	}
	free_sstr(sstr);
	free_args(&args);
	(void)ac;
	(void)av;
	(void)sstr;
	return (0);
}
