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
	// ft_lstdelone_int(*from, del);  /* quand j'enleve j'ai plus de leaks mais il me dit que je free un truc qui existe pas */
	*from = temp->next;
	global->nbr_ope++;
	if (global->stack == 0)
		write(1, "pa\n", 3);
	if (global->stack == 1)
		write(1, "pb\n", 3);
	return (1);
}