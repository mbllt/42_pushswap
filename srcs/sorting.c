#include "pushswap.h"

static int	is_sorted(t_list_int *actual)
{
	return ((*(actual->content) < *(actual->next->content) &&
			*(actual->next->content) < *(actual->next->next->content)));
}

static void	sort(t_list_int **actual, t_global *global, int nbr_sorting)
{
	long int	biggest;

	if (nbr_sorting == 2)
	{
		if ((*actual)->content > (*actual)->next->content)
			swap(actual, global);
		return ;
	}
	biggest = *((*actual)->content);
	if (biggest < *((*actual)->next->content))
		biggest = *((*actual)->next->content);
	if (biggest < *((*actual)->next->next->content))
		biggest = *((*actual)->next->next->content);
	while (!is_sorted(*actual))
	{
		if (!is_sorted(*actual)
			&& *((*actual)->next->content) != biggest)
			swap(actual, global);
		if (!is_sorted(*actual))
			rev_rotate(actual, global);
	}
	return ;
}

int sorting(int nbr_sorting, t_list_int **actual, t_list_int **other, t_global *global)
{
	if (nbr_sorting <= 3)
	{
		sort(actual, global, nbr_sorting);
		return (1);
	}
	find_median(*actual, global, &(global->str));
	if (global->argc % 2)
	{
		global->median--;
		/* send actual des lst->content plus petit que mediane */
		(void)other;
	}
	else
	{
		/* send actual des lst->content plus petit que mediane et mediane
		donc pas meme nombre dans actual et other */
	}
	printf("median :%d\n", global->median);
	printf("nbr_sorting :%d\n", nbr_sorting);
    return (1);
}