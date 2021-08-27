/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 17:39:32 by mballet           #+#    #+#             */
/*   Updated: 2021/08/27 17:39:40 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	push(t_list_int **ontop, t_list_int **from, t_global *global, int stack)
{
	t_list_int	*temp;
	long int	*nbr;

	temp = NULL;
	nbr = NULL;
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
		ft_lstdelone_int(*from, del);
		*from = temp->next;
		global->nbr_ope++;
		if (stack == 1 || stack == 3)
			write(1, "pa\n", 3);
		if (stack == 0 || stack == 2)
			write(1, "pb\n", 3);
	}
	return (1);
}
