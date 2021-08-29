/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 17:39:42 by mballet           #+#    #+#             */
/*   Updated: 2021/08/29 17:32:56 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	rev_rotate(t_list_int **lst, t_global *global, int stack)
{
	t_list_int	*tmp;
	t_list_int	*tmp_bis;

	tmp = ft_lstlast_int(*lst);
	tmp_bis = *lst;
	while ((*lst)->next->next)
		*lst = (*lst)->next;
	(*lst)->next = NULL;
	ft_lstadd_front_int(lst, tmp);
	(*lst)->next = tmp_bis;
	global->nbr_ope++;
	if (stack == 0 || stack == 2)
		if (!add_ope(global, "rra", 3))
			return (0);
	if (stack == 1 || stack == 3)
		if (!add_ope(global, "rrb", 3))
			return (0);
	// if (stack == 0 || stack == 2)
	// 	write(1, "rra\n", 4);
	// if (stack == 1 || stack == 3)
	// 	write(1, "rrb\n", 4);
	return (1);
}
