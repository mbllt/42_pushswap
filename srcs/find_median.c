#include "pushswap.h"

static void	fill_in_str(t_list_int *actual, int **str, int nbr_sorting)
{
	t_list_int	*tmp;
	int	i;
	int	j;

	tmp = actual;
	i = 0;
	j = 0;
	while (j < nbr_sorting)
	{
		STR[i] = *(tmp->content);
		tmp = tmp->next;
		i++;
		j++;
	}
	STR[i] = 0;
}

static int	sort_str(int **str, int nbr_sorting)
{
	// int	*tmp;
	int	i;
	int	j;
	int	c;

	// tmp = malloc(sizeof(char) * nbr_sorting + 1);
	// if (!tmp)
	// 	return (NULL);
	i = 0;
	while(i < nbr_sorting)
	{
		j = i + 1;
		while (j < nbr_sorting)
		{
			if (STR[i] < STR[j])
			{
				c = STR[i];
				STR[i] = STR[j];
				STR[j] = c;
			}
			j++;
		}
		i++;
	}
	for (int l = 0;l < nbr_sorting;l++)
		printf("str :%d\n", STR[l]);
	return (1);
}

int	find_median(int nbr_sorting, t_list_int *actual, t_global *global, int **str)
{
	int	size;
	int	nbr;

	fill_in_str(actual, str, nbr_sorting);
	// printf("nbr_sorting %d\n", nbr_sorting);
	if (!(sort_str(str, nbr_sorting)))
		return (0);
	// for (int i = 0;i < nbr_sorting;i++)
	// 	printf("str : %d\n", (*str)[i]);
	size = nbr_sorting;
	nbr = size / 2;
	global->median = (*str)[nbr];
	if (size / 2)
		global->median--;
	//printf("median :%d\n", global->median);
	return (1);
}