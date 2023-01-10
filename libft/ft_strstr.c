/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:27:28 by mafissie          #+#    #+#             */
/*   Updated: 2022/01/20 16:06:53 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!*to_find)
		return (str);
	while (str[i])
	{
		if (str[i] == to_find[j])
		{
			while (str[i] && str[i] == to_find[j])
			{
				if (!to_find[j + 1])
					return (&str[i - j]);
				i++;
				j++;
			}
			i -= j;
			j = 0;
		}
		i++;
	}
	return (NULL);
}
