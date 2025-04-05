/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 00:58:03 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/06 04:28:58 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

static void set_pipe_fd(int pipe_fd[][2],int pipe_num);
static void exec_cmds(char **argv,char *envp[],int pipe_fd[][2],t_input *pipe_input);
static void wait_children(int cmd_num);


int exec_pipe(int argc,char **argv,char *envp[],t_input *pipe_input)
{
	ft_printf(" exec_start \n --- \n");
	int pipe_fd[pipe_input->pipe_num][2];
	set_pipe_fd(pipe_fd,pipe_input->pipe_num);
	exec_cmds(argv,envp,pipe_fd,pipe_input);
	wait_children(pipe_input->cmd_num);
	ft_printf(" exec_fin \n");
	return (0);
}

static void set_pipe_fd(int pipe_fd[][2],int pipe_num)
{
	int i;
	i = 0;
	while(i < pipe_num)
	{
		if(pipe(pipe_fd[i]) == -1)
		{
			perror("set_pipe_fd(pipe)");
			exit(-1);
		}
		i++;
	}
}
static void exec_cmds(char **argv,char *envp[],int pipe_fd[][2],t_input *pipe_input)
{
	int i;
	pid_t pid;
	i = 0;
	while(i < (pipe_input->cmd_num))
	{
		pid = fork();
		if(pid == -1)
		{
			perror("exec_cmds_fork_error");
			exit(-1);
		}
		if(pid == 0) //child prissess
		{
			//各子プロセスで使わない pipe をすべて閉じる
			for (int j = 0; j < pipe_input->pipe_num; j++)
			{
				if (j != i - 1) close(pipe_fd[j][0]); // 自分が読む pipe 以外
				if (j != i)     close(pipe_fd[j][1]); // 自分が書く pipe 以外
			}
			//pipe_set
			if(i == 0)//1st
			{
				int infile_fd = open(argv[1],O_RDONLY);
				if(infile_fd < 0)
				{
					perror("exec_cmds(open_infile_error)");
					exit(-1);
				}
				dup2(infile_fd,STDIN_FILENO);
				close(infile_fd);
				dup2(pipe_fd[0][1],STDOUT_FILENO);
			}
			else if(i == (pipe_input->cmd_num)-1)//last
			{
				int outfile_fd = open(argv[(pipe_input->cmd_num)+2],W_OK);
				if(outfile_fd < 0)
				{
					perror("exex_cmds(open_outfile_error)");
					exit(-1);
				}
				dup2(pipe_fd[i-1][0],STDIN_FILENO);
				dup2(outfile_fd,STDOUT_FILENO);
				close(outfile_fd);
			}
			else	//middle
			{
				dup2(pipe_fd[i-1][0],STDIN_FILENO);
				dup2(pipe_fd[i][1],STDOUT_FILENO);
			}
			execve(pipe_input->cmd_fullpath[i],pipe_input->cmd_phrase[i],envp);

			perror("exec_pipe(execve_error)");
			exit(-1);
		}
		i++;
	}
	// close_pipe();
	// 親プロセスは全てのパイプを閉じる
	for (int j = 0; j < (pipe_input->cmd_num) - 1; j++) {
		close(pipe_fd[j][0]);
		close(pipe_fd[j][1]);
	}
}

static void wait_children(int cmd_num)
{
	for (int i = 0; i < cmd_num; i++)
	{
		wait(NULL);  // すべての子プロセスを待つ
	}
}
