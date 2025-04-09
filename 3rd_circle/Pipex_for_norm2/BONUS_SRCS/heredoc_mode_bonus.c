/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_mode_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 21:40:28 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/09 05:32:28 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	check_heredocmode_input(int argc, char **argv, char *env_path);
static void	heredoc(char *limitter);
static int	is_same_str(char *str_one, char *str_two);

int	heredoc_mode(int argc, char **argv, char *envp[])
{
	t_input	*pipe_input;
	char	*env_path;

	env_path = getpath_from_env(envp);
	if (env_path == NULL)
		return (-1);
	if (check_heredocmode_input(argc, argv, env_path) != 0)
		return (-1);
	pipe_input = set_struct(argc, argv, envp, HEREDOC_MODE);
	if (pipe_input == NULL)
		return (-1);
	heredoc(argv[2]);
	if (exec_pipe(argv, envp, pipe_input) != 0)
	{
		unlink(HEREDOC_TXT);
		return (-1);
	}
	if (pipe_input != NULL)
		free_struct(pipe_input);
	unlink(HEREDOC_TXT);
	return (0);
}

static int	check_heredocmode_input(int argc, char **argv, char *env_path)
{
	if (file2_no_write_auth(argv[argc - 1]) == 1)
	{
		ft_printf("Input Error : file2 don't have write auth \n");
		return (-1);
	}
	if (cmd_unexit_heredoc(argc, argv, env_path) == 1)
	{
		ft_printf("Input Error : cmd unexist \n");
		return (-1);
	}
	return (0);
}

static void	heredoc(char *limitter)
{
	int		fd;
	char	*line;

	fd = open(HEREDOC_TXT, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("heredoc");
		exit(-1);
	}
	while (1)
	{
		write(1, "> ", 3);
		line = get_next_line(STDIN_FILENO);
		if (line == NULL)
			break ;
		if (is_same_str(line, limitter) == 1)
		{
			free(line);
			break ;
		}
		write(fd, line, ft_strlen(line));
		free(line);
	}
	close(fd);
}

static int	is_same_str(char *line, char *limiter)
{
	size_t	len;

	len = ft_strlen(limiter);
	if (ft_strncmp(line, limiter, len) == 0 && line[len] == '\n')
		return (1);
	return (0);
}
