#include "pushswap.h"

void	rev_rotate(t_list **lst, t_global *global)
{
	t_list	*tmp;
	t_list	*tmp_bis;

	tmp = ft_lstlast(*lst);
	tmp_bis = *lst;
	while ((*lst)->next->next)
		*lst = (*lst)->next;
	(*lst)->next = NULL;
	ft_lstadd_front(lst, tmp);
	(*lst)->next = tmp_bis;
	global->nbr_ope++;
}