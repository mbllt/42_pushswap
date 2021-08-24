#include "pushswap.h"

int long	find_biggest(t_list_int *lst)
{
	long big;

	big = *(lst->content);
	if (big < *(lst->next->content))
		big =  *(lst->next->content);
	if (big < *(lst->next->next->content))
		big =  *(lst->next->next->content);
	return (big);
}

int long	find_smallest(t_list_int *lst)
{
	long small;

	small = *(lst->content);
	if (small > *(lst->next->content))
		small =  *(lst->next->content);
	if (small > *(lst->next->next->content))
		small =  *(lst->next->next->content);
	return (small);
}