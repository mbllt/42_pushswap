/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_six.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:04:32 by mballet           #+#    #+#             */
/*   Updated: 2021/09/08 12:54:45 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	push_on_a(t_list_int **lsta, t_list_int **lstb, t_global *global)
{
	int	size;

	size = ft_lstsize_int(*lstb);
	while (size)
	{
		if (!push(lsta, lstb, global, 1))
			return (0);
		size--;
	}
	return (1);
}

int	sort_six(t_list_int **lsta, t_list_int **lstb, t_global *global)
{
	if (global->argc <= 4)
	{
		return (sort_a_six(global->argc - 1, lsta, global, 0));
	}
	if (!find_median(*lsta, global, 0))
		return (0);
	if (!seperate(lsta, lstb, global, 0))
		return (0);
	if (!sort_a_six(ft_lstsize_int(*lsta), lsta, global, 0))
		return (0);
	if (!sort_b_six(ft_lstsize_int(*lstb), lstb, global, 1))
		return (0);
	if (!push_on_a(lsta, lstb, global))
		return (0);
	if (!check_ope(global))
		return (0);
	return (1);
}
