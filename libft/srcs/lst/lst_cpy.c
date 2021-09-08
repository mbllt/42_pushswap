/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:36:59 by mballet           #+#    #+#             */
/*   Updated: 2021/09/08 14:51:58 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	lst_cpy_int(t_list_int *from, t_list_int **cpy)
{
	t_list_int	*tmp;

	(*cpy) = ft_lstnew_int(from->content);
	if (!(*cpy))
		return (0);
	if (from)
	{
		while (from->next)
		{
			tmp = NULL;
			from = from->next;
			tmp = ft_lstnew_int(from->content);
			if (!tmp)
				return (0);
			ft_lstadd_back_int(cpy, tmp);
		}
	}
	return (1);
}

int	lst_cpy(t_list *from, t_list **cpy)
{
	t_list	*tmp;

	(*cpy) = ft_lstnew(from->content);
	if (!(*cpy))
		return (0);
	if (from)
	{
		while (from->next)
		{
			tmp = NULL;
			from = from->next;
			tmp = ft_lstnew(from->content);
			if (!tmp)
				return (0);
			ft_lstadd_back(cpy, tmp);
		}
	}
	return (1);
}
