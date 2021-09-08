/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_global.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 17:40:16 by mballet           #+#    #+#             */
/*   Updated: 2021/09/08 10:12:44 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	init_str(t_global *global, int size)
{
	global->str = NULL;
	global->str = (int *)malloc(sizeof(int) * size);
	if (!global->str)
		return (0);
	global->str[size] = 0;
	return (1);
}

int	init_global(t_global *global, int argc)
{
	global->nbr_ope = 0;
	global->median = 0;
	global->lst_size = 0;
	global->argc = argc;
	if (!(init_str(global, argc)))
		return (0);
	global->changed = 0;
	global->ope = NULL;
	global->nbr_sort = argc - 1;
	return (1);
}
