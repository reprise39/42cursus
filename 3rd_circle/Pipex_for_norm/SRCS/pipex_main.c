/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:06:10 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/08 19:11:51 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	check_input(int argc, char **argv)
{
	if (argc < 5)
	{
		ft_printf("Input Error : too few arguments\n");
		return (INPUT_FORMAT_ERROR);
	}
	else if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		return (EXEC_HEREDOC_MODE);
	else
		return (EXEC_PIPE_MODE);
}

int	main(int argc, char **argv, char *envp[])
{
	int	mode;

	mode = check_input(argc, argv);
	if (mode == INPUT_FORMAT_ERROR)
		return (-1);
	else if (mode == EXEC_HEREDOC_MODE)
	{
		ft_printf("exec : heredoc_mode\n");
		// heredoc(argc,argv,envp);
	}
	else if (mode == EXEC_PIPE_MODE)
	{
		ft_printf("exec : pipe_mode\n");
		if (pipe_mode(argc, argv, envp) != 0)
			return (-1);
	}
	return (0);
}
