#include "pushswap.h"

void	rev_rotate(t_list_int **lst, t_global *global)
{
	t_list_int	*tmp;
	t_list_int	*tmp_bis;

	tmp = ft_lstlast_int(*lst);
	tmp_bis = *lst;
	while ((*lst)->next->next)
		*lst = (*lst)->next;
	(*lst)->next = NULL;
	ft_lstadd_front_int(lst, tmp);
	(*lst)->next = tmp_bis;
	global->nbr_ope++;
	if (global->stack == 0)
		write(1, "rra\n", 4);
	if (global->stack == 1)
		write(1, "rrb\n", 4);
}