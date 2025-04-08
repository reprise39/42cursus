/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct_cmd_fullpaths.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 03:56:07 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/09 04:35:50 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**make_cmd_fullpaths(int cmd_num, char ***cmd_phrase, char *envp[])
{
	char	**dest;
	char	*path;

	path = getpath_from_env(envp);
	if (path == NULL)
		return (NULL);
	dest = malloc(sizeof(char *) * (cmd_num + 1));
	if (dest == NULL)
		return (NULL);
	set_dest(dest, cmd_num, cmd_phrase, path);
	return (dest);
}

char	*make_cmd_fullpath(char **cmd, char *pathtop)
{
	int		i;
	char	**path_candidate;
	char	*fullpath_candidate;

	i = 0;
	path_candidate = ft_split(pathtop, ':');
	if (path_candidate == NULL)
		return (NULL);
	while (path_candidate[i] != NULL)
	{
		fullpath_candidate = make_fullpath_candidate(path_candidate, cmd, i);
		if (fullpath_candidate == NULL)
			return (NULL);
		if (access(fullpath_candidate, X_OK) == 0)
		{
			free_ft_split(path_candidate);
			return (fullpath_candidate);
		}
		free(fullpath_candidate);
		i++;
	}
	free_ft_split(path_candidate);
	return (NULL);
}

void	free_cmd_fullpath(int upper, char **dest)
{
	int	i;

	i = 0;
	while (i <= upper)
	{
		free(dest[i]);
		i++;
	}
	free(dest);
}

char	*make_fullpath_candidate(char **path_candidate, char **cmd, int i)
{
	char	*fullpath_candidate;

	fullpath_candidate = malloc(ft_strlen(path_candidate[i]) + ft_strlen(cmd[0])
			+ 2);
	if (fullpath_candidate == NULL)
	{
		free_ft_split(path_candidate);
		return (NULL);
	}
	fullpath_candidate = ft_strcat_threewords(fullpath_candidate,
			path_candidate[i], "/", cmd[0]);
	return (fullpath_candidate);
}

void	set_dest(char **dest, int cmd_num, char ***cmd_phrase, char *path)
{
	int	i;

	i = 0;
	while (i < cmd_num)
	{
		if (access(cmd_phrase[i][0], X_OK) == 0)
			dest[i] = ft_strdup((const char *)cmd_phrase[i][0]);
		else
			dest[i] = make_cmd_fullpath(cmd_phrase[i], path);
		if (dest[i] == NULL)
		{
			free_cmd_fullpath(i, dest);
			return ;
		}
		i++;
	}
	dest[cmd_num] = NULL;
}
