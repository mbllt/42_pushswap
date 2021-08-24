#include "pushswap.h"

static void	fill_in_str(t_list_int *actual, int **str, int nbr_sorting)
{
	t_list_int	*tmp;
	int	i;

	tmp = actual;
	i = 0;
	while (i < nbr_sorting)
	{
		STR[i] = *(tmp->content);
		// printf("str[%d] :%d\n", i, STR[i]);
		tmp = tmp->next;
		i++;
	}
	STR[i] = 0;
}

static int	sort_str(int **str, int nbr_sorting)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while(i < nbr_sorting)
	{
		j = i + 1;
		while (j < nbr_sorting)
		{
			if (STR[i] > STR[j])
			{
				tmp = STR[i];
				STR[i] = STR[j];
				STR[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	find_median(int nbr_sorting, t_list_int *actual, t_global *global, int **str)
{
	int	size;
	int	nbr;

	// printf("nbr_sorting %d\n", nbr_sorting);
	fill_in_str(actual, str, nbr_sorting);
	if (!(sort_str(str, nbr_sorting)))
		return (0);
	printf("STR : ");
	for (int i = 0;i < nbr_sorting;i++)
		printf("%d, ", (*str)[i]);
	printf("\n");
	size = nbr_sorting;
	nbr = size / 2;
	global->median = (*str)[nbr];
	// printf("median :%d\n", global->median);
	if (size % 2)
		global->median--;
	// printf("median :%d\n", global->median);
	return (1);
}