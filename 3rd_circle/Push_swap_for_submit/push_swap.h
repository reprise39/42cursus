/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:56:04 by mkuida            #+#    #+#             */
/*   Updated: 2025/01/17 18:38:32 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SET_UNDER 1
# define SET_UPPER 0
# define SERCH_IN_B 0
# define SERCH_IN_A 1

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_command
{
	int	number_of_command;
	int	ar;
	int	arr;
	int	br;
	int	brr;
	int	rr;
	int	rrr;
	int *a_in;
}		t_command;

// initlst
void	set_initlst(int *a_init, int max);
int		sercharr_nextnum(int target, int *x_init, int serchlst);
int		sercharr_beforenum(int target, int *x_init, int serchlst);
int		sercharr_minnum(int lstsize, int *a_init, int serchlst);
int		sercharr_maxnum(int lstsize, int *a_init, int serchlst);

// struct_command
void	refrech_com(t_command *next_com);
void	exac_com_push_to_b(t_command *next_com, t_list **a, t_list **b);
void	exac_com_push_to_a(t_command *next_com, t_list **a, t_list **b);

// check_input
int		check_input(int argc, char **argv);

// lstaddback_and_checkoverlap
t_list	*pushtostack_and_checkoverlap(int argc, char **argv);

// utils.c
int		ft_isspace(int c);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
int		serch_one(t_list **a);

// command_a.c
int		ra(t_list **a, int rr_flag);
int		pa(t_list **a, t_list **b, int *a_init);
int		sa(t_list **a, int ss_flag);
int		rra(t_list **a, int rrr_flag);

// command_b.c
int		rb(t_list **b, int rr_flag);
int		pb(t_list **a, t_list **b, int *a_init);
int		sb(t_list **b, int ss_flag);
int		rrb(t_list **b, int rrr_flag);

// command_r.c
int		ss(t_list **a, t_list **b);
int		rr(t_list **a, t_list **b);
int		rrr(t_list **a, t_list **b);

// for_three.c
void	three_two_one(t_list **a);
void	three_one_two(t_list **a);
void	two_three_one(t_list **a);
void	one_three_two(t_list **a);
void	two_one_three(t_list **a);

// morethan_three.c
void	by_malloc_prep_morethan_three(t_list **a);
void	morethan_three(t_list **a, t_list **b, t_command *next_com);

// morethan_three_algo_ab_r.c
void	pushcomset_firstlst_to_secondlst(t_list **a, t_list **b, t_command *next_com);
void	pushcostcheck_ifsmall_setcommand_base_r(t_list *a, t_list *b, int r_num, t_command *next_com);
void	mk_com_r(t_command *competi, int a_r_num, int b_r_flag, int b_r_num);
void	checkdef_r(t_list *b, int target, int a_r_num, t_command *competi,
			int setnext_or_bef);

// morethan_three_algo_ab_rr.c
void	pushcostcheck_ifsmall_setcommand_base_rr(t_list *a, t_list *b,
			int r_num, t_command *next_com);
void	checkdef_rr(t_list *b, int target, int a_rr_num, t_command *competi,
			int setnext_or_bef);
void	mk_com_rr(t_command *competi, int a_rr_num, int b_rr_flag,
			int b_rr_num);

// morethan_three_algo_ba_r.c
void	rev_pushcomset_firstlst_to_secondlst(t_list **a, t_list **b, t_command *next_com);
void	rev_pushcostcheck_ifsmall_setcommand_base_r(t_list *a, t_list *b, int r_num, t_command *next_com);
void	rev_checkdef_r(t_list *b, int target, int a_r_num, t_command *competi,
			int setnext_or_bef);
void	rev_mk_com_r(t_command *competi, int a_r_num, int b_r_flag,
			int b_r_num);

// morethan_three_algo_ba_rr.c
void	rev_pushcostcheck_ifsmall_setcommand_base_rr(t_list *a, t_list *b,
			int r_num, t_command *next_com);
void	rev_checkdef_rr(t_list *b, int target, int a_rr_num, t_command *competi,
			int setnext_or_bef);
void	rev_mk_com_rr(t_command *competi, int a_rr_num, int b_rr_flag,
			int b_rr_num);

// algo.c
int		check_alreadyok(t_list *a);
void	push_swap_algo(t_list **a);
void	three_lst(t_list **a);
void	two_lst(t_list **a);

// ft_qsort.c
void	ft_intswitch(int *a, int *b);
int		qsort_partition(int *array, int left, int right);
void	ft_qsort(int *array, int left, int right);

// ft_binarysarch.c
int		ft_binarysarch(int *arr, int arrsize, int target);

// push_swap_coodinatecompress.c
int		*ft_sort(int *origin_num, int size);
void	coodinatecompress(t_list *a, int size);
void	*lst_to_arry(t_list *a, int *origin_num);

// for_debag
void	print_t_com(t_command *command);
void	print_list(t_list *a);

#endif