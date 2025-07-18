/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:06:10 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/09 05:31:01 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	check_input(int argc)
{
	if (argc != 5)
	{
		ft_printf("Input Error : give just 5 arguments\n");
		return (INPUT_FORMAT_ERROR);
	}
	return (EXEC_PIPE_MODE);
}

int	main(int argc, char **argv, char *envp[])
{
	int	mode;

	mode = check_input(argc);
	if (mode == INPUT_FORMAT_ERROR)
		return (-1);
	if (pipe_mode(argc, argv, envp) != 0)
		return (-1);
	return (0);
}
