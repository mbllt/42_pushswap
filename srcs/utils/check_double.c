#include "pushswap.h"

int	check_double(t_list_int *lst)
{
	int		size;
	t_list_int	*tmp;

	size = ft_lstsize_int(lst);
	if (!(lst_cpy_int(lst, &tmp)))
		return (0);
	while (lst)
	{
		tmp = lst->next;
		while (tmp)
		{
			if (lst->content == tmp->content)
				return (0);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	ft_lstclear_int(&tmp, del);
	return (1);
}