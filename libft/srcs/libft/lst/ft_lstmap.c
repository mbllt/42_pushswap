/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 13:43:22 by mballet           #+#    #+#             */
/*   Updated: 2021/08/17 16:25:58 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;

	if (lst == NULL)
		return (NULL);
	else
	{
		temp = ft_lstnew(f(lst->content));
		lst = lst->next;
		while (lst != NULL)
		{
			new = ft_lstnew(f(lst->content));
			if (!(new))
			{
				ft_lstclear(&temp, del);
				return (NULL);
			}
			ft_lstadd_back(&temp, new);
			new = new->next;
			lst = lst->next;
		}
		return (temp);
	}
}
