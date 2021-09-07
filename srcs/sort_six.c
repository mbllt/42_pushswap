#include "pushswap.h"

static int	sort_a(int nbr_sorting, t_list_int **actual, t_global *global, int stack)
{
	long int	big;
	long int	small;

	if (nbr_sorting == 2)
	{
		if (*((*actual)->content) > *((*actual)->next->content))
			if (!swap(actual, global, stack))
				return (0);
		return (1);
	}
	if (!is_sorted_s_to_b(*actual, nbr_sorting))
	{
		big = find_biggest(*actual);
		small = find_smallest(*actual);
		if (small == *((*actual)->content))
		{
			if (!rev_rotate(actual, global, stack))
				return (0);
			if (!swap(actual, global, stack))
				return (0);
			return (1);
		}
		if (small != *((*actual)->content) && big != *((*actual)->content))
		{
			if (small == *((*actual)->next->content))
			{
				if (!swap(actual, global, stack))
					return (0);
			}
			else
			{
				if (!rev_rotate(actual, global, stack))
					return (0);
			}
		}
		if (big == *((*actual)->content))
		{
			if (small == *((*actual)->next->content))
			{		
				if (!rotate(actual, global, stack))
					return (0);
			}
			else
			{
				if (!swap(actual, global, stack))
				return (0);
				if (!rev_rotate(actual, global, stack))
				return (0);
			}
		}
	}
	return (1);
}

static int	sort_b(int nbr_sorting, t_list_int **actual, t_global *global, int stack)
{
	long int	big;
	long int	small;

	if (nbr_sorting == 2)
	{
		if (*((*actual)->content) < *((*actual)->next->content))
			if (!swap(actual, global, stack))
				return (0);
		return (1);
	}
	if (!is_sorted_b_to_s(*actual, nbr_sorting))
	{
		big = find_biggest(*actual);
		small = find_smallest(*actual);
		if (big == *((*actual)->content))
		{
			if (!rev_rotate(actual, global, stack))
				return (0);
			if (!swap(actual, global, stack))
				return (0);
			return (1);
		}
		if (big != *((*actual)->content) && small != *((*actual)->content))
		{
			if (big == *((*actual)->next->content))
			{
				if (!swap(actual, global, stack))
					return (0);
			}
			else
			{
				if (!rev_rotate(actual, global, stack))
					return (0);
			}
		}
		if (small == *((*actual)->content))
		{
			if (big == *((*actual)->next->content))
			{
				if (!rotate(actual, global, stack))
					return (0);
			}
			else
			{
				if (!swap(actual, global, stack))
				return (0);
				if (!rev_rotate(actual, global, stack))
				return (0);
			}
		}
	}
	return (1);
}

static int	push_on_a(t_list_int **lsta, t_list_int **lstb, t_global *global)
{
	int	size;

	size = ft_lstsize_int(*lstb);
	while (size)
	{
		if (!push(lsta, lstb, global, 1))
			return (0);
		size--;
	}
	return (1);
}

int	sort_six(t_list_int **lsta, t_list_int **lstb, t_global *global)
{
	if (global->argc <= 4)
	{
		return (sort_a(global->argc - 1, lsta, global, 0));
	}
	if (!find_median(global->argc - 1, *lsta, global, &(global->str), 0))
		return (0);
	seperate(lsta, lstb, global, global->argc - 1, 0);
	if (!sort_a(ft_lstsize_int(*lsta), lsta, global, 0))
		return (0);
	if (!sort_b(ft_lstsize_int(*lstb), lstb, global, 1))
		return (0);
	if (!push_on_a(lsta, lstb, global))
		return (0);
	if (!check_ope(global))
		return (0);
	return (1);
}