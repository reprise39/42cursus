/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:24:51 by mkuida            #+#    #+#             */
/*   Updated: 2024/11/24 22:29:43 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*mem_update(int fd, char *saved_mem)
{
	char	*buffer;
	size_t	return_read_value;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	return_read_value = 1;
	while (ft_strchr(saved_mem, '\n') == NULL && return_read_value != 0)
	{
		return_read_value = read(fd, buffer, BUFFER_SIZE);
		if (return_read_value < 0 || (return_read_value == 0 && saved_mem == NULL))
		{
			free(buffer);
			return (NULL);
		}
		buffer[return_read_value] = '\0';
		saved_mem = strjoin_and_free(saved_mem, buffer);
		if (saved_mem == NULL)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (saved_mem);
}

static char	*put_savedmem_before_linebreak(char *saved_mem)
{
	size_t	i;
	size_t	j;
	char	*dest;

	if (saved_mem == NULL || *saved_mem == '\0')
		return (NULL);
	i = 0;
	j = 0;
	while (saved_mem[i] != '\n' && saved_mem[i] != '\0')
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (dest == NULL)
		return (NULL);
	while (j < i)
	{
		dest[j] = saved_mem[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

static char	*cut_savedmem_before_linebreak(char *saved_mem)
{
	size_t	i;
	char	*dest;

	if (saved_mem == NULL)
		return (NULL);
	i = 0;
	while (saved_mem[i] != '\n' && saved_mem[i] != '\0')
		i++;
	if (saved_mem[i] == '\0')
	{
		free(saved_mem);
		return (NULL);
	}
	dest = malloc(sizeof(char) * (ft_strlen(saved_mem) - i + 1));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, saved_mem + i + 1, ft_strlen(saved_mem) - i);
	free(saved_mem);
	return (dest);
}

// static char	*cut_savedmem_before_linebreak(char *saved_mem)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*dest;

// 	if (saved_mem == NULL)
// 		return (NULL);
// 	i = 0;
// 	j = 0;
// 	while (saved_mem[i] != '\n')
// 	{
// 		if (saved_mem[i] == '\0')
// 			return (NULL);
// 		i++;
// 	}
// 	dest = malloc(sizeof(char) * (ft_strlen(saved_mem) - i));
// 	if (dest == NULL)
// 		return (NULL);
// 	while (saved_mem[i + 1 + j] != '\0')
// 	{
// 		dest[j] = saved_mem[i + 1 + j];
// 		j++;
// 	}
// 	dest[j] = '\0';
// 	free(saved_mem);
// 	return (dest);
// }

char	*get_next_line(int fd)
{
	static char	*saved_mem[FD_SIZE];
	char		*dest_line;

	if (BUFFER_SIZE <= 0 || fd < 0 )
		return (NULL);
	saved_mem[fd] = mem_update(fd, saved_mem[fd]);
	dest_line = put_savedmem_before_linebreak(saved_mem[fd]);
	if (dest_line == NULL)
	{
		if(saved_mem[fd] != NULL)
		{
			free(saved_mem[fd]);
			saved_mem[fd] == NULL;
		}
		return (NULL);
	}
	saved_mem[fd] = cut_savedmem_before_linebreak(saved_mem[fd]);
	return (dest_line);
}
