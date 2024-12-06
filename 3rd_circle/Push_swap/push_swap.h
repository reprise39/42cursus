/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:56:04 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/05 19:40:31 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

//check_input.c
int check_input(int argc,char **argv);
//lstaddback_and_checkoverlap
t_list *pushtostack_and_checkoverlap(int argc,char **argv);
// utils.c
int	ft_isspace(int c);
// command.c
int ra(t_list **a);
int pa(t_list** a, t_list **b);
int sa(t_list **a);
int rra(t_list **a);

#endif