#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/include/libft.h"

#define STR (*str)

typedef struct	s_global
{
	int	nbr_ope;
	int	median;
	int	lst_size;
	int	argc;
	int	*str;
}				t_global;

void	printlst(t_list_int *lst);
void	del(long int *content);
int		get_check_lst(t_list_int **lsta, t_global *global, char **argv);
void	swap(t_list_int **lst, t_global *global);
void	swap_ab(t_list_int **lsta, t_list_int **lstb, t_global *global);
int		push(t_list_int **ontop, t_list_int **from, t_global *global);
void	rotate(t_list_int **lst, t_global *global);
void	rotate_ab(t_list_int **lsta, t_list_int **lstb, t_global *global);
void	rev_rotate(t_list_int **lst, t_global *global);
void	rev_rotate_ab(t_list_int **lsta, t_list_int **lstb, t_global *global);
int		init_global(t_global *global, int argc);
void	free_global(t_global *global);
int		check_double(t_list_int *lst);
int 	sorting(t_list_int **lsta, t_list_int **lstb, t_global *global);
int		find_median(t_list_int *lst, t_global *global, int **str);

#endif
