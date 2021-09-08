/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_six.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:54:09 by mballet           #+#    #+#             */
/*   Updated: 2021/09/08 13:03:00 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	big_in_front(t_list_int **actual, t_global *global, int stack)
{
	if (!rev_rotate(actual, global, stack))
		return (0);
	if (!swap(actual, global, stack))
		return (0);
	return (1);
}

static int	medium_in_front(t_list_int **actual,
			t_global *global, int stack, int big)

{
	if (big == *((*actual)->next->content))
	{
		if (!swap(actual, global, stack))
			return (0);
	}
	else
	{
		if (!rev_rotate(actual, global, stack))
			return (0);
	}
	return (1);
}

static int	small_in_front(t_list_int **actual,
			t_global *global, int stack, int big)
{
	if (big == *((*actual)->next->content))
	{
		if (!rotate(actual, global, stack))
			return (0);
	}
	else
	{
		if (!swap(actual, global, stack))
			return (0);
		if (!rev_rotate(actual, global, stack))
			return (0);
	}
	return (1);
}

int	sort_b_six(int nbr_sorting, t_list_int **actual,
	t_global *global, int stack)
{
	long int	big;
	long int	small;

	if (nbr_sorting == 2)
	{
		if (*((*actual)->content) < *((*actual)->next->content))
			if (!swap(actual, global, stack))
				return (0);
		return (1);
	}
	if (!is_sorted_b_to_s(*actual, nbr_sorting))
	{
		big = find_biggest(*actual);
		small = find_smallest(*actual);
		if (big == *((*actual)->content)
			&& !(big_in_front(actual, global, stack)))
			return (0);
		if (big != *((*actual)->content) && small != *((*actual)->content)
			&& !(medium_in_front(actual, global, stack, big)))
			return (0);
		if (small == *((*actual)->content)
			&& !(small_in_front(actual, global, stack, big)))
			return (0);
	}
	return (1);
}
