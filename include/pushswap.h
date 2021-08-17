#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct	s_global
{
	int		nbr_ope;
	int		median;
	int		lst_size;
	int		argc;
	char	**argv;
}				t_global;

void	printlst(t_list *lst);
void	del(void *content);
int		get_check_lst(t_list **lsta, t_list **lstb, t_global *global);
void	swap(t_list **lst, t_global *global);
void	swap_ab(t_list **lsta, t_list **lstb, t_global *global);
int		push(t_list **ontop, t_list **from, t_global *global);
void	rotate(t_list **lst, t_global *global);
void	rotate_ab(t_list **lsta, t_list **lstb, t_global *global);
void	rev_rotate(t_list **lst, t_global *global);
void	rev_rotate_ab(t_list **lsta, t_list **lstb, t_global *global);
int		sort(t_list **lsta, t_list **lstb, t_global *global);
int		init_global(t_global *global, int argcc, char **argv);
void	free_global(t_global *global);
int		check_double(t_list *lst);
void	sorting(t_list *lst, t_global *global);

#endif
