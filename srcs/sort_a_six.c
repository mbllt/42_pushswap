/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_six.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:53:42 by mballet           #+#    #+#             */
/*   Updated: 2021/09/08 13:12:25 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	small_in_front(t_list_int **actual, t_global *global, int stack)
{
	if (!rev_rotate(actual, global, stack))
		return (0);
	if (!swap(actual, global, stack))
		return (0);
	return (1);
}

static int	medium_in_front(t_list_int **actual,
			t_global *global, int stack, int small)

{
	if (small == *((*actual)->next->content))
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

static int	big_in_front(t_list_int **actual,
			t_global *global, int stack, int small)
{
	if (small == *((*actual)->next->content))
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

int	sort_a_six(int nbr_sorting, t_list_int **actual, t_global *global,
	int stack)
{
	long int	big;
	long int	small;

	if (nbr_sorting == 2)
	{
		if (*((*actual)->content) > *((*actual)->next->content))
			if (!swap(actual, global, stack))
				return (0);
		return (1);
	}
	if (!is_sorted_s_to_b(*actual, nbr_sorting))
	{
		big = find_biggest(*actual);
		small = find_smallest(*actual);
		if (small == *((*actual)->content)
			&& !(small_in_front(actual, global, stack)))
			return (0);
		if (small != *((*actual)->content) && big != *((*actual)->content)
			&& !(medium_in_front(actual, global, stack, small)))
			return (0);
		if (big == *((*actual)->content)
			&& !(big_in_front(actual, global, stack, small)))
			return (0);
	}
	return (1);
}
