/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lstaddback_and_checkoverlap.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:08:04 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/05 00:49:18 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft_added_ftprintf/libft.h"
# include "push_swap.h"

static int	ft_lstaddback_and_checkoverlap(t_list **lst, t_list *new)
{
	const int new_content = new->content;
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
			if(dest->content == new_content)
				return (-1);
			dest = dest->next;
		}
		dest->next = new;
		return (1);
	}
}


t_list *pushtostack_and_checkoverlap(int argc,char **argv)
{
	int i;
	t_list *list_top;
	t_list *added_list;
	int input;

	i = 1;
	while(i < argc)
	{
		input = ft_atoi(argv[i]);
		if(i == 1)
		{
			list_top = ft_lstnew(&input);
		}
		else
		{
			added_list = ft_lstnew(&input);
			if(ft_lstaddback_and_checkoverlap(list_top,added_list) == -1)
			{
				ft_lstclear(&list_top,free); //あってるか心配
				return (NULL);
			}
		}
		i++;
	}
	return (list_top);
}
