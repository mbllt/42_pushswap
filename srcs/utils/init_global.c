#include "pushswap.h"

static int	init_str(t_global *global, t_list_int *lst)
{
	int	size;

	size = ft_lstsize_int(lst);
	global->str = NULL;
	global->str = (int *)malloc(sizeof(int) * size + 1);
	if (!global->str)
		return (0);
	global->str[size] = 0;
	return (1);
}

int	init_global(t_global *global, int argc, t_list_int *lst)
{
	global->nbr_ope = 0;
	global->median = 0;
	global->lst_size = 0;
	global->argc = argc;
	if (!(init_str(global, lst)))
		return (0);
	return (1);
}