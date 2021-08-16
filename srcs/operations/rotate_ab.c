#include "pushswap.h"

void	rotate_ab(t_list **lsta, t_list **lstb, t_global *global)
{
	t_list	*tmpa;
	t_list	*tmp_bisa;
	t_list	*tmpb;
	t_list	*tmp_bisb;

	tmpa = (*lsta);
	tmp_bisa = (*lsta)->next;
	ft_lstadd_back(lsta, tmpa);
	tmpa->next = NULL;
	(*lsta) = tmp_bisa;
	tmpb = (*lstb);
	tmp_bisb = (*lstb)->next;
	ft_lstadd_back(lstb, tmpb);
	tmpb->next = NULL;
	(*lstb) = tmp_bisb;
	global->nbr_ope++;
}