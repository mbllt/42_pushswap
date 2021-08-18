#include "pushswap.h"

int	push(t_list_int **ontop, t_list_int **from, t_global *global)
{
	t_list_int	*temp;

	temp = NULL;
	temp = ft_lstnew_int((*from)->content);
	if (!temp)
		return (0);
	ft_lstadd_front_int(ontop, temp);
	temp = *from;
	ft_lstdelone_int(*from, del);
	(*from) = temp->next;
	global->nbr_ope++;
	return (1);
}