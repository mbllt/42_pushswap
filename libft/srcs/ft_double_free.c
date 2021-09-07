/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:38:25 by mballet           #+#    #+#             */
/*   Updated: 2021/09/07 13:38:26 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_double_free(char **str, int size_first, int size_second)
{
	int	i;

	i = 0;
	while (i < size_first)
	{
		if (str[i])
			free(str[i]);
	}
	if (str)
		free(str);
	str = NULL;
}
