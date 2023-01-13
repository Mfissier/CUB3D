/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafissie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:16:51 by mafissie          #+#    #+#             */
/*   Updated: 2023/01/13 11:29:07 by mafissie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char		*str1;
	char		*str2;
	char		*strj;
	long int	i;

	str1 = (char *)s1;
	str2 = (char *)s2;
	if (s1 == NULL)
		return (NULL);
	i = 0;
	if (str2 == NULL)
		return (ft_strdup(str1));
	else if (str1 == NULL)
		return (ft_strdup(str2));
	strj = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (strj == NULL)
		return (NULL);
	while (*str1)
		strj[i++] = *(str1++);
	while (*str2)
		strj[i++] = *(str2++);
	strj[i] = '\0';
	free(s1);
	return (strj);
}
