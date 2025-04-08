/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 03:36:21 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/08 19:21:26 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_struct(t_input *input)
{
	int	i;
	int	j;

	i = 0;
	while (i < (input->cmd_num))
	{
		j = 0;
		while (input->cmd_phrase[i][j])
		{
			free(input->cmd_phrase[i][j]);
			j++;
		}
		free(input->cmd_phrase[i]);
		i++;
	}
	free(input->cmd_phrase);
	i = 0;
	while (i < (input->cmd_num))
	{
		if (input->cmd_fullpath[i] != NULL)
			free(input->cmd_fullpath[i]);
		i++;
	}
	free(input->cmd_fullpath);
	free(input);
}
