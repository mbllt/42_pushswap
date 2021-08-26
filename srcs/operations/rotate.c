#include "pushswap.h"

void	rotate(t_list_int **lst, t_global *global)
{
	t_list_int	*tmp;
	t_list_int	*tmp_bis;

	tmp = (*lst);
	tmp_bis = (*lst)->next;
	ft_lstadd_back_int(lst, tmp);
	tmp->next = NULL;
	*lst = tmp_bis;
	global->nbr_ope++;
	if (global->stack == 0 || global->stack == 2)
		write(1, "ra\n", 3);
	if (global->stack == 1 || global->stack == 3)
		write(1, "rb\n", 3);
}