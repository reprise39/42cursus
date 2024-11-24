/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:48:59 by mkuida            #+#    #+#             */
/*   Updated: 2024/11/25 00:07:02 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	char	*line1;
	char	*line2;

	line1 = "";
	line2 = "";
	fd1 = open("masahiko.txt", O_RDONLY);
	fd2 = open("saki.txt", O_RDONLY);
	while (!(line1 == NULL && line2 == NULL))
	{
		line1 = get_next_line(fd1);
		if(line1 != NULL)
		{
			printf(">1 %s\n", line1);
			free(line1);
		}

		line2 = get_next_line(fd2);
		if(line2 != NULL)
		{
			printf(">2 %s\n", line2);
			free(line2);
		}
	}
	close(fd1);
	close(fd2);
	printf("end\n");
	return (0);
}
