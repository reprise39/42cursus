/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:54:25 by mkuida            #+#    #+#             */
/*   Updated: 2025/03/10 16:38:59 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft_added_ftprintf/libft.h"
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