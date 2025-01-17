/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_morethan_three_algo_ba_r.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 02:09:23 by mkuida            #+#    #+#             */
/*   Updated: 2025/01/17 18:55:18 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_added_ftprintf/libft.h"
#include "push_swap.h"

static void	rev_mk_com_r_flag_off(t_command *competi, int a_r_num, int b_r_num);

void	rev_pushcomset_firstlst_to_secondlst(t_list **a, t_list **b,
		t_command *next_com)
{
	int	i;
	int	cost;
	int	cost_min_possi;
	int	cost_min;

	i = 0;
	while (i < ft_lstsize(*a))
	{
		cost = (next_com->number_of_command);
		cost_min_possi = i;
		if (cost > cost_min_possi)
		{
			rev_pushcostcheck_ifsmall_setcommand_base_r(*a, *b, i, next_com);
		}
		i++;
	}
	i = 1;
	while (i < ft_lstsize(*a))
	{
		cost = (next_com->number_of_command);
		cost_min_possi = i;
		if (cost > cost_min_possi)
			rev_pushcostcheck_ifsmall_setcommand_base_rr(*a, *b, i, next_com);
		i++;
	}
}

void	rev_pushcostcheck_ifsmall_setcommand_base_r(t_list *a, t_list *b,
		int r_num, t_command *next_com)
{
	int	i;
	int	target;
	int	in_b_nextnum;
	int	in_b_minnum;
	int	lstsize;

	lstsize = ft_lstsize(a);
	i = 0;
	while (r_num > i)
	{
		a = a->next;
		i++;
	}
	target = *(int *)(a->content);
	in_b_nextnum = sercharr_nextnum(target, (next_com->a_in), SERCH_IN_A);
	if (in_b_nextnum != -1)
		rev_checkdef_r(b, in_b_nextnum, r_num, next_com, SET_UPPER);
	else if (in_b_nextnum == -1)
	{
		in_b_minnum = sercharr_minnum(lstsize, (next_com->a_in), SERCH_IN_A);
		rev_checkdef_r(b, in_b_minnum, r_num, next_com, SET_UPPER);
	}
}

void	rev_checkdef_r(t_list *b, int target, int a_r_num, t_command *competi,
		int setnext_or_bef)
{
	int	bsize;
	int	def;

	bsize = ft_lstsize(b);
	if (setnext_or_bef == 1)
		def = 1;
	else
		def = 0;
	while (*(int *)(b->content) != target)
	{
		b = b->next;
		def++;
	}
	if (def == bsize)
		rev_mk_com_r(competi, a_r_num, 1, 0);
	else if (def <= (bsize / 2))
		rev_mk_com_r(competi, a_r_num, 1, def);
	else if (def > (bsize / 2))
	{
		if (bsize - def > 0)
			rev_mk_com_r(competi, a_r_num, 0, bsize - def);
		else
			rev_mk_com_r(competi, a_r_num, 1, def);
	}
}

void	rev_mk_com_r(t_command *competi, int a_r_num, int b_r_flag, int b_r_num)
{
	int	r;
	int	rr;

	if (b_r_flag == 1)
	{
		if (ft_max(a_r_num, b_r_num) < (competi->number_of_command))
		{
			refrech_com(competi);
			rr = ft_min(a_r_num, b_r_num);
			r = ft_max(a_r_num, b_r_num) - rr;
			(competi->number_of_command) = ft_max(a_r_num, b_r_num);
			(competi->rr) = rr;
			if (a_r_num >= b_r_num)
				(competi->br) = r;
			else
				(competi->ar) = r;
		}
	}
	else if (b_r_flag == 0)
	{
		rev_mk_com_r_flag_off(competi, a_r_num, b_r_num);
	}
}

static void	rev_mk_com_r_flag_off(t_command *competi, int a_r_num, int b_r_num)
{
	if ((a_r_num + b_r_num) < (competi->number_of_command))
	{
		refrech_com(competi);
		(competi->br) = a_r_num;
		(competi->arr) = b_r_num;
		(competi->number_of_command) = a_r_num + b_r_num;
	}
}
