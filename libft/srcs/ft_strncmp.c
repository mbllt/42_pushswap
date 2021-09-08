/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:53:15 by mballet           #+#    #+#             */
/*   Updated: 2021/09/08 15:48:22 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	if (n <= 0)
		return (0);
	while (ss1[i] == ss2[i] && ss1[i] != '\0' && ss2[i] != '\0' && i < (n - 1))
		i++;
	if (ss1[i] > ss2[i])
		return ((unsigned char)ss1[i] - (unsigned char)ss2[i]);
	if (ss1[i] < ss2[i])
		return (-1);
	else
		return (0);
}
