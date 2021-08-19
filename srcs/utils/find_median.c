#include "pushswap.h"

#define STR (*str)

static void	fill_in_str(t_list_int *lst, int **str)
{
	int	i;
	t_list_int	*tmp;

	i = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		STR[i] = *(tmp->content);
		tmp = tmp->next;
		i++;
	}
}

// static void	swap_str(int **str, int i, int j)
// {
// 	int	tmp;

// 	tmp = STR[i];
// 	STR[i] = STR[j];
// 	STR[j] = tmp;
// }

static void	sort_str(int **str)
{
	int	i;
	int	j;

	i = 0;
	while (STR[i])
	{
		j = 0;
		while (STR[j])
		{
			// if (STR[i] > STR[j])
				// swap_str(str, i, j);
			j++;
		}
		i++;
	}
}

int	find_median(t_list_int *lst, t_global *global, int **str)
{
	(void)lst;
	(void)str;
	fill_in_str(lst, str);
	sort_str(str);
	printf("\nSTR :\n");
	for (int i = 0; i < ft_lstsize_int(lst); i++)
		printf("%d\n", (*str)[i]);
	return (global->median);
}