#include "pushswap.h"

void	swap(t_list **lst, t_global *global)
{
	t_list	temp;

	if (*lst && (*lst)->next)
	{
		temp = **lst;
		(*lst)->content = temp.next->content;
		(*lst)->next->content = temp.content;
	}
	global->nbr_ope++;
}