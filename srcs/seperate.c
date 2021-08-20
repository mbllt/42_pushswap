#include "pushswap.h"

void	seperate(t_list_int **actual, t_list_int **other, t_global *global)
{
	t_list_int	*tmp;
	(void)actual;
	(void)other;
	(void)global;
	printf("median :%d\n", global->median);
	tmp = *actual;
	while (tmp)
	{
		if (*(tmp->content) > global->median)
		{
			while (*(tmp->content) != *((*actual)->content))
			{
				rotate(actual, global);
			}
			push(other, actual, global);
		}
		tmp = tmp->next;
	}
}