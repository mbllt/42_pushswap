/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seperate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 17:40:42 by mballet           #+#    #+#             */
/*   Updated: 2021/09/08 11:48:24 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	push_on_a_or_b(t_list_int **actual, t_list_int **other,
		t_global *global, int stack)
{
	while (++global->i < global->nbr_sort)
	{
		if (*(global->tmp->content) < global->median
			&& (stack == 0 || stack == 2))
		{
			while (*(global->tmp->content) != *((*actual)->content))
				if (++global->nbr && !rotate(actual, global, stack))
					return (-1);
			if (!push(other, actual, global, stack))
				return (-1);
		}
		else if (*(global->tmp->content) > global->median
			&& (stack == 1 || stack == 3))
		{
			while (*(global->tmp->content) != *((*actual)->content))
				if (++global->nbr && !rotate(actual, global, stack))
					return (-1);
			if (!push(other, actual, global, stack))
				return (-1);
		}
		global->tmp = global->tmp->next;
	}
	return (global->nbr);
}

int	seperate(t_list_int **actual, t_list_int **other,
		t_global *global, int stack)
{
	int	i;
	int	save_size;
	int	nbr;

	i = 0;
	save_size = ft_lstsize_int(*actual);
	global->i = -1;
	global->nbr = 0;
	global->tmp = *actual;
	nbr = push_on_a_or_b(actual, other, global, stack);
	if (nbr == -1)
		return (0);
	i = 0;
	if (save_size != global->nbr_sort)
	{
		while (i < nbr)
		{
			if (!rev_rotate(actual, global, stack))
				return (0);
			i++;
		}
	}
	return (1);
}
