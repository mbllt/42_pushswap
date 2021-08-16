#include "pushswap.h"

int	push(t_list **ontop, t_list **from, t_global *global)
{
	t_list	*temp;

	temp = NULL;
	temp = ft_lstnew((*from)->content);
	if (!temp)
		return (0);
	ft_lstadd_front(ontop, temp);
	temp = *from;
	ft_lstdelone(*from, del);
	(*from) = temp->next;
	global->nbr_ope++;
	return (1);
}