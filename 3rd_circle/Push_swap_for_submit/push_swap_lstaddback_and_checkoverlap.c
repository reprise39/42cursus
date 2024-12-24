/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lstaddback_and_checkoverlap.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:08:04 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/24 18:52:58 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft_added_ftprintf/libft.h"
# include "push_swap.h"

static t_list *free_and_return_null(t_list **list_top,int *int_ptr,t_list *added_list)
{
	ft_lstclear(list_top,free);
	free(int_ptr);
	free(added_list);
	return (NULL);
}

static int	ft_lstaddback_and_checkoverlap(t_list **lst, t_list *new)
{
	const int new_content = *(int *)(new->content);
	t_list *dest;
	
	if (!new)
		return (-1);
	if (*lst == NULL)
	{
		*lst = new;
		return (1);
	}
	else
	{
		dest = *lst;
		while (dest->next != NULL)
		{
			if(*(int *)(dest->content) == new_content)
				return (-1);
			dest = dest->next;
		}
		if(*(int *)(dest->content) == new_content)
				return (-1);
		dest->next = new;
		return (1);
	}
}

t_list *pushtostack_and_checkoverlap(int argc,char **argv)
{
	int i;
	int *int_ptr;
	t_list *list_top;
	t_list *added_list;

	i = 1;
	while(i < argc)
	{
		int_ptr = malloc(sizeof(int));
		if(int_ptr == NULL)
			return NULL;
		*int_ptr = ft_atoi(argv[i]);
		if(i == 1)
			list_top = ft_lstnew(int_ptr);
		else
		{
			added_list = ft_lstnew(int_ptr);
			if(ft_lstaddback_and_checkoverlap(&list_top,added_list) == -1)
				return(free_and_return_null(&list_top,int_ptr,added_list));
		}
		i++;
	}
	return (list_top);
}

