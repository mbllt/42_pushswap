#include "pushswap.h"

void	rev_rotate_ab(t_list **lsta, t_list **lstb, t_global *global)
{
	t_list	*tmpa;
	t_list	*tmp_bisa;
	t_list	*tmpb;
	t_list	*tmp_bisb;

	tmpa = ft_lstlast(*lsta);
	tmp_bisa = *lsta;
	while ((*lsta)->next->next)
		*lsta = (*lsta)->next;
	(*lsta)->next = NULL;
	ft_lstadd_front(lsta, tmpa);
	(*lsta)->next = tmp_bisa;
	tmpb = ft_lstlast(*lstb);
	tmp_bisb = *lstb;
	while ((*lstb)->next->next)
		*lstb = (*lstb)->next;
	(*lstb)->next = NULL;
	ft_lstadd_front(lstb, tmpb);
	(*lstb)->next = tmp_bisb;
	global->nbr_ope++;
}
