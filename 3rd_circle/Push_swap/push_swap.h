/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:56:04 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/05 00:39:25 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>

// typedef struct int_list
// {
// 	void			*content;
// 	struct int_list	*next;
// }					t_ilist;

//check_input.c
int check_input(int argc,char **argv);
//lstaddback_and_checkoverlap
t_list *pushtostack_and_checkoverlap(int argc,char **argv);
// utils.c
int	ft_isspace(int c);

#endif