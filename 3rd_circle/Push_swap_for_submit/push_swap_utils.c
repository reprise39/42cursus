/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:05:54 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/24 20:46:19 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_added_ftprintf/libft.h"
#include "push_swap.h"

int	ft_isspace(int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	if (ch == '\f' || ch == '\n' || ch == '\r')
		return (1);
	else if (ch == '\t' || ch == '\v' || ch == ' ')
		return (1);
	else
		return (0);
}

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int	serch_one(t_list **a)
{
	int		i;
	t_list	*atop;

	atop = *a;
	i = 0;
	while (*(int *)(atop->content) != 1)
	{
		atop = (atop->next);
		i++;
	}
	return (i);
}
