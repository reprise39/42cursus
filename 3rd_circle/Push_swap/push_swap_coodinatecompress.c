/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_coodinatecompress.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:36:10 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/20 02:15:53 by mkuida           ###   ########.fr       */
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
	int i;
	t_list *list_top = a;
	t_list *listptr;
	
	i = 0;
	origin_num = ft_calloc(size,sizeof(int));
	if(origin_num == NULL)
		return;
	
	// ft_printf("2nd : <convert arrayceck>\n"); //確認
	while(a->next != NULL)
	{
		origin_num[i] = *(int *)(a->content);
		// ft_printf("%d ",origin_num[i]); //確認
		i++;
		a = a->next;
	}
	origin_num[i] = *(int *)(a->content);
	// ft_printf("%d ",origin_num[i]); //確認
	
	comp_num = ft_sort(origin_num,size);

	// ft_printf("2nd : <sorted arry check>\n");
	// for(int ma = 0 ; ma < size ; ma++)
	// {
	// 	ft_printf("%d ",comp_num[ma]); //確認
	// }
	listptr = list_top;
	ft_printf("\n2nd : <comp>\n");
	while(listptr->next != NULL)
	{
		*(int *)(listptr->content) = (ft_binarysarch(comp_num,size,*(int *)(listptr->content)))+1;
		ft_printf("%d ",*(int *)listptr->content);
		listptr = listptr->next;
	}
	*(int *)(listptr->content) = (ft_binarysarch(comp_num,size,*(int *)(listptr->content))+1);
	ft_printf("%d \n\n",*(int *)(listptr->content));
	return;
}
