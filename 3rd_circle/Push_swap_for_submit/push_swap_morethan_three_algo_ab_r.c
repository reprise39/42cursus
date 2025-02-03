/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_morethan_three_algo_ab_r.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 02:06:06 by mkuida            #+#    #+#             */
/*   Updated: 2025/02/03 18:37:06 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_added_ftprintf/libft.h"
#include "push_swap.h"

static void	mk_com_r_flag_off(t_command *competi, int a_r_num, int b_r_num);

void	pushcomset_firstlst_to_secondlst(t_list **a, t_list **b,
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
			pushcostcheck_ifsmall_setcommand_base_r(*a, *b, i, next_com);
		i++;
	}
	i = 1;
	while (i < ft_lstsize(*a))
	{
		cost = (next_com->number_of_command);
		cost_min_possi = i;
		if (cost > cost_min_possi)
			pushcostcheck_ifsmall_setcommand_base_rr(*a, *b, i, next_com);
		i++;
	}
}

void	pushcostcheck_ifsmall_setcommand_base_r(t_list *a, t_list *b, int r_num,
		t_command *next_com)
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
	in_b_nextnum = sercharr_nextnum(target, (next_com->a_in), SERCH_IN_B);
	next_com->r_setnext_or_bef = SET_UNDER;
	if (in_b_nextnum != -1)
	{
		checkdef_r(b, in_b_nextnum, r_num, next_com);
	}
	else if (in_b_nextnum == -1)
	{
		in_b_minnum = sercharr_minnum(lstsize, (next_com->a_in), SERCH_IN_B);
		checkdef_r(b, in_b_minnum, r_num, next_com);
	}
}

void	checkdef_r(t_list *b, int target, int a_r_num, t_command *competi)
{
	int	bsize;
	int	def;

	bsize = ft_lstsize(b);
	if (competi->r_setnext_or_bef == 1)
		def = 1;
	else
		def = 0;
	while (*(int *)(b->content) != target)
	{
		b = b->next;
		def++;
	}
	if (def == bsize)
		mk_com_r(competi, a_r_num, 1, 0);
	else if (def <= (bsize / 2))
	{
		mk_com_r(competi, a_r_num, 1, def);
	}
	else if (def > (bsize / 2))
	{
		if (bsize - def > 0)
			mk_com_r(competi, a_r_num, 0, bsize - def);
	}
}

void	mk_com_r(t_command *competi, int a_r_num, int b_r_flag, int b_r_num)
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
				(competi->ar) = r;
			else
				(competi->br) = r;
		}
	}
	else if (b_r_flag == 0)
	{
		mk_com_r_flag_off(competi, a_r_num, b_r_num);
	}
}

static void	mk_com_r_flag_off(t_command *competi, int a_r_num, int b_r_num)
{
	if ((a_r_num + b_r_num) < (competi->number_of_command))
	{
		refrech_com(competi);
		(competi->ar) = a_r_num;
		(competi->brr) = b_r_num;
		(competi->number_of_command) = a_r_num + b_r_num;
	}
}
