/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:09:15 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/14 04:30:28 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft_added_ftprintf/libft.h"
# include "push_swap.h"

void two_lst(t_list **a)
{
	int first;
	int second;
	t_list *a_ptr;

	a_ptr = *a;
	first = *(int *)((a_ptr)->content);
	(a_ptr) = (a_ptr)->next;
	second = *(int *)((a_ptr)->content);
	if(first > second)
		return;
	else
		ft_printf("sa\n");
	return;
}

void three_lst(t_list **a)
{
	int first;
	int second;
	int third;
	t_list *a_ptr;

	a_ptr = *a;
	first = *(int *)((a_ptr)->content);
	(a_ptr) = (a_ptr)->next;
	second = *(int *)(a_ptr->content);
	a_ptr = a_ptr->next;
	third = *(int *)(a_ptr->content);
	if(first > second && first > third && second > third)//3>2>1
		three_two_one(a);
	else if(first > second && first > third && second < third)//3>1>2
		three_one_two(a);
	else if(second > first && second > third && third < first)//2>3>1
		two_three_one(a);
	else if(second > first && second > third && third > first)//1>3>2
		one_three_two(a);
	else if(third > first && third > second && first > second)//2>1>3
		two_one_three(a);
	else if(third > first && third > second && first < second)//1>2>3
		return;
	else
		ft_printf("three_lst:algo error\n");
	return;
}


void push_swap_algo(t_list **a)
{
	const int lstsize = ft_lstsize(*a);
	if(a == NULL)
		return;
	ft_printf("\n// ika algo kaisi //\n");
	if(lstsize == 1)
		return;
	else if(lstsize == 2)
		two_lst(a);
	else if(lstsize == 3)
		three_lst(a);
	else if(lstsize > 3)
		morethan_three(a);
		// ft_printf("mijissou\n");
	else
		return;
}
