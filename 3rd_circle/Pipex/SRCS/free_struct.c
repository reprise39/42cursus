/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 03:36:21 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/06 03:36:40 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void free_struct(t_input *input)
{
	if (!input)
		return;

	// free cmd_phrase
	for (int i = 0; i < input->cmd_num; i++)
	{
		int j = 0;
		while (input->cmd_phrase[i][j])
		{
			free(input->cmd_phrase[i][j]);
			j++;
		}
		free(input->cmd_phrase[i]);
	}
	free(input->cmd_phrase);

	// free cmd_fullpath
	for (int i = 0; i < input->cmd_num; i++)
	{
		free(input->cmd_fullpath[i]);
	}
	free(input->cmd_fullpath);

	// 最後に構造体本体
	free(input);
}
