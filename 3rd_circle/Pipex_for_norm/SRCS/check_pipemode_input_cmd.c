/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipemode_input_cmd.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 05:32:10 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/06 05:54:58 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int checkcmd_unexist_from_path(char* argv,char *pathtop);

int cmd_unexit(int argc,char **argv,char *env_path)
{
	int i;
	int unexist_flag;
	char **cmd;
	
	unexist_flag = 0;
	i = 2;
	while(i < (argc-1))
	{
		cmd = ft_split(argv[i],' ');
		if(cmd == NULL)
			return (1);
		unexist_flag = checkcmd_unexist_from_path(cmd[0],env_path);
		free_ft_split(cmd);
		if(unexist_flag == 1)
			return (1);
		i++;
	}
	return (0);
}

static int checkcmd_unexist_from_path(char* argv,char *pathtop)
{
	int i;
	char **path_candidate;
	char *fullpath_candidate;
	
	i = 0;
	path_candidate = ft_split(pathtop,':');
	if(path_candidate == NULL)
		return (1);
	while(path_candidate[i] != NULL)
	{
		fullpath_candidate = malloc(ft_strlen(path_candidate[i]) + ft_strlen(argv) + 2);
		if(fullpath_candidate == NULL)
		{
			free_ft_split(path_candidate);
			return (1);
		}
		fullpath_candidate = ft_strcat_threewords(fullpath_candidate,path_candidate[i],"/",argv);
		if(access(fullpath_candidate,X_OK) == 0)
		{
			free(fullpath_candidate);
			free_ft_split(path_candidate);
			return (0);
		}
		free(fullpath_candidate);
		i++;
	}
	free_ft_split(path_candidate);
	return (1);
}

