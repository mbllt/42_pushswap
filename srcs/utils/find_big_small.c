/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_big_small.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 17:40:10 by mballet           #+#    #+#             */
/*   Updated: 2021/09/07 13:52:47 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int long	find_biggest(t_list_int *lst)
{
	long	big;

	big = *(lst->content);
	if (big < *(lst->next->content))
		big = *(lst->next->content);
	if (big < *(lst->next->next->content))
		big = *(lst->next->next->content);
	return (big);
}

int long	find_smallest(t_list_int *lst)
{
	long	small;

	small = *(lst->content);
	if (small > *(lst->next->content))
		small = *(lst->next->content);
	if (small > *(lst->next->next->content))
		small = *(lst->next->next->content);
	return (small);
}
