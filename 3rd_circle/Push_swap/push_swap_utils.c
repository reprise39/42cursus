/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:05:54 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/05 00:09:10 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft_added_ftprintf/libft.h"
# include "push_swap.h"

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
