/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 00:58:03 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/08 23:16:31 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	set_pipe_fd(int pipe_fd[][2], int pipe_num);
void		exec_cmds(char **argv, char *envp[], int pipe_fd[][2],
				t_input *pipe_input);
static void	wait_children(int cmd_num);
static void	close_fd(t_input *pipe_input, int pipe_fd[][2]);

int	exec_pipe(int argc, char **argv, char *envp[], t_input *pipe_input)
{
	int	(*pipe_fd)[2];

	pipe_fd = malloc(sizeof(int) * 2 * (pipe_input->pipe_num));
	if (pipe_fd == NULL)
	{
		perror("exec_pipe");
		exit(-1);
	}
	set_pipe_fd(pipe_fd, pipe_input->pipe_num);
	exec_cmds(argv, envp, pipe_fd, pipe_input);
	wait_children(pipe_input->cmd_num);
	free(pipe_fd);
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
	close_fd(pipe_input, pipe_fd);
}

static void	wait_children(int cmd_num)
{
	int	i;

	i = 0;
	while (i < cmd_num)
	{
		wait(NULL);
		i++;
	}
}

static void	close_fd(t_input *pipe_input, int pipe_fd[][2])
{
	int	i;

	i = 0;
	while (i < (pipe_input->cmd_num) - 1)
	{
		close(pipe_fd[i][0]);
		close(pipe_fd[i][1]);
		i++;
	}
}
