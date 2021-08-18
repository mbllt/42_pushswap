#include "pushswap.h"

void	free_global(t_global *global)
{
	free(global->str);
}