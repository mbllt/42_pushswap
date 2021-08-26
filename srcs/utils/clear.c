#include "pushswap.h"

void	del(long int *content)
{
	free(content);
}

short int	clear(t_list_int **lsta, t_list_int **lstb, t_global *global, int i)
{
	if (*lsta)
		ft_lstclear_int(lsta, del);
	if (*lstb)
		ft_lstclear_int(lstb, del);
	free_global(global);	
	if (i == -1)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	return (0);
}