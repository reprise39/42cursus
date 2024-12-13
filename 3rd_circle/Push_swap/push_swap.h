/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:56:04 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/14 04:13:17 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

//check_input.c
int check_input(int argc,char **argv);
//lstaddback_and_checkoverlap
t_list *pushtostack_and_checkoverlap(int argc,char **argv);
// utils.c
int	ft_isspace(int c);
// command_a.c
int ra(t_list **a,int rr_flag);
int pa(t_list **a, t_list **b);
int sa(t_list **a,int ss_flag);
int rra(t_list **a,int rrr_flag);
// command_b.c
int rb(t_list **b,int rr_flag);
int pb(t_list **a, t_list **b);
int sb(t_list **b,int ss_flag);
int rrb(t_list **b,int rrr_flag);
// command_r.c
int ss(t_list** a, t_list **b);
int rr(t_list **a, t_list **b);
int rrr(t_list** a, t_list **b);
// for_three
void three_two_one(t_list **a);
void three_one_two(t_list **a);
void two_three_one(t_list **a);
void one_three_two(t_list **a);
void two_one_three(t_list **a);
//algo
void push_swap_algo(t_list **a);
void three_lst(t_list **a);
void two_lst(t_list **a);

//ft_qsort
void ft_intswitch(int *a,int *b);
int qsort_partition(int *array,int left,int right);
void ft_qsort(int *array,int left,int right);
//ft_binarysarch
int ft_binarysarch(int *arr,int arrsize,int target);

#endif