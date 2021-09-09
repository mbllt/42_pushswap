/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 17:39:32 by mballet           #+#    #+#             */
/*   Updated: 2021/09/09 09:59:38 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	norm(int stack, t_global *global)
{
	if (stack == 1 || stack == 3)
		if (!add_ope(global, "pa", 2))
			return (0);
	if (stack == 0 || stack == 2)
		if (!add_ope(global, "pb", 2))
			return (0);
	return (1);
}

int	push(t_list_int **ontop, t_list_int **from, t_global *global, int stack)
{
	t_list_int	*temp;
	long int	*nbr;

	if (*from)
	{
		nbr = malloc(sizeof(int));
		if (!nbr)
			return (0);
		*nbr = *((*from)->content);
		temp = ft_lstnew_int(nbr);
		if (!temp)
			return (0);
		ft_lstadd_front_int(ontop, temp);
		temp = *from;
		ft_lstdelone_int(*from, del_int);
		*from = temp->next;
		global->nbr_ope++;
		if (!norm(stack, global))
			return (0);
	}
	return (1);
}
