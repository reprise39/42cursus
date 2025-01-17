/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:47:14 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/27 20:42:55 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *s)
{
	char	*str;

	if (s == NULL)
		return ((size_t)(-1));
	str = (char *)s;
	while (*str != '\0')
		str++;
	return (str - s);
}

// never input added_str NULL
	// else if (added_str == NULL)
	// {
	// 	return_dest = ft_strdup(freed_str);
	// 	free(freed_str);
	// 	return (return_dest);
	// }

char	*strjoin_and_free(char *freed_str, char const *added_str)
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

// int	ft_strlcpy(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	i;
// 	size_t	src_size;

// 	if (dst == NULL || src == NULL)
// 		return ((size_t)(-1));
// 	i = 0;
// 	src_size = ft_strlen(src);
// 	if (dstsize == 0)
// 		return (src_size);
// 	while (i < src_size && i < dstsize - 1)
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	dst[i] = '\0';
// 	return (src_size);
// }

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*dest;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	dest = malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[len] = '\0';
	return (dest);
}
