#include "pushswap.h"

void	seperate(t_list_int **actual, t_list_int **other, t_global *global, int nbr_sorting, int stack)
{
	t_list_int	*tmp;
	int			i;

	(void)stack;
	i = 0;
	tmp = *actual;
	while (i < nbr_sorting)
	{
		if (*(tmp->content) < global->median && stack == 0)		/* les plus petits vont dans la pile b */
		{
			while (*(tmp->content) != *((*actual)->content))
			{
				rotate(actual, global);
			}
			push(other, actual, global);
		}
		else if (*(tmp->content) > global->median && stack == 1)		/* les plus petits vont dans la pile b */
		{
			while (*(tmp->content) != *((*actual)->content))
			{
				rotate(actual, global);
			}
			push(other, actual, global);
		}
		tmp = tmp->next;
		i++;
	}
}