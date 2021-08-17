#include "pushswap.h"

void	free_global(t_global *global)
{
	int	i;

	if (global->argv)
	{
		i = 0;
		while (i < global->argc)
		{
			free(global->argv[i]);
			i++;
		}
		free(global->argv);
	}
}