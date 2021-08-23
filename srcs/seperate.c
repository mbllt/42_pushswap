#include "pushswap.h"

void	seperate(t_list_int **actual, t_list_int **other, t_global *global, int nbr_sorting)
{
	t_list_int	*tmp;
	int			i;

	i = 0;
	tmp = *actual;
	while (i < nbr_sorting)
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
		i++;
	}
}