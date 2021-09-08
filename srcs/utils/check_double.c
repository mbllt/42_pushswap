/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 17:40:04 by mballet           #+#    #+#             */
/*   Updated: 2021/09/08 14:40:22 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_double(t_list_int *lst)
{
	t_list_int	*tmp;

	tmp = NULL;
	tmp = lst;
	while (lst)
	{
		tmp = lst->next;
		while (tmp)
		{
			if (*(lst->content) == *(tmp->content))
				return (0);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (1);
}
