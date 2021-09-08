#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/include/libft.h"

#define STR (*str)

typedef struct	s_global
{
	int			nbr_ope;
	int			median;
	int			lst_size;
	int			argc;
	int			*str;
	int			changed;
	int			nbr_sort;
	t_list		*ope;
	t_list_int	tmp;
	int			nbr;
}				t_global;

void		printlst(t_list_int *lst);
void		del_int(long int *content);
void		del(void *content);
int			get_check_lst(t_list_int **lsta, t_global *global, char **argv);
int			swap(t_list_int **lst, t_global *global, int stack);
int			swap_ab(t_list_int **lsta, t_list_int **lstb, t_global *global);
int			push(t_list_int **ontop, t_list_int **from, t_global *global, int stack);
int			rotate(t_list_int **lst, t_global *global, int stack);
int			rotate_ab(t_list_int **lsta, t_list_int **lstb, t_global *global);
int			rev_rotate(t_list_int **lst, t_global *global, int stack);
int			rev_rotate_ab(t_list_int **lsta, t_list_int **lstb, t_global *global);
int			init_global(t_global *global, int argc);
void		free_global(t_global *global);
int			check_double(t_list_int *lst);
int 		sorting(t_list_int **lsta, t_list_int **lstb, t_global *global, int stack);
int			find_median(t_list_int *lst, t_global *global, int stack);
short int	clear(t_list_int **lsta, t_list_int **lstb, t_global *global, int i);
int			seperate(t_list_int **actual, t_list_int **other, t_global *global, int stack);
int long	find_biggest(t_list_int *lst);
int long	find_smallest(t_list_int *lst);
int			is_sorted_s_to_b(t_list_int *lst, int nbr_sorting);
int			is_sorted_b_to_s(t_list_int *lst, int nbr_sorting);
int			add_ope(t_global *global, char *str, int size);
int			sort_six(t_list_int **lsta, t_list_int **lstb, t_global *global);
int			check_ope(t_global *global);
void		print_ope(t_global *global);

#endif
