#include <pushswap.h>

static int	find_small_big(t_list *lst, int *small, int *big)
{
	int	small_bis;
	int	i;

	while (lst)
	{
		if ((int)lst->content < *small)
			*small = (int)lst->content;
		if ((int)lst->content > *big)
			*big = (int)lst->content;
		lst = lst->next;
	}
	small_bis = *small;
	i = 0;
	while (small_bis < *big)
	{
		small_bis++;
		i++;
	}
	return ((*small) + (i / 2));
}

void	find_median(t_list *lst, t_global *global)
{
	t_list	*tmp;
	int	small;
	int	big;
	int	over;
	int	median;
	int	i;

	small = INT_MAX;
	big = INT_MIN;
	median = find_small_big(lst, &small, &big);
	printf("small :%d | big :%d | median :%d\n", small, big, median);
	over = 0;
	i = 0;
	while (over == 0)
	// while (i < 10)
	{
		tmp = lst;
		while (lst)
		{
			// printf("content :%d == median :%d || content :%d == median :%d\n",
				// (int)lst->content, median - i, (int)lst->content, median + i);
			if ((int)lst->content == median - i || (int)lst->content == median + i)
			{
				median = (int)lst->content;
				over = 1;
				break;
			}
			lst = lst->next;
		}
		lst = tmp;
		i++;
	}
	global->median = median;
}