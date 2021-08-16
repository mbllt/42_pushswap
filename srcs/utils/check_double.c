#include "pushswap.h"

int	check_double(t_list *lst)
{
	int		size;
	t_list	*tmp;

	size = ft_lstsize(lst);
	if (!(lst_cpy(lst, &tmp)))
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
	ft_lstclear(&tmp, del);
	return (1);
}