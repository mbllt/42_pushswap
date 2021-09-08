/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 17:40:46 by mballet           #+#    #+#             */
/*   Updated: 2021/09/08 14:42:59 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	stack_on(t_list_int **actual, t_list_int **other,
			t_global *global, int stack)
{
	int	i;

	i = 0;
	while (i < global->nbr_sort)
	{
		if (!push(other, actual, global, stack))
			return (0);
		i++;
	}
	return (1);
}

static int	sort_three(t_list_int **actual, t_list_int **other,
			t_global *global, int stack)
{
	if (stack % 2 == 1)
	{
		if (!sort_b(actual, global, stack))
			return (0);
	}
	else
	{
		if (!sort_a(actual, global, stack))
			return (0);
	}
	if (stack == 2)
		if (!stack_on(actual, other, global, stack))
			return (0);
	if (stack == 3)
		if (!stack_on(actual, other, global, stack))
			return (0);
	return (1);
}

static int	send_stack_even(t_list_int **actual, t_list_int **other,
	t_global *global, int nbr_sort_tmp)
{
	global->nbr_sort = nbr_sort_tmp / 2 + nbr_sort_tmp % 2;
	if (!sorting(actual, other, global, 0))
		return (0);
	global->nbr_sort = nbr_sort_tmp / 2;
	if (!sorting(other, actual, global, 3))
		return (0);
	return (1);
}

static int	send_stack_odd(t_list_int **actual, t_list_int **other,
	t_global *global, int nbr_sort_tmp)
{
	global->nbr_sort = nbr_sort_tmp / 2 + nbr_sort_tmp % 2;
	if (!sorting(actual, other, global, 1))
		return (0);
	global->nbr_sort = nbr_sort_tmp / 2;
	if (!sorting(other, actual, global, 2))
		return (0);
	return (1);
}

int	sorting(t_list_int **actual, t_list_int **other,
	t_global *global, int stack)
{
	int	nbr_sort_tmp;

	nbr_sort_tmp = global->nbr_sort;
	if (nbr_sort_tmp <= 3)
		return (sort_three(actual, other, global, stack));
	if (!(find_median(*actual, global, stack)))
		return (0);
	if (!seperate(actual, other, global, stack))
		return (0);
	if (!(stack % 2))
	{
		if (!send_stack_even(actual, other, global, nbr_sort_tmp))
			return (0);
	}
	else
	{
		if (!send_stack_odd(actual, other, global, nbr_sort_tmp))
			return (0);
	}
	global->nbr_sort = nbr_sort_tmp;
	if (stack == 2 || stack == 3)
		stack_on(actual, other, global, stack);
	return (1);
}
//			>> dans a et va dans a
//			>> dans a et va dans b

//			>> dans b et va dans b
//			>> dans b et va dans a
