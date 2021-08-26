#include "pushswap.h"

int	push(t_list_int **ontop, t_list_int **from, t_global *global)
{
	t_list_int	*temp;
	long int	*nbr;

	temp = NULL;
	nbr = NULL;
	if (*from)
	{
		nbr = malloc(sizeof(int));
		if (!nbr)
			return (0);
		*nbr = *((*from)->content);
		temp = ft_lstnew_int(nbr);
		if (!temp)
			return (0);
		ft_lstadd_front_int(ontop, temp);
		temp = *from;
		ft_lstdelone_int(*from, del);  /* quand j'enleve j'ai plus de leaks mais il me dit que je free un truc qui existe pas */
		*from = temp->next;
		global->nbr_ope++;
		if (global->stack == 1 || global->stack == 3)
			write(1, "pa\n", 3);
		if (global->stack == 0 || global->stack == 2)
			write(1, "pb\n", 3);
	}
	return (1);
}

// int	push(t_list_int **ontop, t_list_int **from, t_global *global)
// {
// 	t_list_int	*tmp;
// 	t_list_int	*tmp_bis;

// 	if (*from)
// 	{
// 		// printf("\033[32mLIST avant ontop :\n");
// 		// printlst_int(*ontop);
// 		// printf("\033[32mLIST avant from :\n");
// 		// printlst_int(*from);
// 		tmp = *from;
// 		tmp_bis = (*from)->next;
// 		tmp->next = NULL;
// 		ft_lstadd_front_int(ontop, tmp);
// 		*from = tmp_bis;
// 		// printf("\033[32mLIST ontop :\n");
// 		// printlst_int(*ontop);
// 		// printf("\033[32mLIST from :\n");
// 		// printlst_int(*from);
// 		global->nbr_ope++;
// 		if (global->stack == 1 || global->stack == 3)
// 			write(1, "pa\n", 3);
// 		else
// 			write(1, "pb\n", 3);
// 	}
// 	return (1);
// }