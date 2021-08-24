#include "pushswap.h"

static void	sort_a(t_list_int **actual, t_global *global, int nbr_sorting)
{
	long int	big;
	long int	small;

	printf("content avant a 0 :%ld\n", *((*actual)->content));
	printf("content avant a 1 :%ld\n", *((*actual)->next->content));
	printf("content avant a 2 :%ld\n", *((*actual)->next->next->content));
	if (nbr_sorting == 2)
	{
		if ((*actual)->content > (*actual)->next->content)
			swap(actual, global);
		return ;
	}
	if (!is_sorted_s_to_b(*actual, nbr_sorting))
	{
		big = find_biggest(*actual);
		small = find_smallest(*actual);
		if (small == *((*actual)->next->content) && big == *((*actual)->next->next->content))
		{
			swap(actual, global);
			return ;
		}
		if (big == *((*actual)->content))
			swap(actual, global);
		rotate(actual, global);
		swap(actual, global);
		rev_rotate(actual, global);
		if (small != *((*actual)->content))
			swap(actual, global);
	}
	printf("content apres a 0 :%ld\n", *((*actual)->content));
	printf("content apres a 1 :%ld\n", *((*actual)->next->content));
	printf("content apres a 2 :%ld\n", *((*actual)->next->next->content));
}

static void	sort_b(t_list_int **actual, t_global *global, int nbr_sorting)
{
	long int	big;
	long int	small;

	printf("content avant b 0 :%ld\n", *((*actual)->content));
	printf("content avant b 1 :%ld\n", *((*actual)->next->content));
	printf("content avant b 2 :%ld\n", *((*actual)->next->next->content));
	if (nbr_sorting == 2)
	{
		if (*((*actual)->content) < *((*actual)->next->content))
			swap(actual, global);
		return ;
	}
	if (!is_sorted_b_to_s(*actual, nbr_sorting))
	{
		big = find_biggest(*actual);
		small = find_smallest(*actual);
		if (big == *((*actual)->next->content) && small == *((*actual)->next->next->content))
		{
			swap(actual, global);
			return ;
		}
		if (small == *((*actual)->content))
			swap(actual, global);
		rotate(actual, global);
		swap(actual, global);
		rev_rotate(actual, global);
		if (big != *((*actual)->content))
			swap(actual, global);
	}
	printf("content apres b 0 :%ld\n", *((*actual)->content));
	printf("content apres b 1 :%ld\n", *((*actual)->next->content));
	printf("content apres b 2 :%ld\n", *((*actual)->next->next->content));
}

static void	stack_on_a(t_list_int **actual, t_list_int **other, int nbr_sorting, t_global *global)
{
	int	i;

	i = 0;
	while (i < nbr_sorting)
	{
		push(other, actual, global);
		i++;
	}
}

int sorting(int nbr_sorting, t_list_int **actual, t_list_int **other, t_global *global, int stack)
{
	global->stack = stack;
	printf("LIST actual : ");
	printlst_int(*actual);
	printf("LIST other : ");
	printlst_int(*other);
	printf("nbr_sorting :%d\n", nbr_sorting);
	if (nbr_sorting <= 3)
	{
		if (stack == 1)
		{
			sort_b(actual, global, nbr_sorting);
			stack_on_a(actual, other, nbr_sorting, global);
		}
		else
			sort_a(actual, global, nbr_sorting);
		return (1);
	}
	if (!(find_median(nbr_sorting, *actual, global, &(global->str))))
		return (0);
	printf("median %d\n", global->median);
	// for (int i = 0;i < nbr_sorting;i++)
	// 	printf("str : %d\n", global->str[i]);
	if (nbr_sorting !=  3)
		seperate(actual, other, global, nbr_sorting, stack);
	// printf("nbr_sorting %d et mediane %d\n", nbr_sorting, global->median);
	// printf("printf lst a:\n");
	// printlst_int(*actual);
	// printf("printf lst b:\n");
	// printlst_int(*other);
	if ((global->argc - 1) % 2)	/* odd */
	{
		(void)other;
	}
	else					/* pair */
	{
		if (stack == 0)
			sorting(nbr_sorting / 2, actual, other, global, 0);
		else
			sorting(nbr_sorting / 2, other, actual, global, 0);
		if (stack == 0)
			sorting(nbr_sorting / 2, other, actual, global, 1);
		else
			sorting(nbr_sorting / 2, actual, other, global, 1);
		// printf("nbr_sorting :%d\n", nbr_sorting);
		/* send actual des lst->content plus petit que mediane et mediane
		donc pas meme nombre dans actual et other */
	}
	//printf("nbr_sorting / 2 :%d\n", nbr_sorting / 2);
    return (1);
}