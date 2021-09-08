/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:53:12 by mballet           #+#    #+#             */
/*   Updated: 2021/09/08 12:53:28 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	sort_b(t_list_int **actual, t_global *global, int stack)
{
	long int	big;
	long int	small;

	if (global->nbr_sort == 2)
	{
		if (*((*actual)->content) < *((*actual)->next->content))
			if (!swap(actual, global, stack))
				return (0);
		return (1);
	}
	if (!is_sorted_b_to_s(*actual, global->nbr_sort))
	{
		big = find_biggest(*actual);
		small = find_smallest(*actual);
		if (big == *((*actual)->next->content) && small == *((*actual)->next->next->content))
		{
			if (!swap(actual, global, stack))
				return (0);
			return (1);
		}
		if (small == *((*actual)->content))
			if (!swap(actual, global, stack))
				return (0);
		if (!rotate(actual, global, stack))
			return (0);
		if (!swap(actual, global, stack))
			return (0);
		if (!rev_rotate(actual, global, stack))
			return (0);
		if (big != *((*actual)->content))
			if (!swap(actual, global, stack))
				return (0);
	}
	return (1);
}