/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 04:23:39 by mballet           #+#    #+#             */
/*   Updated: 2021/08/19 20:45:01 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	get_lst(t_list_int **lsta, int i, char **argv)
{
	t_list_int	*tmp;
	long int	num;
	long int	*nbr;

	num = ft_atoi(argv[i]);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	nbr = NULL;
	nbr = malloc(sizeof(int));
	if (!nbr)
		return (0);
	*nbr = num;
	tmp = ft_lstnew_int(nbr);
	if (!tmp)
		return (0);
	ft_lstadd_back_int(lsta, tmp);
	return (1);
}
	
int	get_check_lst(t_list_int **lsta, t_global *global, char **argv)
{
	int	i;
	int	num;

	if (global->argc > 1)
	{
		i = 1;
		num = is_strnum(argv[i]);
		while (num && i < global->argc)
		{
			if (!(get_lst(lsta, i, argv)))
				return (0);
			i++;
		}		
		if (!num || !check_double(*lsta))
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list_int		*lsta;
	t_list_int		*lstb;
	t_global		global;

	lsta = NULL;
	lstb = NULL;
	if (argc > 1)
	{
		if (!init_global(&global, argc))
		{
			return (clear(&lsta, &lsta, &global, -1));
		}
		if (!get_check_lst(&lsta, &global, argv) ||
			!(sorting(global.argc - 1, &lsta, &lstb, &global)))
		{
			return (clear(&lsta, &lsta, &global, -1));
		}
	}
	// printf("\033[32mLIST a :\n");
	// printlst_int(lsta);
	// printf("nbr_ope %d\n", global.nbr_ope);
	return (clear(&lsta, &lsta, &global, 0));
}