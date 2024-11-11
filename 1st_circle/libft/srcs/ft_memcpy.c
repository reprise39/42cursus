/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:36:54 by mkuida            #+#    #+#             */
/*   Updated: 2024/11/11 19:49:58 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char *cpy;
	unsigned char *tar;
	size_t i;

	cpy = (unsigned char *)dest;
	tar = (unsigned char *)src;
	i = 0;
	while(i < n)
	{
		cpy[i] = tar[i];
		i++;
	}
	return dest;
}
