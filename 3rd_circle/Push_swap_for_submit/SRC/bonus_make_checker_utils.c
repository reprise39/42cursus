/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_make_checker_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 18:54:53 by mkuida            #+#    #+#             */
/*   Updated: 2025/02/05 16:52:02 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_added_ftprintf/libft.h"
#include "../push_swap.h"
#include "../get_next_line.h"

int check_list_is_sorted(t_list *lst)
{
	int		temp;
	t_list	*check;

	if (lst == NULL)
		return (1);
	temp = *((int *)(lst->content)); 
	check = lst->next;
	while (check != NULL)
	{
		if(*(int *)(check->content) < temp)
			return (-1);
		temp = *((int *)(check->content)); 
		check = check->next;
	}
	return (1);
}

int check_list_is_ok(t_list **a,t_list **b)
{
	if(ft_lstsize(*b) != 0)
		return (-1);
	if(check_list_is_sorted(*a) == 1)
		return (1);
	else
		return (-1);
}
