#include "pushswap.h"

void	free_global(t_global *global)
{
	if (global->str)
		free(global->str);
}