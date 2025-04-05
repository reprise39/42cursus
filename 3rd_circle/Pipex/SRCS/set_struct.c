/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 18:56:12 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/06 03:28:26 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

static char ***make_cmd_phrase(int cmd_num,char **argv);
static char **make_cmd_fullpaths(int cmd_num,char ***cmd_phrase,char *envp[]);
char *make_cmd_fullpath(char** cmd,char*pathtop);
static char *ft_strcat_threewords(char *dest,char *one,char *two ,char *three);
static char *getpath_from_env(char **envp);

t_input *set_struct(int argc,char **argv,char *envp[])
{
	t_input *dest;
	dest = malloc(sizeof(t_input));
	if (dest == NULL)
		return (NULL);
	dest->cmd_num = argc - 3;
	dest->pipe_num = argc - 4;
	dest->cmd_phrase = make_cmd_phrase(dest->cmd_num, argv);
	if(dest->cmd_phrase == NULL)
		return (NULL);
	dest->cmd_fullpath = make_cmd_fullpaths(dest->cmd_num,dest->cmd_phrase,envp);
	if(dest->cmd_fullpath == NULL)
	{
		//free(cmd_phrase);
		return (NULL);
	}
	return (dest);
}

static char ***make_cmd_phrase(int cmd_num,char **argv)
{
	int i;
	i = 0;
	char ***dest;
	dest = malloc(sizeof(char**)*(cmd_num+1));
	if(dest == NULL)
		return(NULL);
	while(i < cmd_num)
	{
		dest[i] = ft_split(argv[i+2],' ');
		i++;
	}
	dest[i] = NULL;
	return(dest);
}

static char **make_cmd_fullpaths(int cmd_num,char ***cmd_phrase,char *envp[])
{
	int i;
	i = 0;
	
	char *path;
	path = getpath_from_env(envp);
	if(path == NULL)
		return (NULL);

	char **dest;
	dest = malloc(sizeof(char*)*(cmd_num+1));
	if(dest == NULL)
		return(NULL);	
	while(i < cmd_num)
	{
		dest[i] = make_cmd_fullpath(cmd_phrase[i],path);
		if(dest[i] == NULL)
		{
			//エラー処理//
		}
		i++;
	}
	dest[cmd_num] = NULL;
	return (dest);
}

char *make_cmd_fullpath(char** cmd,char*pathtop)
{
	int i;
	i = 0;
	char **path_candidate;
	char *fullpath_candidate;
	path_candidate = ft_split(pathtop,':');
	if(path_candidate == NULL)
		return (NULL);
	
	while(path_candidate[i] != NULL)
	{
		fullpath_candidate = malloc(ft_strlen(path_candidate[i]) + ft_strlen(cmd[0]) + 2);
		if(fullpath_candidate == NULL)
		{
			// splitのfreeが必要
			int j = 0;
			while (path_candidate[j] != NULL)
			{
				free(path_candidate[j]);
				j++;
			}
			free(path_candidate);
			return (NULL);
		}
		fullpath_candidate = ft_strcat_threewords(fullpath_candidate,path_candidate[i],"/",cmd[0]);
		if(access(fullpath_candidate,X_OK) == 0)
		{
			ft_printf("path_into_struct!\n");
			ft_printf("into -> %s\n",fullpath_candidate);
			//free(fullpath_candidate); //freeせずに返す
			//splitの中身解放
			int j = 0;
			while (path_candidate[j] != NULL)
			{
				free(path_candidate[j]);
				j++;
			}
			free(path_candidate);
			return (fullpath_candidate);
		}
		free(fullpath_candidate);
		i++;
	}
	//splitの中身解放
	int j = 0;
	while (path_candidate[j] != NULL)
	{
		free(path_candidate[j]);
		j++;
	}
	free(path_candidate);
	return (NULL);
}

static char *ft_strcat_threewords(char *dest,char *one,char *two ,char *three)
{
	char* ptr;
	ptr = dest;
	int i;
	i = 0;
	while(one[i] != '\0')
	{
		ptr[i] = one[i];
		i++;
	}
	ptr += i;
	i=0;
	while(two[i] != '\0')
	{
		ptr[i] = two[i];
		i++;
	}
	ptr += i;
	i=0;
	while(three[i] != '\0')
	{
		ptr[i] = three[i];
		i++;
	}
	ptr[i] = '\0';
	return (dest);
}


char *getpath_from_env(char **envp)
{
	int i;
	i = 0;
	while(envp[i] != NULL)
	{
		if(ft_strncmp(envp[i],"PATH=",5) == 0)
			return(envp[i] + 5);
		i++;
	}
	return (NULL);
}
