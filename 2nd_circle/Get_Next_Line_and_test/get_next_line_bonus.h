/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:54:25 by mkuida            #+#    #+#             */
/*   Updated: 2024/11/24 22:43:04 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//buffer_size
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
//fd_size(ulimit -n)
# ifndef FD_SIZE
#  define FD_SIZE 1024
# endif

//header
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

//main function
char	*get_next_line(int fd);
//util functions
size_t	ft_strlen(const char *s);
char	*strjoin_and_free(char *freed_str, char const *added_str);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);

#endif