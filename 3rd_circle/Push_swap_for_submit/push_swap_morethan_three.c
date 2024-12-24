/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_morethan_three.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 04:28:14 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/24 19:12:38 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft_added_ftprintf/libft.h"
# include "push_swap.h"

static void push_twice_unless_asize_lessthanthree(t_list **a,t_list **b,int *a_init);
static void push_to_b_until_asize_three(t_list **a,t_list **b,t_command *next_com,int *a_init);
static void rotate_one_to_top(t_list **a);

void by_malloc_prep_morethan_three(t_list **a)
{
	t_list **b;
	t_command *next_com;
	int *a_init;
	const int maxint = ft_lstsize(*a);
	
	b = malloc(sizeof(t_list *));
	if( b == NULL)
		return;
	*b = NULL;
	next_com = malloc(sizeof(t_command));
	if(next_com == NULL)
	{
		free(b);
		return;
	}
	a_init = ft_calloc(sizeof(int),(maxint + 2));
	if(a_init == NULL)
	{
		free(b);
		free(next_com);
		return;
	}
	set_initlst(a_init,maxint);
	morethan_three(a,b,next_com,a_init);
}

void morethan_three(t_list **a,t_list **b,t_command *next_com,int *a_init)
{
	int i;
	const int maxint = ft_lstsize(*a);
	int one_place;	
	
	i = 0;
	push_twice_unless_asize_lessthanthree(a,b,a_init);
	push_to_b_until_asize_three(a,b,next_com,a_init);
	three_lst(a);

	while(*b != NULL)
	{
		refrech_com(next_com);
		rev_pushcomset_firstlst_to_secondlst(b,a,a_init,next_com);
		exac_com_push_to_a(next_com,a,b,a_init);
		i++;
	}
	rotate_one_to_top(a);
	free(b);
	free(a_init);
	free(next_com);
}

static void push_twice_unless_asize_lessthanthree(t_list **a,t_list **b,int *a_init)
{
	int i;

	i = 0;
	while(i < 2 && ft_lstsize(*a) > 3)
	{
		pb(a,b,a_init);
		i++;
	}
}

static void push_to_b_until_asize_three(t_list **a,t_list **b,t_command *next_com,int *a_init)
{
	int i;
	i=0;
	
	while(ft_lstsize(*a) > 3)
	{
		refrech_com(next_com);
		pushcomset_firstlst_to_secondlst(a,b,a_init,next_com);
		exac_com_push_to_b(next_com,a,b,a_init);
		i++;
	}
}

static void rotate_one_to_top(t_list **a)
{
	int one_place;	

	one_place = serch_one(a);
	if(one_place > (ft_lstsize(*a)/2))
	{
		while(*(int *)((*a)->content) != 1)
			rra(a,0);
	}
	else
	{
		while(*(int *)((*a)->content) != 1)
			ra(a,0);
	}
}


