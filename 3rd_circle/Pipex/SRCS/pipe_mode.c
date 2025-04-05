/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_mode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 03:24:07 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/06 03:52:20 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

static int check_input(int argc,char **argv,char *envp[]);
static int file1_unexist(char *path);
static int file1_no_read_auth(char *path);
static int file2_no_write_auth(char *path);
static int cmd_unexit(int argc,char **argv,char *envp[]);
static char *getpath_from_env(char **envp);
static int checkcmd_unexist_from_path(char* argv,char *pathtop);
static char *ft_strcat_threewords(char *dest,char *one,char *two ,char *three);

int pipes(int argc,char **argv,char *envp[])
{
	t_input *pipe_input;
	int rtn;
	if (check_input(argc,argv,envp) != 0)
		return (-1);

		pipe_input = set_struct(argc,argv,envp);
	if(pipe_input == NULL)
		return (-1);

		print_struct(pipe_input); // kakunin
	ft_printf("\n ---start exec pipe--- \n");
	rtn = exec_pipe(argc,argv,envp,pipe_input);

	free_struct(pipe_input);
	
	return (0);
}

static int check_input(int argc,char **argv,char *envp[])
{
	
	if(file1_unexist(argv[1]) == 1)
	{
		ft_printf("file1 : no exist \n");
		return (-1);
	}
	if(file1_no_read_auth(argv[1]) == 1 || file2_no_write_auth(argv[argc-1]) == 1)
	{
		if(file1_no_read_auth(argv[1]) == 1)
			ft_printf("file1 : no read auth \n");
		if(file2_no_write_auth(argv[argc-1]) == 1)
			ft_printf("file2 : no write auth \n");
		return (-1);
	}
	if(cmd_unexit(argc,argv,envp) == 1)
	{
		ft_printf("cmd : unexist \n");
		return (-1);
	}
	return (0);
}

static int file1_unexist(char *path)
{
	if(access(path,F_OK) == 0)
		return (0);
	else
		return (1);
}

static int file1_no_read_auth(char *path)
{
	if(access(path,R_OK) == 0)
		return (0);
	else
		return (1);
}

static int file2_no_write_auth(char *path)
{
	if(access(path,F_OK) == -1)
	{
		// sononameno file wo tukuru hituyouaruyo
		return (0);
	}
	else if(access(path,W_OK) == 0)
		return (0);
	else
		return (1);
}

static int cmd_unexit(int argc,char **argv,char *envp[])
{
	int i;
	int unexist_flag;

	char *path;
	char **cmd;
	
	path = getpath_from_env(envp);
	if(path == NULL)
		return (1);
	
	unexist_flag = 0;
	i = 2;
	while(i < (argc-1))
	{
		cmd = ft_split(argv[i],' ');
		if(cmd == NULL)
			return (1);
		unexist_flag = checkcmd_unexist_from_path(cmd[0],path);
		int j = 0;
		while (cmd[j] != NULL)
		{
			free(cmd[j]);
			j++;
		}
		free(cmd);
		if(unexist_flag == 1)
			return (1);
		i++;
	}
	return (0);
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

static int checkcmd_unexist_from_path(char* argv,char *pathtop)
{
	int i;
	i = 0;
	char **path_candidate;
	char *fullpath_candidate;
	path_candidate = ft_split(pathtop,':');
	if(path_candidate == NULL)
		return (1);
	
	while(path_candidate[i] != NULL)
	{
		fullpath_candidate = malloc(ft_strlen(path_candidate[i]) + ft_strlen(argv) + 2);
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
			return (1);
		}
		fullpath_candidate = ft_strcat_threewords(fullpath_candidate,path_candidate[i],"/",argv);
		if(access(fullpath_candidate,X_OK) == 0)
		{
			ft_printf("path mikke!\n");
			ft_printf("%s\n",fullpath_candidate);
			free(fullpath_candidate);
			//splitの中身解放
			int j = 0;
			while (path_candidate[j] != NULL)
			{
				free(path_candidate[j]);
				j++;
			}
			free(path_candidate);
			return (0);
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
	return (1);
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
