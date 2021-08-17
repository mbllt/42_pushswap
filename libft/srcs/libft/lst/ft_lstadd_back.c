/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:34:52 by mballet           #+#    #+#             */
/*   Updated: 2021/08/17 14:04:48 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back_int(t_list_int **alst, t_list_int *new)
{
	t_list_int	*temp;

	temp = NULL;
	if (*alst == NULL)
		*alst = new;
	else
	{
		temp = ft_lstlast_int(*alst);
		temp->next = new;
	}
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*temp;

	temp = NULL;
	if (*alst == NULL)
		*alst = new;
	else
	{
		temp = ft_lstlast(*alst);
		temp->next = new;
	}
}
