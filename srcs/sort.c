#include "pushswap.h"

// static int	sort_swap(t_list **lst, long long int *ope, t_global *global)
// {
// 	t_list *tmp;

// 	tmp = *lst;
// 	while (*lst && (*lst)->next)
// 	{
// 		if ((int)(*lst)->content > (int)(*lst)->next->content)
// 		{
// 			(*ope)++;
// 			swap(lst, global);
// 		}
// 		*lst = (*lst)->next;
// 	}
// 	*lst = tmp;
// 	return (1);
// }

int	sort(t_list **lsta, t_list **lstb, t_global *global)
{
	// long long int	ope;

	// ope = 1;
	// while (ope > 0)
	// {
	// 	ope = 0;
	// 	if (!sort_swap(lsta, &ope, global))
	// 		return (0);
	// }
	(void)lstb;
	global->lst_size = ft_lstsize(*lsta);
	if (global->lst_size > 1)
	{
		find_median(*lsta, global);
	}
	printf("Median :%d\n", global->median);
	return (1);
}