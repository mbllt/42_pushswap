/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printlst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:38:37 by mballet           #+#    #+#             */
/*   Updated: 2021/09/07 13:38:38 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	printlst_int(t_list_int *lst)
{
	while (lst != NULL)
	{
		printf("%ld, ", *(lst->content));
		lst = lst->next;
	}
	printf("\n");
}
