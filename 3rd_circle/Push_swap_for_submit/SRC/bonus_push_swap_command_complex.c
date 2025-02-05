/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_push_swap_comannd_complex.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 03:16:36 by mkuida            #+#    #+#             */
/*   Updated: 2025/02/05 16:06:43 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_added_ftprintf/libft.h"
#include "../push_swap.h"

int	bonus_ss(t_list **a, t_list **b)
{
	bonus_swap(a);
	bonus_swap(b);
	return (1);
}

int	bonus_rr(t_list **a, t_list **b)
{
	bonus_rotate(a);
	bonus_rotate(b);
	return (1);
}

int	bonus_rrr(t_list **a, t_list **b)
{
	bonus_rev_rotate(a);
	bonus_rev_rotate(b);
	return (1);
}
