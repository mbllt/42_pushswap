/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 17:40:07 by mballet           #+#    #+#             */
/*   Updated: 2021/08/27 17:40:08 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	del(long int *content)
{
	free(content);
}

short int	clear(t_list_int **lsta, t_list_int **lstb, t_global *global, int i)
{
	if (*lsta)
		ft_lstclear_int(lsta, del);
	if (*lstb)
		ft_lstclear_int(lstb, del);
	free_global(global);	
	if (i == -1)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	return (0);
}
