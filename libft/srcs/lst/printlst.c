#include "libft.h"

void	printlst_int(t_list_int *lst)
{
	while (lst != NULL)
	{
		printf("%d\n", (long int)lst->content);
		lst = lst->next;
	}
}