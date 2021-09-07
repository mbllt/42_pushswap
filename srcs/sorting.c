/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 17:40:46 by mballet           #+#    #+#             */
/*   Updated: 2021/09/07 14:00:53 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	sort_a(t_list_int **actual, t_global *global, int nbr_sorting, int stack)
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
		if (small == *((*actual)->next->content) && big == *((*actual)->next->next->content))
		{
			if (!swap(actual, global, stack))
				return (0);
			return (1);
		}
		if (big == *((*actual)->content))
			if (!swap(actual, global, stack))
				return (0);
		if (!rotate(actual, global, stack))
			return (0);
		if (!swap(actual, global, stack))
			return (0);
		if (!rev_rotate(actual, global, stack))
			return (0);
		if (small != *((*actual)->content))
			if (!swap(actual, global, stack))
				return (0);
	}
	return (1);
}

static int	sort_b(t_list_int **actual, t_global *global, int nbr_sorting, int stack)
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

static int	stack_on(t_list_int **actual, t_list_int **other, int nbr_sorting, t_global *global, int stack)
{
	int	i;

	i = 0;
	while (i < nbr_sorting)
	{
		if (!push(other, actual, global, stack))
			return (0);
		i++;
	}
	return (1);
}

static int	sort_three(int nbr_sorting, t_list_int **actual, t_list_int **other, t_global *global, int stack)
{
	if (stack % 2 == 1)
	{
		if (!sort_b(actual, global, nbr_sorting, stack))
			return (0);
	}
	else
	{
		if (!sort_a(actual, global, nbr_sorting, stack))
			return (0);
	}
	if (stack == 2)
		if (!stack_on(actual, other, nbr_sorting, global, stack))
			return (0);
	if (stack == 3)
		if (!stack_on(actual, other, nbr_sorting, global, stack))
			return (0);
	return (1);
}

int	sorting(int nbr_sorting, t_list_int **actual, t_list_int **other, t_global *global, int stack)
{
	if (nbr_sorting <= 3)
	{
		return (sort_three(nbr_sorting, actual, other, global, stack));
	}
	if (!(find_median(nbr_sorting, *actual, global, &(global->str), stack)))
		return (0);
	seperate(actual, other, global, nbr_sorting, stack);
	if (!(stack % 2))
	{
		if (!sorting(nbr_sorting / 2 + nbr_sorting % 2, actual, other, global, 0))
			return (0);
		if (!sorting(nbr_sorting / 2, other, actual, global, 3))
			return (0);
	}
	else
	{
		if (!sorting(nbr_sorting / 2 + nbr_sorting % 2, actual, other, global, 1))
			return (0);
		if (!sorting(nbr_sorting / 2, other, actual, global, 2))
			return (0);
	}
	if (stack == 2)
		stack_on(actual, other, nbr_sorting, global, stack);
	if (stack == 3)
		stack_on(actual, other, nbr_sorting, global, stack);
	return (1);
}
//if (!sorting(nbr_sorting / 2 + nbr_sorting % 2, actual, other, global, 0))
//			>> dans a et va dans a
//if (!sorting(nbr_sorting / 2, other, actual, global, 3)
//			>> dans a et va dans b

//if (!sorting(nbr_sorting / 2 + nbr_sorting % 2, actual, other, global, 1))
//			>> dans b et va dans b
//if (!sorting(nbr_sorting / 2, other, actual, global, 2))
//			>> dans b et va dans a
