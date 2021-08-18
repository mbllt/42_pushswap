#include "pushswap.h"

void	swap_ab(t_list_int **lsta, t_list_int **lstb, t_global *global)
{
	t_list_int	tempa;
	t_list_int	tempb;

	if (*lsta && (*lsta)->next)
	{
		tempa = **lsta;
		(*lsta)->content = tempa.next->content;
		(*lsta)->next->content = tempa.content;
	}
	if (*lstb && (*lstb)->next)
	{
		tempb = **lstb;
		(*lstb)->content = tempb.next->content;
		(*lstb)->next->content = tempb.content;
	}
	global->nbr_ope++;
}