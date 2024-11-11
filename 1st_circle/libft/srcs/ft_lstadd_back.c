/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:07:33 by mkuida            #+#    #+#             */
/*   Updated: 2024/11/08 04:08:59 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lsft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*dest;

	dest = *lst;
	while (dest->next != NULL)
	{
		dest = dest->next;
	}
	dest->next = new;
	new->next = NULL;
}
