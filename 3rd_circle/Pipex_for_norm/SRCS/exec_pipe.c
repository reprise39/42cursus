/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 00:58:03 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/08 19:48:00 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	set_pipe_fd(int pipe_fd[][2], int pipe_num);
void		exec_cmds(char **argv, char *envp[], int pipe_fd[][2],
				t_input *pipe_input);
static void	wait_children(int cmd_num);

int	exec_pipe(int argc, char **argv, char *envp[], t_input *pipe_input)
{
	int	pipe_fd[pipe_input->pipe_num][2];

	set_pipe_fd(pipe_fd, pipe_input->pipe_num);
	exec_cmds(argv, envp, pipe_fd, pipe_input);
	wait_children(pipe_input->cmd_num);
	return (0);
}

static void	set_pipe_fd(int pipe_fd[][2], int pipe_num)
{
	int	i;

	i = 0;
	while (i < pipe_num)
	{
		if (pipe(pipe_fd[i]) == -1)
		{
			perror("set_pipe_fd(pipe)");
			exit(-1);
		}
		i++;
	}
}

void	exec_cmds(char **argv, char *envp[], int pipe_fd[][2],
	t_input *pipe_input)
{
int		i;
pid_t	pid;

i = 0;
while (i < (pipe_input->cmd_num))
{
	(pipe_input->exec_i_num) = i;
	pid = fork();
	if (pid == -1)
	{
		perror("exec_cmds(fork_error)");
		exit(-1);
	}
	if (pid == 0)
	{
		close_not_neighbor_pipe(pipe_fd, pipe_input);
		exec_child(argv, envp, pipe_fd, pipe_input);
	}
	i++;
}
for (int j = 0; j < (pipe_input->cmd_num) - 1; j++)
{
	close(pipe_fd[j][0]);
	close(pipe_fd[j][1]);
}
}

static void	wait_children(int cmd_num)
{
	for (int i = 0; i < cmd_num; i++)
	{
		wait(NULL); // すべての子プロセスを待つ
	}
}

