/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 11:10:05 by mballet           #+#    #+#             */
/*   Updated: 2021/01/21 09:26:53 by mballet          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_counti(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (i);
}

int	ft_check_base(char *base)
{
	size_t	i;
	size_t	j;
	size_t	t;

	t = ft_strlen(base);
	i = 0;
	while (i < t - 1)
	{
		j = i + 1;
		while (j < t)
		{
			if (base[i] == base[j])
				return (-1);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (-1);
		i++;
	}
	if (i < 1)
		return (-1);
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;
	int	nb;

	i = ft_counti(base);
	if (ft_check_base(base) != 0)
		return ;
	if (nbr < 0)
	{
		nb = nbr * -1;
		write(1, "-", 1);
		ft_putnbr_base(nbr, base);
	}
	if (nbr < i)
	{
		write(1, &base[nbr % i], 1);
	}
	if (nbr >= i)
	{
		ft_putnbr_base(nbr / i, base);
		ft_putnbr_base(nbr % i, base);
	}
}
