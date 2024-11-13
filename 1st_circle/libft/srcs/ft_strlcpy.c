/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:53:24 by mkuida            #+#    #+#             */
/*   Updated: 2024/11/12 18:00:14 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t src_size;

	i=0;
	src_size = ft_strlen(src);
	if(dstsize == 0)
		return src_size;
	while(i < src_size && i < dstsize-1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return src_size;
}
