/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipemode_input_file.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 05:03:02 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/06 05:19:49 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

int file1_unexist(char *path)
{
	if(access(path,F_OK) == 0)
		return (0);
	else
		return (1);
}

int file2_unexist(int argc,char **argv)
{
	int file2_dest;
	file2_dest = argc-1; 
	if(access(argv[file2_dest],F_OK) == 0)
		return (0);
	else
		return (1);
}

int file1_no_read_auth(char *path)
{
	if(access(path,R_OK) == 0)
		return (0);
	else
		return (1);
}

int file2_no_write_auth(char *path)
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
