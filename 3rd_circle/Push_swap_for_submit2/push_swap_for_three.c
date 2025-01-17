/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_for_three.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 04:03:17 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/24 20:10:29 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_added_ftprintf/libft.h"
#include "push_swap.h"

void	three_two_one(t_list **a)
{
	ra(a, 0);
	sa(a, 0);
}

void	three_one_two(t_list **a)
{
	ra(a, 0);
}

void	two_three_one(t_list **a)
{
	rra(a, 0);
}

void	one_three_two(t_list **a)
{
	ra(a, 0);
	sa(a, 0);
	rra(a, 0);
}

void	two_one_three(t_list **a)
{
	sa(a, 0);
}
