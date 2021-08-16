/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 09:21:54 by mballet           #+#    #+#             */
/*   Updated: 2021/08/09 14:47:46 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!*alst)
		*alst = new;
	else
	{
		if (new->next != NULL)
		{
			while (new->next != NULL)
				new = new->next;
		}
		else
			new->next = *alst;
		*alst = new;
	}
}
