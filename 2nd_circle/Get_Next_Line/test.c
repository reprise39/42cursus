/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 21:48:59 by mkuida            #+#    #+#             */
/*   Updated: 2024/11/23 18:25:47 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	line = "";
	fd = open("masahiko.txt", O_RDONLY);
	printf("\n yobidasimae \n");
	while (line)
	{
		line = get_next_line(fd);
		printf("> %s", line);
		free(line);
	}
	printf("\n end \n");
	fflush(stdout);
	return (0);
}
