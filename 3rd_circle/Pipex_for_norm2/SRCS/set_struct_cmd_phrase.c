/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct_cmd_phrase.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 19:59:55 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/09 04:00:04 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	***make_cmd_phrase(int cmd_num, char **argv, int is_heredoc)
{
	int		i;
	char	***dest;

	i = 0;
	dest = malloc(sizeof(char **) * (cmd_num + 1));
	if (dest == NULL)
		return (NULL);
	while (i < cmd_num)
	{
		if (is_heredoc == 0)
			dest[i] = ft_split(argv[i + 2], ' ');
		else if (is_heredoc == 1)
			dest[i] = ft_split(argv[i + 3], ' ');
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
