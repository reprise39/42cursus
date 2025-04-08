/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_mode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 03:24:07 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/08 20:16:51 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	check_pipemode_input(int argc, char **argv, char *env_path);

int	pipe_mode(int argc, char **argv, char *envp[])
{
	t_input	*pipe_input;
	char	*env_path;

	env_path = getpath_from_env(envp);
	if (env_path == NULL)
		return (-1);
	if (check_pipemode_input(argc, argv, env_path) != 0)
		return (-1);
	pipe_input = set_struct(argc, argv, envp);
	if (pipe_input == NULL)
		return (-1);
	if (exec_pipe(argc, argv, envp, pipe_input) != 0)
		return (-1);
	if (pipe_input != NULL)
		free_struct(pipe_input);
	return (0);
}

int	check_pipemode_input(int argc, char **argv, char *env_path)
{
	if (file1_unexist(argv[1]) == 1)
	{
		ft_printf("Input Error :file1 not exist \n");
		return (-1);
	}
	if (file1_no_read_auth(argv[1]) == 1
		|| file2_no_write_auth(argv[argc - 1]) == 1)
	{
		if (file1_no_read_auth(argv[1]) == 1)
			ft_printf("Input Error : file1 don't have read auth \n");
		if (file2_no_write_auth(argv[argc - 1]) == 1)
			ft_printf("Input Error : file2 don't have write auth \n");
		return (-1);
	}
	if (cmd_unexit(argc, argv, env_path) == 1)
	{
		ft_printf("Input Error : cmd unexist \n");
		return (-1);
	}
	return (0);
}
