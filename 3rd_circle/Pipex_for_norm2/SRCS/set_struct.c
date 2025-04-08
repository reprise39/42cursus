/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:56:12 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/08 20:00:32 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_input	*set_struct(int argc, char **argv, char *envp[])
{
	t_input	*dest;

	dest = malloc(sizeof(t_input));
	if (dest == NULL)
		return (NULL);
	dest->cmd_num = argc - 3;
	dest->pipe_num = argc - 4;
	dest->cmd_phrase = make_cmd_phrase(dest->cmd_num, argv);
	if (dest->cmd_phrase == NULL)
	{
		free(dest);
		return (NULL);
	}
	dest->cmd_fullpath = make_cmd_fullpaths(dest->cmd_num, dest->cmd_phrase,
			envp);
	if (dest->cmd_fullpath == NULL)
	{
		free_cmd_phrase(dest->cmd_phrase);
		free(dest);
		return (NULL);
	}
	return (dest);
}
