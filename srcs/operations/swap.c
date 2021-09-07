/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 17:39:58 by mballet           #+#    #+#             */
/*   Updated: 2021/09/07 13:45:40 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	swap(t_list_int **lst, t_global *global, int stack)
{
	t_list_int	temp;

	if (*lst && (*lst)->next)
	{
		temp = **lst;
		(*lst)->content = temp.next->content;
		(*lst)->next->content = temp.content;
	}
	global->nbr_ope++;
	if (stack == 0 || stack == 2)
		if (!add_ope(global, "sa", 2))
			return (0);
	if (stack == 1 || stack == 3)
		if (!add_ope(global, "sb", 2))
			return (0);
	return (1);
}
