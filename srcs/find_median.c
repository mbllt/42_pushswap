/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 17:40:27 by mballet           #+#    #+#             */
/*   Updated: 2021/09/08 13:11:12 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	fill_in_str(t_list_int *actual, int **str, int nbr_sorting)
{
	t_list_int	*tmp;
	int			i;

	tmp = actual;
	i = 0;
	while (i < nbr_sorting)
	{
		(*str)[i] = *(tmp->content);
		tmp = tmp->next;
		i++;
	}
	(*str)[i] = 0;
}

static int	sort_str(int **str, int nbr_sorting)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < nbr_sorting)
	{
		j = i + 1;
		while (j < nbr_sorting)
		{
			if ((*str)[i] > (*str)[j])
			{
				tmp = (*str)[i];
				(*str)[i] = (*str)[j];
				(*str)[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	find_median(t_list_int *actual, t_global *global, int stack)
{
	int	size;
	int	nbr;

	fill_in_str(actual, &global->str, global->nbr_sort);
	if (!(sort_str(&global->str, global->nbr_sort)))
		return (0);
	size = global->nbr_sort;
	if (!(stack % 2))
		nbr = size / 2 + 1;
	else
		nbr = size / 2 + size % 2;
	global->median = global->str[nbr - 1];
	return (1);
}
