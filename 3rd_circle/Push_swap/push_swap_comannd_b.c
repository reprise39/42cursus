/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_comannd_b.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 03:15:09 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/19 21:32:23 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft_added_ftprintf/libft.h"
# include "push_swap.h"

int sb(t_list **a,int ss_flag)
{
	t_list *top;
	t_list *second;
	t_list *third;

	top = *a;
	second = top->next;
	third = second->next;
	if(a == NULL || top == NULL || second == NULL)
		return (0);
	top->next = third;
	second->next = top;
	*a = second;
	if(ss_flag == 0)
		printf("sb\n");
	return (1);
}

int pb(t_list** a, t_list **b,int *a_init)
{
	t_list *btop;
	t_list *atop;
	int push_content;

	atop = *a;
	btop = *b;

	if (a == NULL || atop == NULL )
		return (0);
	push_content = *(int *)(atop->content);
	a_init[push_content] = 0;

	*b = (*a);
	*a = (*a)->next;
	(*b)->next = btop;
	printf("pb\n");
	return (1);
}

int rb(t_list **a,int rr_flag)
{
	t_list *atop;
	atop = *a;
	if (a == NULL || atop == NULL || atop->next == NULL)
		return (0);

	ft_lstlast(atop)->next = atop;
	*a = atop->next;
	atop->next = NULL;
	if(rr_flag == 0)
		printf("rb\n");
	return (1);
}

int rrb(t_list **a,int rrr_flag)
{
	t_list *list_ptr;
	list_ptr = *a;
	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return (0);

	while((list_ptr->next)->next != NULL)
		list_ptr = list_ptr->next;
	
	list_ptr->next->next = *a;
	*a = list_ptr->next;
	list_ptr->next = NULL;
	if(rrr_flag == 0)
		printf("rrb\n");
	return (1);
}
