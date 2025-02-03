/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_morethan_three_algo_ab_rr.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 02:06:06 by mkuida            #+#    #+#             */
/*   Updated: 2025/02/03 18:25:46 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_added_ftprintf/libft.h"
#include "push_swap.h"

static void	mk_com_rr_flag_off(t_command *competi, int a_rr_num, int b_rr_num);

void	pushcostcheck_ifsmall_setcommand_base_rr(t_list *a, t_list *b,
		int r_num, t_command *next_com)
{
	int			i;
	int			target;
	int			in_b_nextnum;
	int			in_b_minnum;
	const int	lstsize = ft_lstsize(a);

	i = 0;
	while (r_num + i < lstsize)
	{
		a = a->next;
		i++;
	}
	target = *(int *)(a->content);
	in_b_nextnum = sercharr_nextnum(target, (next_com->a_in), SERCH_IN_B);
	if (in_b_nextnum != -1)
	{
		next_com->rr_setnext_or_bef = SET_UNDER;
		checkdef_rr(b, in_b_nextnum, r_num, next_com);
	}
	else if (in_b_nextnum == -1)
	{
		in_b_minnum = sercharr_minnum(lstsize, (next_com->a_in), SERCH_IN_B);
		next_com->rr_setnext_or_bef = SET_UNDER;
		checkdef_rr(b, in_b_minnum, r_num, next_com);
	}
}

void	checkdef_rr(t_list *b, int target, int a_rr_num, t_command *competi)
{
	int	bsize;
	int	def;

	bsize = ft_lstsize(b);
	if (competi->rr_setnext_or_bef == 1)
		def = 1;
	else
		def = 0;
	while (*(int *)(b->content) != target)
	{
		b = b->next;
		def++;
	}
	if (def == bsize)
		mk_com_rr(competi, a_rr_num, 1, 0);
	else if (def <= (bsize / 2))
	{
		mk_com_rr(competi, a_rr_num, 0, def);
	}
	else if (def > (bsize / 2))
	{
		if (bsize - def > 0)
			mk_com_rr(competi, a_rr_num, 1, bsize - def);
	}
}

void	mk_com_rr(t_command *competi, int a_rr_num, int b_rr_flag, int b_rr_num)
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
				(competi->arr) = rr;
			else
				(competi->brr) = rr;
		}
	}
	else if (b_rr_flag == 0)
	{
		mk_com_rr_flag_off(competi, a_rr_num, b_rr_num);
	}
}

static void	mk_com_rr_flag_off(t_command *competi, int a_rr_num, int b_rr_num)
{
	if ((a_rr_num + b_rr_num) < (competi->number_of_command))
	{
		refrech_com(competi);
		(competi->arr) = a_rr_num;
		(competi->br) = b_rr_num;
		(competi->number_of_command) = a_rr_num + b_rr_num;
	}
}
