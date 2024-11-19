/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:24:51 by mkuida            #+#    #+#             */
/*   Updated: 2024/11/19 21:01:12 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "get_next_line.h"

char *get_next_line(int fd)
{
    if(read(fd,BUFFER_SIZE,BUFFER_SIZE + 1 ) == -1 || BUFFER_SIZE <= 0)
        return (NULL);
    
    
}