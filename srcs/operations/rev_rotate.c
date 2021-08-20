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
	write(1, "rra/rrb\n", 8);
}