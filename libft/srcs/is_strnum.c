#include "libft.h"

int	is_strnum(char *str)
{
	int	size;

	if (str)
	{
		size = ft_strlen(str);
		while (--size >= 0)
		{
			if ((!(ft_isdigit(str[size])) && str[size] != '-') || 
				(!(ft_isdigit(str[size])) && str[size] == '-' && size != 0))
				return (0);
		}
		return (1);
	}
	return (0);
}