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
	write(1, "ra/rb\n", 6);
}