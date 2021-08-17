/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 04:23:39 by mballet           #+#    #+#             */
/*   Updated: 2021/08/17 13:44:34 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	del(void *content)
{
	free(content);
}

int	get_check_lst(t_list **lsta, t_list **lstb, t_global *global)
{
	t_list		*tmp;
	int			argc;
	long int	num;
	// long int	nbr;

	argc = global->argc;
	if (argc > 1)
	{
		while (argc > 1 && is_strnum(global->argv[--argc]))
		{
			num = ft_atoi(global->argv[argc]);
			if (num > INT_MAX || num < INT_MIN)
				return (0);
			// nbr = NULL;
			// nbr = malloc(sizeof(int));
			// if (!nbr)
			// 	return (0);
			// nbr = num;
			tmp = ft_lstnew((int)num);
			if (!tmp)
				return (0);
			ft_lstadd_front(lsta, tmp);
		}
		if (argc > 1 || !check_double(*lsta))
			return (0);
		(void)lstb;
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
	if (!init_global(&global, argc, argv))
	{
		free_global(&global);
		return (-1);
	}
	if (argc == 1)
		return (0);
	if (!get_check_lst(&lsta, &lstb, &global))
	{
		ft_lstclear(&lsta, del);
		ft_lstclear(&lstb, del);
		free_global(&global);	
		write(1, "Error\n", 6);
		return (-1);
	}
	printf("list a :\n");
	printlst(lsta);
	// printf("list b :\n");
	// printlst(lstb);
	ft_lstclear(&lsta, del);
	// ft_lstclear(&lstb, del);
	free_global(&global);
	// printf("Nombre d'opération : %d\n", global.nbr_ope);
	return (0);
}