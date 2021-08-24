#include "pushswap.h"

void	swap(t_list_int **lst, t_global *global)
{
	t_list_int	temp;

	if (*lst && (*lst)->next)
	{
		temp = **lst;
		(*lst)->content = temp.next->content;
		(*lst)->next->content = temp.content;
	}
	global->nbr_ope++;
	if (global->stack == 0)
		write(1, "sa\n", 3);
	if (global->stack == 1)
		write(1, "sb\n", 3);
}