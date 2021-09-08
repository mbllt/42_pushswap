/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seperate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 17:40:42 by mballet           #+#    #+#             */
/*   Updated: 2021/09/08 11:04:02 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	seperate(t_list_int **actual, t_list_int **other,
		t_global *global, int stack)
{
	t_list_int	*tmp;
	int			i;
	int			nbr;
	int			save_size;

	i = 0;
	nbr = 0;
	tmp = *actual;
	save_size = ft_lstsize_int(*actual);
	while (i < global->nbr_sort)
	{
		if (*(tmp->content) < global->median && (stack == 0 || stack == 2))
		{
			while (*(tmp->content) != *((*actual)->content))
			{
				if (!rotate(actual, global, stack))
					return (0);
				nbr++;
			}
			if (!push(other, actual, global, stack))
				return (0);
		}
		else if (*(tmp->content) > global->median && (stack == 1 || stack == 3))
		{
			while (*(tmp->content) != *((*actual)->content))
			{
				if (!rotate(actual, global, stack))
					return (0);
				nbr++;
			}
			if (!push(other, actual, global, stack))
				return (0);
		}
		tmp = tmp->next;
		i++;
	}
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
