/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 09:36:40 by mballet           #+#    #+#             */
/*   Updated: 2021/09/08 14:53:58 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	trim_index_front(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (set[j] && s1[i])
	{
		if (s1[i] == set[j])
		{
			i++;
			j = -1;
		}
		j++;
	}
	return (i);
}

static int	trim_index_back(char const *s1, char const *set)
{
	int	len;
	int	j;

	len = ft_strlen(s1) - 1;
	j = 0;
	while (len >= 0 && set[j])
	{
		if (s1[len] == set[j])
		{
			len--;
			j = -1;
		}
		j++;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	unsigned int	i_front;
	size_t			i_back;

	if (!s1)
		return (NULL);
	i_front = (unsigned int)trim_index_front(s1, set);
	i_back = (size_t)trim_index_back(s1, set);
	str = NULL;
	str = ft_substr(s1, i_front, i_back - i_front + 1);
	return (str);
}
