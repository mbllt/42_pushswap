#include "libft.h"

int	lst_cpy_int(t_list_int *from, t_list_int **cpy)
{
	t_list_int	*tmp;

	(*cpy) = ft_lstnew_int(from->content);
	if (!(*cpy))
		return (0);
	tmp = NULL;
	if (from)
	{
		while (from->next)
		{
			from = from->next;
			tmp = ft_lstnew_int(from->content);
			if (!tmp)
				return (0);
			ft_lstadd_back_int(cpy, tmp);
		}
	}
	return (1);
}

int	lst_cpy(t_list *from, t_list **cpy)
{
	t_list	*tmp;

	(*cpy) = ft_lstnew(from->content);
	if (!(*cpy))
		return (0);
	tmp = NULL;
	if (from)
	{
		while (from->next)
		{
			from = from->next;
			tmp = ft_lstnew(from->content);
			if (!tmp)
				return (0);
			ft_lstadd_back(cpy, tmp);
		}
	}
	return (1);
}