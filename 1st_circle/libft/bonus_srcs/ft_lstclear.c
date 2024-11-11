/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 23:11:57 by mkuida            #+#    #+#             */
/*   Updated: 2024/11/07 23:12:28 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	dellist_recursive(t_list *dest, void (*del)(void *))
{
	if (dest == NULL)
		return ;
	if (dest->next != NULL)
		dellist_recursive(dest->next, del);
	del(dest->content);
	free(dest);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	dellist_recursive(*lst, del);
	*lst = NULL;
}
