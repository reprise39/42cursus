/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_comannd_r.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 03:16:36 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/14 03:37:23 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft_added_ftprintf/libft.h"
# include "push_swap.h"

int ss(t_list** a, t_list **b)
{
	sa(a,1);
	sb(b,1);
	ft_printf("ss\n");
}

int rr(t_list **a, t_list **b)
{
	ra(a,1);
	rb(b,1);
	ft_printf("rr\n");
}

int rrr(t_list** a, t_list **b)
{
	rra(a,1);
	rrb(b,1);
	ft_printf("rrr\n");
}
