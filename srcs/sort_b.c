/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:53:12 by mballet           #+#    #+#             */
/*   Updated: 2021/09/08 13:32:12 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

typedef struct s_big_small
{
	long int	big;
	long int	small;
}				t_big_small;

static int	sort_a_b(t_list_int **actual, t_global *global, int stack,
			t_big_small bs)
{
	if (bs.big == *((*actual)->next->content)
		&& bs.small == *((*actual)->next->next->content))
	{
		if (!swap(actual, global, stack))
			return (0);
		return (1);
	}
	if (bs.small == *((*actual)->content))
		if (!swap(actual, global, stack))
			return (0);
	if (!rotate(actual, global, stack))
		return (0);
	if (!swap(actual, global, stack))
		return (0);
	if (!rev_rotate(actual, global, stack))
		return (0);
	if (bs.big != *((*actual)->content))
		if (!swap(actual, global, stack))
			return (0);
	return (1);
}

int	sort_b(t_list_int **actual, t_global *global, int stack)
{
	t_big_small	bs;

	if (global->nbr_sort == 2)
	{
		if (*((*actual)->content) < *((*actual)->next->content))
			if (!swap(actual, global, stack))
				return (0);
		return (1);
	}
	if (!is_sorted_b_to_s(*actual, global->nbr_sort))
	{
		bs.big = find_biggest(*actual);
		bs.small = find_smallest(*actual);
		if (!sort_a_b(actual, global, stack, bs))
			return (0);
	}
	return (1);
}
