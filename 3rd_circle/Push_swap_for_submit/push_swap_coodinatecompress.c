/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_coodinatecompress.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:36:10 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/23 10:54:49 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft_added_ftprintf/libft.h"
# include "push_swap.h"

int *ft_sort(int *origin_num,int size)
{
	int i;
	int *dest;

	i = 0;
	dest = ft_calloc(sizeof(int),size);
	if(dest == NULL)
		return NULL;
	while(i < size)
	{
		dest[i] = origin_num[i];
		i++;
	}
	ft_qsort(dest, 0 , size - 1);
	return dest;
}

void coodinatecompress(t_list *a,int size)
{
	int *origin_num;
	int *comp_num;
	t_list *list_top;
	t_list *listptr;
	
	list_top = a;
	origin_num = ft_calloc(size,sizeof(int));
	if(origin_num == NULL)
		return;
	lst_to_arry(a,origin_num);
	comp_num = ft_sort(origin_num,size);
	listptr = list_top;
	while(listptr->next != NULL)
	{
		*(int *)(listptr->content) = (ft_binarysarch(comp_num,size,*(int *)(listptr->content)))+1;
		listptr = listptr->next;
	}
	*(int *)(listptr->content) = (ft_binarysarch(comp_num,size,*(int *)(listptr->content))+1);
	free(origin_num);
	free(comp_num);
	return;
}

void *lst_to_arry(t_list *a,int *origin_num)
{
	int i;
	i = 0;
	
	while(a->next != NULL)
	{
		origin_num[i] = *(int *)(a->content);
		i++;
		a = a->next;
	}
	origin_num[i] = *(int *)(a->content);
}
