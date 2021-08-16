#include "pushswap.h"

void	rotate(t_list **lst, t_global *global)
{
	t_list	*tmp;
	t_list	*tmp_bis;

	tmp = (*lst);
	tmp_bis = (*lst)->next;
	ft_lstadd_back(lst, tmp);
	tmp->next = NULL;
	*lst = tmp_bis;
	global->nbr_ope++;
}