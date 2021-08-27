/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 17:39:50 by mballet           #+#    #+#             */
/*   Updated: 2021/08/27 17:39:51 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate(t_list_int **lst, t_global *global, int stack)
{
	t_list_int	*tmp;
	t_list_int	*tmp_bis;

	tmp = (*lst);
	tmp_bis = (*lst)->next;
	ft_lstadd_back_int(lst, tmp);
	tmp->next = NULL;
	*lst = tmp_bis;
	global->nbr_ope++;
	if (stack == 0 || stack == 2)
		write(1, "ra\n", 3);
	if (stack == 1 || stack == 3)
		write(1, "rb\n", 3);
}
