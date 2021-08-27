/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_global.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 17:40:13 by mballet           #+#    #+#             */
/*   Updated: 2021/08/27 17:40:14 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_global(t_global *global)
{
	if (global->str)
		free(global->str);
}
