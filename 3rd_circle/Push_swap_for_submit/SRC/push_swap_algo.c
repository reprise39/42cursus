/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:09:15 by mkuida            #+#    #+#             */
/*   Updated: 2025/02/05 15:47:43 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_added_ftprintf/libft.h"
#include "../push_swap.h"

int	check_alreadyok(t_list *a)
{
	int	temp;

	temp = *(int *)(a->content);
	while (a->next != NULL)
	{
		a = a->next;
		if (temp > *(int *)(a->content))
			return (0);
		temp = *(int *)(a->content);
	}
	return (1);
}

void	two_lst(t_list **a)
{
	int		first;
	int		second;
	t_list	*a_ptr;

	a_ptr = *a;
	first = *(int *)((a_ptr)->content);
	(a_ptr) = (a_ptr)->next;
	second = *(int *)((a_ptr)->content);
	if (first < second)
		return ;
	else
		ft_printf("sa\n");
	return ;
}

void	three_lst(t_list **a)
{
	int		first;
	int		second;
	int		third;
	t_list	*a_ptr;

	a_ptr = *a;
	first = *(int *)((a_ptr)->content);
	(a_ptr) = (a_ptr)->next;
	second = *(int *)(a_ptr->content);
	a_ptr = a_ptr->next;
	third = *(int *)(a_ptr->content);
	if (first > second && first > third && second > third)
		three_two_one(a);
	else if (first > second && first > third && second < third)
		three_one_two(a);
	else if (second > first && second > third && third < first)
		two_three_one(a);
	else if (second > first && second > third && third > first)
		one_three_two(a);
	else if (third > first && third > second && first > second)
		two_one_three(a);
	else if (third > first && third > second && first < second)
		return ;
	return ;
}

void	push_swap_algo(t_list **a)
{
	const int	lstsize = ft_lstsize(*a);

	if (a == NULL)
		return ;
	if (check_alreadyok(*a) == 1)
		return ;
	if (lstsize == 1)
		return ;
	else if (lstsize == 2)
		two_lst(a);
	else if (lstsize == 3)
		three_lst(a);
	else if (lstsize > 3)
		by_malloc_prep_morethan_three(a);
	else
		return ;
}
