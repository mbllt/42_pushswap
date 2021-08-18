#include "pushswap.h"

void	rev_rotate_ab(t_list_int **lsta, t_list_int **lstb, t_global *global)
{
	t_list_int	*tmpa;
	t_list_int	*tmp_bisa;
	t_list_int	*tmpb;
	t_list_int	*tmp_bisb;

	tmpa = ft_lstlast_int(*lsta);
	tmp_bisa = *lsta;
	while ((*lsta)->next->next)
		*lsta = (*lsta)->next;
	(*lsta)->next = NULL;
	ft_lstadd_front_int(lsta, tmpa);
	(*lsta)->next = tmp_bisa;
	tmpb = ft_lstlast_int(*lstb);
	tmp_bisb = *lstb;
	while ((*lstb)->next->next)
		*lstb = (*lstb)->next;
	(*lstb)->next = NULL;
	ft_lstadd_front_int(lstb, tmpb);
	(*lstb)->next = tmp_bisb;
	global->nbr_ope++;
}
