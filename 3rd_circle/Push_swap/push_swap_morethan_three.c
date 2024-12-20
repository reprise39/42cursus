/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_morethan_three.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 04:28:14 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/21 02:54:35 by mkuida           ###   ########.fr       */
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
	ft_printf("target = %d\n", target);
	ft_printf("btop = %d\n", *(int *)(b->content));

	while(*(int *)(b->content) != target)
	{
		b = b->next;
		def++;
	}
	// ft_printf("aa");
	// def++;
	ft_printf("def == %d\n",def);
	if(def == bsize)
		mk_com_r(competi,a_r_num,1,0);
	else if(def < (bsize/2))
	{
		mk_com_r(competi,a_r_num,1,def);
	}
	else if(def > (bsize/2))
	{
		mk_com_r(competi,a_r_num,1,def);
		if(def - bsize > 0)
			mk_com_r(competi,a_r_num,0,def - bsize);
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

		checkdef_r(b,in_b_minnum,r_num,next_com , SET_UPPER);
	}
	//前の数字との依存関係
	// ft_printf("\n checkpoint2 \n");

	// in_b_befnum = sercharr_beforenum(target,a_init,SERCH_IN_B);
	// printf("\n in_b_bef_num = %d \n",in_b_befnum);
	// if(in_b_befnum != -1)
	// {
	// 	checkdef_r(b,in_b_befnum,r_num,next_com, SET_UPPER);
	// }
	// else if(in_b_befnum == -1)
	// {
	// 	in_b_maxnum = sercharr_maxnum(lstsize,a_init,SERCH_IN_B);
	// 	checkdef_r(b,in_b_maxnum,r_num,next_com, SET_UNDER);
	// }
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


void morethan_three(t_list **a)
{
	int i;
	int *a_init;
	int maxint;
	t_list **b;
	t_command *next_com;
	
	b = calloc(sizeof(t_list **),1);
	next_com = calloc(sizeof(t_command *),1);
	
	maxint = ft_lstsize(*a);
	a_init = ft_calloc(sizeof(int),(maxint + 2));
	*b = NULL;
	set_initlst(a_init,maxint);
	
	i = 0;
	while(i < 2 && ft_lstsize(*a) > 3)
	{
		pb(a,b,a_init);
		i++;
	}
	while(ft_lstsize(*a) > 3)
	{

		refrech_com(next_com);
		// ft_printf("%d kaime\n",i);		//kokomadeOK
		// ft_printf("lstsize %d \n",ft_lstsize(*a));
		pushcomset_firstlst_to_secondlst(a,b,a_init,next_com);
		exac_com_push_to_b(next_com,a,b,a_init);

		// print_list(*a);
		// print_list(*b);
		i++;
	}
	three_lst(a);
	ft_printf("   >>> b he idouowari <a> list\n");
	print_list(*a);
	ft_printf("   >>> b he idouowari <b> list\n");
	print_list(*b);

	while(*b != NULL)
	{
		refrech_com(next_com);
		// print_t_com(next_com);
		// ft_printf("%d kaime\n",i);		//kokomadeOK
		// ft_printf("lstsize %d \n",ft_lstsize(*a));
		rev_pushcomset_firstlst_to_secondlst(b,a,a_init,next_com);
		// print_t_com(next_com);
		exac_com_push_to_a(next_com,a,b,a_init);

		// print_list(*a);
		// print_list(*b);
		i++;
	}
}


void rev_pushcomset_firstlst_to_secondlst(t_list **a,t_list **b,int *a_init,t_command *next_com)
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
			rev_pushcostcheck_ifsmall_setcommand_base_r(*a,*b,a_init,i,next_com);
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


void rev_pushcostcheck_ifsmall_setcommand_base_r(t_list *a,t_list *b,int *a_init,int r_num,t_command *next_com)
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
	in_b_nextnum = sercharr_nextnum(target,a_init,SERCH_IN_A);
	// ft_printf("in_b_next_num = %d \n",in_b_nextnum);
	// ft_printf("\n checkpoint1 \n");
	if(in_b_nextnum != -1)
	{
		// ft_printf("\n in_b_next_num = %d \n",in_b_nextnum);
		rev_checkdef_r(b,in_b_nextnum,r_num,next_com , SET_UPPER);
		// ft_printf("\n checkpoint2 \n");
	}
	else if(in_b_nextnum == -1)
	{
		// ft_printf("\n in_b_next_num = %d \n",in_b_nextnum);
		in_b_minnum = sercharr_minnum(lstsize,a_init,SERCH_IN_A);
		// ft_printf("\n in_b_min_num = %d \n",in_b_minnum);

		rev_checkdef_r(b,in_b_minnum,r_num,next_com , SET_UNDER);
	}
	//前の数字との依存関係
	// ft_printf("\n checkpoint2 \n");

	// in_b_befnum = sercharr_beforenum(target,a_init,SERCH_IN_A);
	// printf("\n in_a_bef_num = %d \n",in_b_befnum);
	// if(in_b_befnum != -1)
	// {
	// 	checkdef_r(b,in_b_befnum,r_num,next_com, SET_UNDER);
	// }
	// else if(in_b_befnum == -1)
	// {
	// 	in_b_maxnum = sercharr_maxnum(lstsize,a_init,SERCH_IN_A);
	// 	checkdef_r(b,in_b_maxnum,r_num,next_com, SET_UPPER);
	// }
}


void rev_checkdef_r(t_list *b,int target ,int a_r_num,t_command *competi,int setnext_or_bef)
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
	{
		// ft_printf("def == bsize\n");
		rev_mk_com_r(competi,a_r_num,1,0);
	}
	else if(def < (bsize/2))
	{
		// ft_printf("def < (bsize/2)\n");
		rev_mk_com_r(competi,a_r_num,1,def);
	}
	else if(def > (bsize/2))
	{
		// ft_printf("def > (bsize/2)\n");
		rev_mk_com_r(competi,a_r_num,1,def);
		if(def - bsize > 0)
			rev_mk_com_r(competi,a_r_num,0,def - bsize);
	}
}

void rev_mk_com_r(t_command* competi,int a_r_num,int b_r_flag,int b_r_num)
{
	int r;
	int rr;

	// ft_printf("a_r_num = %d\n",a_r_num);
	// ft_printf("b_r_num = %d\n",b_r_num);
	// ft_printf("b_r_flag = %d\n",b_r_flag);

	
	if(b_r_flag == 1)
	{
		// printf("in_mkcom_1\n");
		if(ft_max(a_r_num,b_r_num) < (competi->number_of_command))
		{
			rr = ft_min(a_r_num,b_r_num);
			r = ft_max(a_r_num,b_r_num) - rr;
			(competi->number_of_command) = ft_max(a_r_num,b_r_num);
			(competi->rr) = rr;
			if(a_r_num >= b_r_num)
				(competi->br) =r;
			else
				(competi->ar) =r;
			// printf("| (competi->number_of_command) = %d\n",(competi->number_of_command));
			// printf("| rr = %d\n",rr);
			// printf("| r = %d\n",r);
			
		}
	}
	else if(b_r_flag == 0)
	{
		// printf("in_mkcom_0\n");
		if((a_r_num + b_r_num) < (competi->number_of_command))
		{
			(competi->ar) = b_r_num;
			(competi->brr) = a_r_num;
			(competi->number_of_command) = a_r_num + b_r_num;
		}
	}
	// print_t_com(competi);
}
