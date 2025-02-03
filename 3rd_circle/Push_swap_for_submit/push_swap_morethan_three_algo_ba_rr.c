/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_morethan_three_algo_ba_rr.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 02:09:23 by mkuida            #+#    #+#             */
/*   Updated: 2025/02/03 18:35:27 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_added_ftprintf/libft.h"
#include "push_swap.h"

static void	rev_mk_com_rr_flag_off(t_command *competi, int a_rr_num,
				int b_rr_num);

void	rev_pushcostcheck_ifsmall_setcommand_base_rr(t_list *a, t_list *b,
		int r_num, t_command *next_com)
{
	int			i;
	int			target;
	int			in_a_nextnum;
	int			in_a_minnum;
	const int	lstsize = ft_lstsize(a);

	i = 0;
	while (r_num + i < lstsize)
	{
		a = a->next;
		i++;
	}
	target = *(int *)(a->content);
	next_com->rev_rr_setnext_or_bef = SET_UPPER;
	in_a_nextnum = sercharr_nextnum(target, (next_com->a_in), SERCH_IN_A);
	if (in_a_nextnum != -1)
	{
		rev_checkdef_rr(b, in_a_nextnum, r_num, next_com);
	}
	else if (in_a_nextnum == -1)
	{
		in_a_minnum = sercharr_minnum(lstsize, (next_com->a_in), SERCH_IN_A);
		rev_checkdef_rr(b, in_a_minnum, r_num, next_com);
	}
}

void	rev_checkdef_rr(t_list *b, int target, int a_rr_num, t_command *competi)
{
	int	bsize;
	int	def;

	bsize = ft_lstsize(b);
	if (competi->rev_rr_setnext_or_bef == 1)
		def = 1;
	else
		def = 0;
	while (*(int *)(b->content) != target)
	{
		b = b->next;
		def++;
	}
	if (def == bsize)
		rev_mk_com_rr(competi, a_rr_num, 1, 0);
	else if (def <= (bsize / 2))
		rev_mk_com_rr(competi, a_rr_num, 0, def);
	else if (def > (bsize / 2))
	{
		if (bsize - def > 0)
			rev_mk_com_rr(competi, a_rr_num, 1, bsize - def);
		else
			mk_com_rr(competi, a_rr_num, 1, def);
	}
}

void	rev_mk_com_rr(t_command *competi, int a_rr_num, int b_rr_flag,
		int b_rr_num)
{
	int	rr;
	int	rrr;

	if (b_rr_flag == 1)
	{
		if (ft_max(a_rr_num, b_rr_num) < (competi->number_of_command))
		{
			refrech_com(competi);
			rrr = ft_min(a_rr_num, b_rr_num);
			rr = ft_max(a_rr_num, b_rr_num) - rrr;
			(competi->number_of_command) = ft_max(a_rr_num, b_rr_num);
			(competi->rrr) = rrr;
			if (a_rr_num >= b_rr_num)
				(competi->brr) = rr;
			else
				(competi->arr) = rr;
		}
	}
	else if (b_rr_flag == 0)
	{
		rev_mk_com_rr_flag_off(competi, a_rr_num, b_rr_num);
	}
}

static void	rev_mk_com_rr_flag_off(t_command *competi, int a_rr_num,
		int b_rr_num)
{
	if ((a_rr_num + b_rr_num) < (competi->number_of_command))
	{
		refrech_com(competi);
		(competi->brr) = a_rr_num;
		(competi->ar) = b_rr_num;
		(competi->number_of_command) = a_rr_num + b_rr_num;
	}
}
