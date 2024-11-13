/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:01:29 by mkuida            #+#    #+#             */
/*   Updated: 2024/11/13 20:51:42 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_size;
	size_t	src_size;
	size_t	total_size;
	size_t	i;

	i = 0;
	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	total_size = dst_size + src_size;
	if (dst_size >= dstsize)
		return (dstsize + src_size);
	while (dst_size + i < dstsize - 1 && i < src_size)
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	dst[dst_size + i] = '\0';
	return (total_size);
}
