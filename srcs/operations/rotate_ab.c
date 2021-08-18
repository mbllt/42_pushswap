#include "pushswap.h"

void	rotate_ab(t_list_int **lsta, t_list_int **lstb, t_global *global)
{
	t_list_int	*tmpa;
	t_list_int	*tmp_bisa;
	t_list_int	*tmpb;
	t_list_int	*tmp_bisb;

	tmpa = (*lsta);
	tmp_bisa = (*lsta)->next;
	ft_lstadd_back_int(lsta, tmpa);
	tmpa->next = NULL;
	(*lsta) = tmp_bisa;
	tmpb = (*lstb);
	tmp_bisb = (*lstb)->next;
	ft_lstadd_back_int(lstb, tmpb);
	tmpb->next = NULL;
	(*lstb) = tmp_bisb;
	global->nbr_ope++;
}