/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_struct_command.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:07:12 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/23 10:15:21 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft_added_ftprintf/libft.h"
# include "push_swap.h"

void refrech_com(t_command *next_com)
{
	next_com->number_of_command = INT_MAX;
	next_com->ar = 0;
	next_com->arr = 0;
	next_com->br = 0;
	next_com->brr = 0;
	next_com->rr = 0;
	next_com->rrr = 0;
}


void exac_com_push_to_b(t_command *next_com,t_list **a,t_list **b,int *a_init)
{
	int i;
	i = (next_com->ar);
	while(i > 0)
	{
		ra(a,0);
		i--;
	}
	i = (next_com->arr);
	while(i > 0)
	{
		rra(a,0);
		i--;
	}
	i = (next_com->rr);
	while(i > 0)
	{
		rr(a,b);
		i--;
	}
	i = (next_com->rrr);
	while(i > 0)
	{
		rrr(a,b);
		i--;
	}
	i = (next_com->br);
	while(i != 0)
	{
		rb(b,0);
		i--;
	}
	i = (next_com->brr);
	while(i > 0)
	{
		rrb(b,0);
		i--;
	}
	pb(a,b,a_init);
}


void exac_com_push_to_a(t_command *next_com,t_list **a,t_list **b,int *a_init)
{
	int i;
	i = (next_com->br);
	while(i != 0)
	{
		rb(b,0);
		i--;
	}
	i = (next_com->brr);
	while(i > 0)
	{
		rrb(b,0);
		i--;
	}
	i = (next_com->rr);
	while(i > 0)
	{
		rr(a,b);
		i--;
	}
	i = (next_com->rrr);
	while(i > 0)
	{
		rrr(a,b);
		i--;
	}
	i = (next_com->ar);
	while(i > 0)
	{
		ra(a,0);
		i--;
	}
	i = (next_com->arr);
	while(i > 0)
	{
		rra(a,0);
		i--;
	}
	pa(a,b,a_init);
}


void print_t_com(t_command *command)
{
	ft_printf("<print_t_com>\n");
	ft_printf(" |number_of_command = %d\n", command->number_of_command);
	ft_printf(" |ar = %d\n", command->ar);
	ft_printf(" |arr = %d\n", command->arr);
	ft_printf(" |br = %d\n", command->br);
	ft_printf(" |brr = %d\n", command->brr);
	ft_printf(" |rr = %d\n", command->rr);
	ft_printf(" |rrr = %d\n", command->rrr);
}

void refrech_com_exceptnoc(t_command *next_com)
{
	next_com->number_of_command = INT_MAX;
	next_com->ar = 0;
	next_com->arr = 0;
	next_com->br = 0;
	next_com->brr = 0;
	next_com->rr = 0;
	next_com->rrr = 0;
}