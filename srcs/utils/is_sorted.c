#include "pushswap.h"

int	is_sorted_s_to_b(t_list_int *lst, int nbr_sorting)
{
	int	i;

	i = 0;
	while (i < nbr_sorting && lst->next)
	{
		if (*(lst->content) > *(lst->next->content))
			return (0);
		lst = lst->next;
		i++;
	}
	return (1);
}

int	is_sorted_b_to_s(t_list_int *lst, int nbr_sorting)
{
	int	i;

	i = 0;
	while (i < nbr_sorting)
	{
		if (*(lst->content) < *(lst->next->content))
			return (0);
		lst = lst->next;
		i++;
	}
	return (1);
}