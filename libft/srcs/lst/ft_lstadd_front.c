/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 09:21:54 by mballet           #+#    #+#             */
/*   Updated: 2021/08/19 11:15:41 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front_int(t_list_int **lst, t_list_int *new)
{
	if (!(*lst))
		*lst = new;
	else
	{
		if (new->next != NULL)
		{
			while (new->next != NULL)
				new = new->next;
		}
		else
			new->next = *lst;
		*lst = new;
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!(*lst))
		*lst = new;
	else
	{
		if (new->next != NULL)
		{
			while (new->next != NULL)
				new = new->next;
		}
		else
			new->next = *lst;
		*lst = new;
	}
}
