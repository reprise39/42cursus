/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 23:37:45 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/19 23:18:15 by mkuida           ###   ########.fr       */
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
	// print_list(*a);// ←確認用
	return (0);
}
