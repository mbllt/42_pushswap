#include "libft.h"

void	printlst(t_list *lst)
{
	while (lst != NULL)
	{
		printf("%d\n", (int)lst->content);
		lst = lst->next;
	}
}