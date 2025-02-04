/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:54:25 by mkuida            #+#    #+#             */
/*   Updated: 2025/02/04 18:03:45 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//buffer_size
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//header
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

//main function
char	*get_next_line(int fd);

#endif