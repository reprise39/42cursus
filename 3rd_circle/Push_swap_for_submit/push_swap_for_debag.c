/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_for_debag.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 20:16:06 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/24 20:16:06 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_added_ftprintf/libft.h"
#include "push_swap.h"

void	print_t_com(t_command *command)
{
	ft_printf("<print_t_com>\n");
	ft_printf(" |number_of_command = %d\n", command->number_of_command);
	ft_printf(" |ar = %d\n", command->ar);
	ft_printf(" |arr = %d\n", command->arr);
	ft_printf(" |br = %d\n", command->br);
	ft_printf(" |brr = %d\n", command->brr);
	ft_printf(" |rr = %d\n", command->rr);
	ft_printf(" |rrr = %d\n", command->rrr);
}

void	print_list(t_list *a)
{
	if (a == NULL)
		return ;
	ft_printf("<printlist-start>\n");
	while (a->next != NULL)
	{
		ft_printf("| %d\n", *(int *)(a->content));
		a = a->next;
	}
	ft_printf("| %d\n", *(int *)(a->content));
	ft_printf("<printlist-end>\n");
}
