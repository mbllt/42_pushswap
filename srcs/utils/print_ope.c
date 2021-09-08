/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ope.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 16:01:07 by mballet           #+#    #+#             */
/*   Updated: 2021/09/08 14:41:17 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_ope(t_global *global)
{
	char	*str;
	int		i;
	t_list	*tmp;

	tmp = NULL;
	tmp = global->ope;
	while (global->ope)
	{
		i = 0;
		str = NULL;
		str = (char *)global->ope->content;
		while (str[i])
		{
			write(1, &str[i], 1);
			i++;
		}
		write(1, "\n", 1);
		global->ope = global->ope->next;
	}
	global->ope = tmp;
}
