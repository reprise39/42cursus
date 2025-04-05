/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 20:06:10 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/02 21:06:31 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

int main()
{
	int pid;
	int fd[2];

	pipe(fd);
	pid = fork();
	if(pid == 0)
	{
		close(fd[0]); //0は読み
		write(fd[1], "Hello, pipe!\n", 13);
		close(fd[1]);
	}
	else
	{
		char buf[100];
		close(fd[1]); //1は書き
		read(fd[0], buf, 100);
		printf("Received: %s", buf);
		close(fd[0]);  // 0読み取り
	}


	return 0;
}