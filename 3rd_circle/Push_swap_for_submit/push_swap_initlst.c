/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_initlst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:12:53 by mkuida            #+#    #+#             */
/*   Updated: 2025/02/04 18:45:08 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_added_ftprintf/libft.h"
#include "push_swap.h"

int	sercharr_nextnum(int target, int *x_init, int serchlst)
{
	int	i;

	i = target + 1;
	while (i <= x_init[0])
	{
		if (x_init[i] == serchlst)
			return (i);
		i++;
	}
	return (-1);
}

int	sercharr_beforenum(int target, int *x_init, int serchlst)
{
	int	i;

	i = target;
	while (i != 0)
	{
		if (x_init[i] == serchlst)
			return (i);
		i--;
	}
	return (-1);
}

void	set_initlst(int *a_init, int max)
{
	int	i;

	i = 1;
	a_init[0] = max;
	while (i <= max)
	{
		a_init[i] = 1;
		i++;
	}
}

int	sercharr_minnum(int *a_init, int serchlst)
{
	int	i;

	i = 1;
	while (i < a_init[0])
	{
		if (a_init[i] == serchlst)
			return (i);
		i++;
	}
	return (-1);
}

int	sercharr_maxnum(int *a_init, int serchlst)
{
	int	i;

	i = a_init[0] - 1;
	while (i > 0)
	{
		if (a_init[i] == serchlst)
			return (i);
		i--;
	}
	return (-1);
}
