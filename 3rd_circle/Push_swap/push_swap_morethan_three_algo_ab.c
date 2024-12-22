/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_morethan_three_algo.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 02:06:06 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/23 02:07:32 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft_added_ftprintf/libft.h"
# include "push_swap.h"

void mk_com_r(t_command* competi,int a_r_num,int b_r_flag,int b_r_num)
{
	int r;
	int rr;

	if(b_r_flag == 1)
	{
		if(ft_max(a_r_num,b_r_num) < (competi->number_of_command))
		{
			refrech_com_exceptnoc(competi);
			rr = ft_min(a_r_num,b_r_num);
			r = ft_max(a_r_num,b_r_num) - rr;
			(competi->number_of_command) = ft_max(a_r_num,b_r_num);
			(competi->rr) = rr;
			if(a_r_num >= b_r_num)
				(competi->br) =r;
			else
				(competi->ar) =r;
		}
	}
	else if(b_r_flag == 0)
	{
		if((a_r_num + b_r_num) < (competi->number_of_command))
		{
			refrech_com_exceptnoc(competi);
			(competi->ar) = a_r_num;
			(competi->brr) = b_r_num;
			(competi->number_of_command) = a_r_num + b_r_num;
		}
	}
}



void checkdef_r(t_list *b,int target ,int a_r_num,t_command *competi,int setnext_or_bef)
{
	int bsize;
	int def;
	
	bsize = ft_lstsize(b);
	if(setnext_or_bef == 1)
		def = 1;
	else
		def = 0;
	// ft_printf("target = %d\n", target);
	// ft_printf("btop = %d\n", *(int *)(b->content));

	while(*(int *)(b->content) != target)
	{
		b = b->next;
		def++;
	}
	// ft_printf("aa");
	// def++;
	// ft_printf("def == %d\n",def);
	if(def == bsize)
		mk_com_r(competi,a_r_num,1,0);
	else if(def <= (bsize/2))
	{
		mk_com_r(competi,a_r_num,1,def);
	}
	else if(def > (bsize/2))
	{
		if(def - bsize > 0)
			mk_com_r(competi,a_r_num,0,def - bsize);
		else 
			mk_com_r(competi,a_r_num,1,def);
	}
}



void pushcostcheck_ifsmall_setcommand_base_r(t_list *a,t_list *b,int *a_init,int r_num,t_command *next_com)
{
	int i;
	int target;
	int in_b_nextnum;
	int in_b_befnum;
	int in_b_minnum;
	int in_b_maxnum;
	int lstsize;
	
	lstsize = ft_lstsize(a);
	i = 0;
	if(r_num > i)
		a = a->next;
	target = *(int *)(a->content);
	
	int j = 0;
	while(j <= a_init[0])
	{
		// ft_printf("list[%d] = %d \n",j,a_init[j]);
		j++;
	}

	// ft_printf("target = %d \n",target);
	//次の数字との依存関係
	in_b_nextnum = sercharr_nextnum(target,a_init,SERCH_IN_B);
	// ft_printf("in_b_next_num = %d \n",in_b_nextnum);
	// ft_printf("\n checkpoint1 \n");
	if(in_b_nextnum != -1)
	{
		// ft_printf("\n in_b_next_num = %d \n",in_b_nextnum);
		checkdef_r(b,in_b_nextnum,r_num,next_com , SET_UNDER);
		// ft_printf("\n checkpoint2 \n");
	}
	else if(in_b_nextnum == -1)
	{
		// ft_printf("\n in_b_next_num = %d \n",in_b_nextnum);
		in_b_minnum = sercharr_minnum(lstsize,a_init,SERCH_IN_B);
		// ft_printf("\n in_b_min_num = %d \n",in_b_minnum);

		checkdef_r(b,in_b_minnum,r_num,next_com , SET_UNDER);
	}
	//前の数字との依存関係
	// ft_printf("\n checkpoint2 \n");

	in_b_befnum = sercharr_beforenum(target,a_init,SERCH_IN_B);
	// printf("\n in_b_bef_num = %d \n",in_b_befnum);
	if(in_b_befnum != -1)
	{
		checkdef_r(b,in_b_befnum,r_num,next_com, SET_UPPER);
	}
	else if(in_b_befnum == -1)
	{
		in_b_maxnum = sercharr_maxnum(lstsize,a_init,SERCH_IN_B);
		checkdef_r(b,in_b_maxnum,r_num,next_com, SET_UPPER);
	}
}


void pushcomset_firstlst_to_secondlst(t_list **a,t_list **b,int *a_init,t_command *next_com)
{
	int i;
	int cost;
	int cost_min_possi;
	int cost_min;


	//　＜＜ベース側のリストを順回転＞＞
	i = 0;
	// ft_printf("a sentou ha %d \n", *(int *)((*a)->content) );
	// ft_printf("a nibanme ha %d \n", *(int *)(((*a)->next)->content) );

	while(i < ft_lstsize(*a))
	{
		cost = (next_com->number_of_command);
		cost_min_possi = i;
		if(cost > cost_min_possi)
		{
			pushcostcheck_ifsmall_setcommand_base_r(*a,*b,a_init,i,next_com);
		}
		i++;
	}

	//　後で実装　＜＜ベース側のリストを逆回転＞＞
	// i = 0;
	// while(i < ft_lstsize(*a)); // ok
	// {
	// 	cost = (next_com->number_of_command);
	// 	cost_min_possi = i;
	// 	if(cost > cost_min_possi)
	// 		pushcostcheck_ifsmall_setcommand_base_rr(a,b,a_init,i,next_com);
	// 	i++;
	// }
}
