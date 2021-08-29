#include "pushswap.h"

int	add_ope(t_global *global, char *str, int size)
{
	t_list	*new;
	char	*tmp;
	int		i;

	tmp = NULL;
	tmp = malloc(sizeof(char) * size);
	if (!tmp)
		return (0);
	i = 0;
	while (i < size)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = 0;
	new = NULL;
	new = ft_lstnew(tmp);
	if (!new)
		return (0);
	ft_lstadd_back(&global->ope, new);
	return (1);
}