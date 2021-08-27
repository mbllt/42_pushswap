/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 17:39:53 by mballet           #+#    #+#             */
/*   Updated: 2021/08/27 17:39:54 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_ab(t_list_int **lsta, t_list_int **lstb, t_global *global)
{
	t_list_int	tempa;
	t_list_int	tempb;

	if (*lsta && (*lsta)->next)
	{
		tempa = **lsta;
		(*lsta)->content = tempa.next->content;
		(*lsta)->next->content = tempa.content;
	}
	if (*lstb && (*lstb)->next)
	{
		tempb = **lstb;
		(*lstb)->content = tempb.next->content;
		(*lstb)->next->content = tempb.content;
	}
	global->nbr_ope++;
	write(1, "ss\n", 3);
}
