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
	int	changed;
}				t_global;

void		printlst(t_list_int *lst);
void		del(long int *content);
int			get_check_lst(t_list_int **lsta, t_global *global, char **argv);
void		swap(t_list_int **lst, t_global *global, int stack);
void		swap_ab(t_list_int **lsta, t_list_int **lstb, t_global *global);
int			push(t_list_int **ontop, t_list_int **from, t_global *global, int stack);
void		rotate(t_list_int **lst, t_global *global, int stack);
void		rotate_ab(t_list_int **lsta, t_list_int **lstb, t_global *global);
void		rev_rotate(t_list_int **lst, t_global *global, int stack);
void		rev_rotate_ab(t_list_int **lsta, t_list_int **lstb, t_global *global);
int			init_global(t_global *global, int argc);
void		free_global(t_global *global);
int			check_double(t_list_int *lst);
int 		sorting(int nbr_sorting, t_list_int **lsta, t_list_int **lstb, t_global *global, int stack);
int			find_median(int nbr_sorting, t_list_int *lst, t_global *global, int **str, int stack);
short int	clear(t_list_int **lsta, t_list_int **lstb, t_global *global, int i);
void		seperate(t_list_int **actual, t_list_int **other, t_global *global, int nbr_sorting, int stack);
int long	find_biggest(t_list_int *lst);
int long	find_smallest(t_list_int *lst);
int			is_sorted_s_to_b(t_list_int *lst, int nbr_sorting);
int			is_sorted_b_to_s(t_list_int *lst, int nbr_sorting);

#endif
