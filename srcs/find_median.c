#include "pushswap.h"

static void	fill_in_str(t_list_int *actual, int **str)
{
	t_list_int	*tmp;
	int	i;

	tmp = actual;
	i = 0;
	while (tmp != NULL)
	{
		STR[i] = *(tmp->content);
		tmp = tmp->next;
		i++;
	}
}

static void	swap_str(int **str, int i, int j)
{
	int	tmp;

	tmp = STR[i];
	STR[i] = STR[j];
	STR[j] = tmp;
}

static void	sort_str(int **str, t_global *global)
{
	int	i;
	int	j;

	i = 0;
	while (i < global->argc - 1)
	{
		j = 0;
		while (j < global->argc - 1)
		{
			if (STR[i] < STR[j])
				swap_str(str, i, j);
			j++;
		}
		i++;
	}
}

int	find_median(t_list_int *actual, t_global *global, int **str)
{
	int	size;
	int	nbr;

	fill_in_str(actual, str);
	sort_str(str, global);
	size = global->argc - 1;
	if (size <= 3)
		return (size);
	if (size % 2)
		size--;
	nbr = (size / 2);
	global->median = (*str)[nbr];
	return (nbr);
}