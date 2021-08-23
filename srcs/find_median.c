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

static int	*rotate_str(int **str, int i, int j, int nbr_sorting)
{
	int	*tmp;
	int	len;

	tmp = malloc(sizeof(char) * nbr_sorting + 1);
	if (!tmp)
		return (NULL);
	len = 0;
	while (len < j)
	{
		tmp[len] = STR[len];
		len++;
	}
	tmp[len] = STR[i];
	printf("str[j] %d\n", STR[j]);
	len = j + 1;
	while (j < i)
	{
		tmp[len] = STR[j];
		len++;
		j++;
	}
	while (len < nbr_sorting)
	{
		tmp[len] = STR[len];
		len++;
	}
	tmp[len] = 0;
	// free(*str);
	// for (int i = 0;i < nbr_sorting;i++)
	// 	printf("tmp : %d\n", tmp[i]);
	return (tmp);
}

static int	sort_str(int **str, int nbr_sorting)
{
	int	*tmp;
	int	i;
	int	j;
	int	small;

	tmp = malloc(sizeof(char) * nbr_sorting + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	small = STR[i];
	while(i < nbr_sorting)
	{
		j = 0;
		while (j < nbr_sorting)
		{
			if (STR[j] < small)
				small = STR[j];
			j++;
		}
		tmp[i] = small;
		i++;
	}
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