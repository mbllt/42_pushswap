#include "pushswap.h"

int	init_global(t_global *global, int argc, char **argv)
{
	global->nbr_ope = 0;
	global->median = 0;
	global->lst_size = 0;
	global->argc = argc;
	global->argv = NULL;
	global->argv = ft_strdup_double(argv, argc);
	if (!global->argv)
		return (0);
	return (1);
}