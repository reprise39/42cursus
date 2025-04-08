/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:56:12 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/06 16:26:06 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	***make_cmd_phrase(int cmd_num, char **argv);
static char	**make_cmd_fullpaths(int cmd_num, char ***cmd_phrase, char *envp[]);
static char	*make_cmd_fullpath(char **cmd, char *pathtop);
static void	free_cmd_fullpath(int upper, char **dest);
static char	*make_fullpath_candidate(char **path_candidate, char **cmd, int i);

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

static char	***make_cmd_phrase(int cmd_num, char **argv)
{
	int		i;
	char	***dest;

	i = 0;
	dest = malloc(sizeof(char **) * (cmd_num + 1));
	if (dest == NULL)
		return (NULL);
	while (i < cmd_num)
	{
		dest[i] = ft_split(argv[i + 2], ' ');
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

static char	**make_cmd_fullpaths(int cmd_num, char ***cmd_phrase, char *envp[])
{
	int		i;
	char	**dest;
	char	*path;

	i = 0;
	path = getpath_from_env(envp); // marrocしてない
	if (path == NULL)
		return (NULL);
	dest = malloc(sizeof(char *) * (cmd_num + 1));
	if (dest == NULL)
		return (NULL);
	while (i < cmd_num)
	{
		dest[i] = make_cmd_fullpath(cmd_phrase[i], path);
		if (dest[i] == NULL)
		{
			free_cmd_fullpath(i, dest); // error処理
			return (NULL);
		}
		i++;
	}
	dest[cmd_num] = NULL;
	return (dest);
}

static char	*make_cmd_fullpath(char **cmd, char *pathtop)
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

static void	free_cmd_fullpath(int upper, char **dest)
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

static char	*make_fullpath_candidate(char **path_candidate, char **cmd, int i)
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
