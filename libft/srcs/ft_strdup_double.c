/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:38:32 by mballet           #+#    #+#             */
/*   Updated: 2021/09/08 15:55:57 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strdup_double(char **str, int size)
{
	char	**tab;
	int		i;
	int		j;

	tab = malloc(sizeof(char *) * size);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < size)
	{
		tab[i] = NULL;
		tab[i] = (char *)malloc(sizeof(char) * (ft_strlen(str[i]) + 1));
		if (!(tab[i]))
			return (NULL);
		j = 0;
		while (str[i][j])
		{
			tab[i][j] = str[i][j];
			j++;
		}
		tab[i][j] = '\0';
		i++;
	}
	return (tab);
}
