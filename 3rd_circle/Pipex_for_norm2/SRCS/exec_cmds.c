/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 08:08:24 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/09 17:45:11 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_child(char **argv, char *envp[], int pipe_fd[][2],
		t_input *pipe_input)
{
	int	i;

	i = (pipe_input->exec_i_num);
	if (i == 0)
	{
		exec_first_cmd(argv, envp, pipe_fd, pipe_input);
	}
	else if (i == (pipe_input->cmd_num) - 1)
	{
		exec_last_cmd(argv, envp, pipe_fd, pipe_input);
	}
	else
		exec_mid_cmd(envp, pipe_fd, pipe_input);
}

void	close_not_neighbor_pipe(int pipe_fd[][2], t_input *pipe_input)
{
	int	i;
	int	j;

	i = (pipe_input->exec_i_num);
	j = 0;
	while (j < (pipe_input->pipe_num))
	{
		if (j != i - 1)
			close(pipe_fd[j][0]);
		if (j != i)
			close(pipe_fd[j][1]);
		j++;
	}
}

void	exec_first_cmd(char **argv, char *envp[], int pipe_fd[][2],
		t_input *pipe_input)
{
	int	i;
	int	infile_fd;

	i = (pipe_input->exec_i_num);
	if (pipe_input->mode == PIPE_MODE)
		infile_fd = open(argv[1], O_RDONLY);
	else
		infile_fd = open(HEREDOC_TXT, O_RDONLY);
	if (infile_fd < 0)
	{
		perror("exec_cmds(open_infile_error)");
		unlink(HEREDOC_TXT);
		exit(-1);
	}
	dup2(infile_fd, STDIN_FILENO);
	close(infile_fd);
	dup2(pipe_fd[0][1], STDOUT_FILENO);
	execve(pipe_input->cmd_fullpath[i], pipe_input->cmd_phrase[i], envp);
	perror("exec_pipe(execve_first_error)");
	unlink(HEREDOC_TXT);
	exit(-1);
}

void	exec_last_cmd(char **argv, char *envp[], int pipe_fd[][2],
		t_input *pipe_input)
{
	int	i;
	int	outfile_fd;

	i = (pipe_input->exec_i_num);
	if (pipe_input->mode == PIPE_MODE)
		outfile_fd = open(argv[(pipe_input->cmd_num) + 2],
				O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (pipe_input->mode == HEREDOC_MODE)
		outfile_fd = open(argv[(pipe_input->cmd_num) + 3],
				O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (outfile_fd < 0)
	{
		perror("exex_cmds(open_outfile_error)");
		unlink(HEREDOC_TXT);
		exit(-1);
	}
	dup2(pipe_fd[i - 1][0], STDIN_FILENO);
	dup2(outfile_fd, STDOUT_FILENO);
	close(outfile_fd);
	execve(pipe_input->cmd_fullpath[i], pipe_input->cmd_phrase[i], envp);
	perror("exec_pipe(execve_last_error)");
	unlink(HEREDOC_TXT);
	exit(-1);
}

void	exec_mid_cmd(char *envp[], int pipe_fd[][2],
		t_input *pipe_input)
{
	int	i;

	i = (pipe_input->exec_i_num);
	dup2(pipe_fd[i - 1][0], STDIN_FILENO);
	dup2(pipe_fd[i][1], STDOUT_FILENO);
	execve(pipe_input->cmd_fullpath[i], pipe_input->cmd_phrase[i], envp);
	perror("exec_pipe(execve_middle_error)");
	unlink(HEREDOC_TXT);
	exit(-1);
}
