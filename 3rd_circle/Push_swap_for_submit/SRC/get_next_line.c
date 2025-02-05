/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 20:24:51 by mkuida            #+#    #+#             */
/*   Updated: 2025/02/05 17:23:12 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../get_next_line.h"
#include "../libft_added_ftprintf/libft.h"

static char	*strjoin_and_free(char *freed_str, char const *added_str)
{
	char	*return_dest;
	size_t	fr_len;
	size_t	ad_len;

	if (freed_str == NULL && added_str == NULL)
		return (NULL);
	else if (freed_str == NULL)
		return (ft_strdup(added_str));
	fr_len = ft_strlen(freed_str);
	ad_len = ft_strlen(added_str);
	if (fr_len + ad_len == 0 || fr_len > SIZE_MAX - ad_len)
	{
		free(freed_str);
		return (ft_strdup(""));
	}
	return_dest = malloc((fr_len + ad_len) * sizeof(char) + 1);
	if (return_dest == NULL)
	{
		free(freed_str);
		return (NULL);
	}
	ft_strlcpy(return_dest, freed_str, fr_len + 1);
	ft_strlcpy(return_dest + fr_len, added_str, ad_len + 1);
	free(freed_str);
	return (return_dest);
}

static char	*mem_update(int fd, char *saved_mem)
{
	char	*buffer;
	size_t	read_value;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	read_value = 1;
	while (ft_strchr(saved_mem, '\n') == NULL && read_value != 0)
	{
		read_value = read(fd, buffer, BUFFER_SIZE);
		if (read_value == (size_t)(-1) || (!read_value && !saved_mem))
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_value] = '\0';
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
	char	*dest;

	if (saved_mem == NULL || *saved_mem == '\0')
		return (NULL);
	i = 0;
	while (saved_mem[i] != '\n' && saved_mem[i] != '\0')
		i++;
	dest = malloc(sizeof(char) * (i + 2));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (saved_mem[i] != '\n' && saved_mem[i] != '\0')
	{
		dest[i] = saved_mem[i];
		i++;
	}
	if (saved_mem[i] == '\n')
	{
		dest[i] = '\n';
		i++;
	}
	dest[i] = '\0';
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

char	*get_next_line(int fd)
{
	static char	*saved_mem;
	char		*dest_line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	saved_mem = mem_update(fd, saved_mem);
	dest_line = put_savedmem_before_linebreak(saved_mem);
	if (dest_line == NULL)
	{
		free(saved_mem);
		saved_mem = NULL;
		return (NULL);
	}
	saved_mem = cut_savedmem_before_linebreak(saved_mem);
	return (dest_line);
}
