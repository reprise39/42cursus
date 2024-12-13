/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 23:37:45 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/14 04:11:33 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft_added_ftprintf/libft.h"
# include "push_swap.h"

void print_error()
{
	const char *str = "Error\n";
	write(STDERR_FILENO,str,ft_strlen(str));
	return;
}


//確認用だよ！
void print_list(t_list *a)
{
	ft_printf("<printlist-start>\n");
	while (a->next != NULL)
	{
		ft_printf("%d\n", *(int*)(a->content));
		a = a->next;
	}
	ft_printf("%d\n", *(int*)(a->content));
	ft_printf("<printlist--end>\n");
}

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
	origin_num = calloc(size,sizeof(int));
	if(origin_num == NULL)
		return;
	
	ft_printf("\n<convert arrayceck>\n"); //確認
	while(a->next != NULL)
	{
		origin_num[i] = *(int *)(a->content);
		ft_printf("%d ",origin_num[i]); //確認
		i++;
		a = a->next;
	}
	origin_num[i] = *(int *)(a->content);
	ft_printf("%d ",origin_num[i]); //確認
	
	comp_num = ft_sort(origin_num,size);

	ft_printf("\n<sorted arry check>\n");
	for(int ma = 0 ; ma < size ; ma++)
	{
		ft_printf("%d ",comp_num[ma]); //確認
	}
	listptr = list_top;
	ft_printf("\n<comp>\n");
	while(listptr->next != NULL)
	{
		*(int *)(listptr->content) = ft_binarysarch(comp_num,size,*(int *)(listptr->content));
		ft_printf("%d ",*(int *)listptr->content);
		listptr = listptr->next;
	}
	*(int *)(listptr->content) = ft_binarysarch(comp_num,size,*(int *)(listptr->content));
	ft_printf("%d ",*(int *)(listptr->content));
	return;
}



int main(int argc,char **argv)
{
	t_list **a;
	
	if(argc == 1)
		return (0);
	if(check_input(argc,argv) == -1)
	{
		print_error();
		return (0);
	}
	a = malloc(sizeof(t_list **));
	*a = pushtostack_and_checkoverlap(argc,argv);
	if(*a == NULL)
	{
		print_error();
		return (0);
	}
	// ft_printf("\ninput check\n");
	// print_list(*a);// ←確認用
	coodinatecompress(*a,argc-1);
	// rra(a,0);
	// sa(a);
	// ft_printf("\nrra check\n");
	push_swap_algo(a);
	print_list(*a);// ←確認用
	return (0);
}
