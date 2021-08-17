#include "libft.h"

char	**ft_strdup_double(char **str, int size)
{
	char	**tab;
	int		i;
	int		j;

	tab = NULL;
	tab = malloc(sizeof(char *) * size);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < size)
	{
		tab[i] = (char *)malloc(sizeof(char) * (ft_strlen(str[i]) + 1));
		if (!(tab[i]))
			return (NULL);
		j = 0;
		while (str[i][j])
		{
			tab[i][j] = str[i][j];
			j++;
		}
		tab[i][j] = '\0';
		i++;
	}
	return (tab);
}
