/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_push_swap_command_basic.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:58:40 by mkuida            #+#    #+#             */
/*   Updated: 2025/02/05 16:18:17 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_added_ftprintf/libft.h"
#include "../push_swap.h"

int	bonus_swap(t_list **a)
{
	t_list	*top;
	t_list	*second;
	t_list	*third;

	top = *a;
	second = top->next;
	third = second->next;
	if (a == NULL || top == NULL || second == NULL)
		return (0);
	top->next = third;
	second->next = top;
	*a = second;
	return (1);
}

int	bonus_push(t_list **a, t_list **b)
{
	t_list	*atop;

	atop = *a;
	if (b == NULL || *b == NULL)
		return (0);
	*a = (*b);
	*b = (*b)->next;
	(*a)->next = atop;
	return (1);
}

int	bonus_rotate(t_list **a)
{
	t_list	*atop;

	atop = *a;
	if (a == NULL || atop == NULL || atop->next == NULL)
		return (0);
	ft_lstlast(atop)->next = atop;
	*a = atop->next;
	atop->next = NULL;
	return (1);
}

int	bonus_rev_rotate(t_list **a)
{
	t_list	*list_ptr;

	list_ptr = *a;
	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return (0);
	while ((list_ptr->next)->next != NULL)
		list_ptr = list_ptr->next;
	list_ptr->next->next = *a;
	*a = list_ptr->next;
	list_ptr->next = NULL;
	return (1);
}
