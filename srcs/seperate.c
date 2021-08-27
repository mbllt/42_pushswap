/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seperate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 17:40:42 by mballet           #+#    #+#             */
/*   Updated: 2021/08/27 17:40:43 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	seperate(t_list_int **actual, t_list_int **other, t_global *global, int nbr_sorting, int stack)
{
	t_list_int	*tmp;
	int			i;
	int			nbr;

	i = 0;
	nbr = 0;
	tmp = *actual;
	while (i < nbr_sorting)
	{
		if (*(tmp->content) < global->median && (stack == 0 || stack == 2))
		{
			while (*(tmp->content) != *((*actual)->content))
			{
				rotate(actual, global, stack);
				nbr++;
			}
			push(other, actual, global, stack);
		}
		else if (*(tmp->content) > global->median && (stack == 1 || stack == 3))
		{
			while (*(tmp->content) != *((*actual)->content))
			{
				rotate(actual, global, stack);
				nbr++;
			}
			push(other, actual, global, stack);
		}
		tmp = tmp->next;
		i++;
	}
	i = 0;
	while (i < nbr)
	{
		rev_rotate(actual, global, stack);
		i++;
	}
}
