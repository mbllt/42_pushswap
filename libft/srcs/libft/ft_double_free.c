#include "libft.h"

void	ft_double_free(char **str, int size_first, int size_second)
{
	int	i;

	i = 0;
	while (i < size_first)
	{
		if (str[i])
			free(str[i]);
	}
	if (str)
		free(str);
	str = NULL;
}
