/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:54:25 by mkuida            #+#    #+#             */
/*   Updated: 2024/11/22 23:16:23 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h> //kari
# include <stdint.h>

//main function
char *get_next_line(int fd);

//util functions
size_t ft_strlen(const char *s);
char	*strjoin_and_free(char *freed_str, char const *added_str);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif