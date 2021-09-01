/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seperate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <ballet.mia.6@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 17:40:42 by mballet           #+#    #+#             */
/*   Updated: 2021/09/01 15:21:39 by mballet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	seperate(t_list_int **actual, t_list_int **other, t_global *global, int nbr_sorting, int stack)
{
	t_list_int	*tmp;
	int			i;
	int			nbr;
	int			save_size;

	i = 0;
	nbr = 0;
	tmp = *actual;
	save_size = ft_lstsize_int(*actual);
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
	if (save_size != nbr_sorting)
	{
		while (i < nbr)
		{
			rev_rotate(actual, global, stack);
			i++;
		}
	}
}
