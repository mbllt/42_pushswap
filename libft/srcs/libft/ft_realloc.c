/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:59:16 by mballet           #+#    #+#             */
/*   Updated: 2021/01/21 09:31:06 by mballet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc(char *str, size_t size)
{
	char	*str2;
	int		i;

	if (!str)
		return (NULL);
	str2 = malloc(sizeof(char) * size);
	if (!str2)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (size > 0 && str[i] != '\0')
	{
		str2[i] = str[i];
		size--;
		i++;
	}
	str2[i] = 0;
	free(str);
	return (str2);
}
