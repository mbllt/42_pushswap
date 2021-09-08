/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a_six.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:53:42 by mballet           #+#    #+#             */
/*   Updated: 2021/09/08 12:56:07 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	sort_a_six(int nbr_sorting, t_list_int **actual, t_global *global, int stack)
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
		if (small == *((*actual)->content))
		{
			if (!rev_rotate(actual, global, stack))
				return (0);
			if (!swap(actual, global, stack))
				return (0);
			return (1);
		}
		if (small != *((*actual)->content) && big != *((*actual)->content))
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
		}
		if (big == *((*actual)->content))
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
		}
	}
	return (1);
}