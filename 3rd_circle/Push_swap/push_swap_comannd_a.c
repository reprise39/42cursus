/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_comannd_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:58:40 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/21 22:19:19 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft_added_ftprintf/libft.h"
# include "push_swap.h"

int sa(t_list **a,int ss_flag)
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
		printf("sa\n");
	return (1);
}

int pa(t_list** a, t_list **b,int *a_init)
{
	t_list *atop;
	t_list *btop;

	atop = *a;
	btop = *b;

	int push_content;
	
	if (b == NULL || *b == NULL )
		return (0);
	push_content = *(int *)(btop->content);
	a_init[push_content] = 1;

	*a = (*b);
	*b = (*b)->next;
	(*a)->next = atop;
	printf("pa\n");
	return (1);
}

int ra(t_list **a,int rr_flag)
{
	t_list *atop;
	atop = *a;
	if (a == NULL || atop == NULL || atop->next == NULL)
		return (0);

	ft_lstlast(atop)->next = atop;
	*a = atop->next;
	atop->next = NULL;
	if(rr_flag == 0)
		printf("ra\n");
	return (1);
}

int rra(t_list **a,int rrr_flag)
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
		printf("rra\n");
	return (1);
}
