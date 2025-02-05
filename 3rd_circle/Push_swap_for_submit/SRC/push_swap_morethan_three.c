/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_morethan_three.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 04:28:14 by mkuida            #+#    #+#             */
/*   Updated: 2025/02/05 15:48:47 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_added_ftprintf/libft.h"
#include "../push_swap.h"

static void	push_twice_unless_asize_lessthanthree(t_list **a, t_list **b,
				t_command *next_com);
static void	push_to_b_until_asize_three(t_list **a, t_list **b,
				t_command *next_com);
static void	rotate_one_to_top(t_list **a);

void	by_malloc_prep_morethan_three(t_list **a)
{
	t_list		**b;
	t_command	*next_com;
	int			*a_init;
	const int	maxint = ft_lstsize(*a);

	b = malloc(sizeof(t_list *));
	if (b == NULL)
		return ;
	*b = NULL;
	next_com = malloc(sizeof(t_command));
	if (next_com == NULL)
	{
		free(b);
		return ;
	}
	a_init = ft_calloc(sizeof(int), (maxint + 2));
	if (a_init == NULL)
	{
		free(b);
		free(next_com);
		return ;
	}
	set_initlst(a_init, maxint);
	(next_com->a_in) = a_init;
	morethan_three(a, b, next_com);
}

void	morethan_three(t_list **a, t_list **b, t_command *next_com)
{
	int			i;

	i = 0;
	push_twice_unless_asize_lessthanthree(a, b, next_com);
	push_to_b_until_asize_three(a, b, next_com);
	three_lst(a);
	while (*b != NULL)
	{
		refrech_com(next_com);
		rev_pushcomset_firstlst_to_secondlst(b, a, next_com);
		exac_com_push_to_a(next_com, a, b);
		i++;
	}
	rotate_one_to_top(a);
	free(b);
	free((next_com->a_in));
	free(next_com);
}

static void	push_twice_unless_asize_lessthanthree(t_list **a, t_list **b,
		t_command *next_com)
{
	int	i;

	i = 0;
	while (i < 2 && ft_lstsize(*a) > 3)
	{
		pb(a, b, (next_com->a_in));
		i++;
	}
}

static void	push_to_b_until_asize_three(t_list **a, t_list **b,
		t_command *next_com)
{
	int	i;

	i = 0;
	while (ft_lstsize(*a) > 3)
	{
		refrech_com(next_com);
		pushcomset_firstlst_to_secondlst(a, b, next_com);
		exac_com_push_to_b(next_com, a, b);
		i++;
	}
}

static void	rotate_one_to_top(t_list **a)
{
	int	one_place;

	one_place = serch_one(a);
	if (one_place > (ft_lstsize(*a) / 2))
	{
		while (*(int *)((*a)->content) != 1)
			rra(a, 0);
	}
	else
	{
		while (*(int *)((*a)->content) != 1)
			ra(a, 0);
	}
}
