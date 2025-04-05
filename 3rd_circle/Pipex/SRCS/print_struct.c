/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 03:29:10 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/06 03:51:35 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

void print_struct(t_input *print)
{
	if(print == NULL)
	{
		ft_printf("struct is NULLLLLLLLLLL\n");
		return ;
	}
	ft_printf(" \n ============== start print struct ======== \n");
	ft_printf(" cmd_num  = %d \n",print->cmd_num);
	ft_printf(" pipe_num = %d \n",print->pipe_num);
	for (int i = 0; i < print->cmd_num; i++)
	{
		ft_printf("  cmd %d: ", i);
		for (int j = 0; print->cmd_phrase[i][j] != NULL; j++)
		{
			ft_printf("\"%s\" ", print->cmd_phrase[i][j]);
		}
		ft_printf("\n");
	}

	ft_printf("\n[cmd_fullpath]\n");
	for (int i = 0; i < print->cmd_num; i++)
	{
		printf("  fullpath[%d]: %s\n", i, print->cmd_fullpath[i]);
	}
	printf("============= end =========\n");
	return ;
}
