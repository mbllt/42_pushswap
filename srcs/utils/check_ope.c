/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ope.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mballet <mballet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:50:13 by mballet           #+#    #+#             */
/*   Updated: 2021/09/08 14:48:56 by mballet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	add_lst(t_list **lst, char *str, int size)
{
	t_list	*tmp_nnn;
	char	*tmp_c;
	int		i;

	tmp_nnn = NULL;
	tmp_nnn = (*lst)->next->next->next;
	tmp_c = NULL;
	tmp_c = malloc(sizeof(char) * size);
	if (!tmp_c)
		return (0);
	i = 0;
	while (i < size)
	{
		tmp_c[i] = str[i];
		i++;
	}
	tmp_c[i] = 0;
	free((*lst)->next->content);
	(*lst)->next->content = tmp_c;
	ft_lstdelone((*lst)->next->next, del);
	(*lst)->next->next = tmp_nnn;
	return (1);
}

static void	supress_two(t_list **lst, t_list *tmp_nnn)
{
	ft_lstdelone((*lst)->next->next, del);
	ft_lstdelone((*lst)->next, del);
	(*lst)->next = tmp_nnn;
}

static int	add_and_supress(t_list **lst, char *str_n)
{
	t_list	*tmp_nnn;

	tmp_nnn = NULL;
	tmp_nnn = (*lst)->next->next->next;
	if (!ft_strncmp((const char *)str_n, (const char *)"sa", 2))
	{
		if (!add_lst(lst, "ss", 2))
			return (0);
	}
	else if (!ft_strncmp((const char *)str_n, (const char *)"ra", 2))
	{
		if (!add_lst(lst, "rr", 2))
			return (0);
	}
	else if (!ft_strncmp((const char *)str_n, (const char *)"rra", 3))
	{
		if (!add_lst(lst, "rrr", 3))
			return (0);
	}
	else
	{
		supress_two(lst, tmp_nnn);
	}
	return (1);
}

static int	check(char *str_n, char *str_nn)
{
	if (!ft_strncmp((const char *)str_n, (const char *)"ra", 2)
		&& !ft_strncmp((const char *)str_nn, (const char *)"rra", 3))
		return (0);
	if (!ft_strncmp((const char *)str_n, (const char *)"rb", 2)
		&& !ft_strncmp((const char *)str_nn, (const char *)"rrb", 3))
		return (0);
	if (!ft_strncmp((const char *)str_n, (const char *)"ra", 2)
		&& !ft_strncmp((const char *)str_nn, (const char *)"rb", 2))
		return (0);
	if (!ft_strncmp((const char *)str_n, (const char *)"rra", 2)
		&& !ft_strncmp((const char *)str_nn, (const char *)"rrb", 3))
		return (0);
	if (!ft_strncmp((const char *)str_n, (const char *)"sa", 2)
		&& !ft_strncmp((const char *)str_nn, (const char *)"sb", 2))
		return (0);
	if (!ft_strncmp((const char *)str_n, (const char *)"pa", 2)
		&& !ft_strncmp((const char *)str_nn, (const char *)"pb", 2))
		return (0);
	if (!ft_strncmp((const char *)str_n, (const char *)"pb", 2)
		&& !ft_strncmp((const char *)str_nn, (const char *)"pa", 2))
		return (0);
	return (1);
}

int	check_ope(t_global *global)
{
	char	*str_n;
	char	*str_nn;
	t_list	*tmp;

	tmp = global->ope;
	while (global->ope && global->ope->next && global->ope->next->next)
	{
		str_n = (char *)global->ope->next->content;
		str_nn = (char *)global->ope->next->next->content;
		if (!check(str_n, str_nn))
		{
			if (!add_and_supress(&(global->ope), str_n))
				return (0);
		}
		global->ope = global->ope->next;
	}
	global->ope = tmp;
	return (1);
}
