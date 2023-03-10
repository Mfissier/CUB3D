/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 07:28:19 by mafissie          #+#    #+#             */
/*   Updated: 2023/01/13 11:27:01 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{	
	char	*new_str;

	if (s == NULL)
		return (NULL);
	new_str = ft_calloc(sizeof(char), (ft_strlen(s) + 1));
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, s, ft_strlen(s) + 1);
	return (new_str);
}
