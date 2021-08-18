#include "pushswap.h"

int	check_double(t_list_int *lst)
{
	t_list_int	*tmp;

	tmp = lst;
	while (lst)
	{
		tmp = lst->next;
		while (tmp)
		{
			if (*(lst->content) == *(tmp->content))
				return (0);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (1);
}