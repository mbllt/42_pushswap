/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <ballet.mia.6@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 04:23:39 by mballet           #+#    #+#             */
/*   Updated: 2021/08/15 18:28:35 by mballet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	del(void *content)
{
	(void)content;
}

int	pushswap(int argc, char **argv, t_list **lsta, t_list **lstb, t_global *global)
{
	t_list		*tmp;
	long int	num;

	if (argc > 1)
	{
		while (argc > 1 && is_strnum(argv[--argc]))
		{
			num = ft_atoi(argv[argc]);
			if (num > INT_MAX || num < INT_MIN)
				return (0);
			tmp = ft_lstnew((int *)num);
			if (!tmp)
				return (0);
			ft_lstadd_front(lsta, tmp);
		}
		if (argc > 1 || !check_double(*lsta))
			return (0);
		sort(lsta, lstb, global);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list		*lsta;
	t_list		*lstb;
	t_global	global;

	lsta = NULL;
	lstb = NULL;
	init_global(&global);
	if (argc <= 1 || !pushswap(argc, argv, &lsta, &lstb, &global))
	{
		ft_lstclear(&lsta, del);
		ft_lstclear(&lstb, del);
		write(1, "Error\n", 6);
		return (-1);
	}
	// swap(&lstb);
	// swap_ab(&lsta, &lstb);
	// push(&lsta, &lstb);
	// rotate_ab(&lsta, &lstb);
	// rev_rotate_ab(&lsta, &lstb);
	// printf("list a :\n");
	// printlst(lsta);
	// printf("list b :\n");
	// printlst(lstb);
	ft_lstclear(&lsta, del);
	ft_lstclear(&lstb, del);
	// printf("Nombre d'opération : %lld\n", global.nbr_ope);
	return (0);
}