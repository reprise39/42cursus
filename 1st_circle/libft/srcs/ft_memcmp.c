/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:20:42 by mkuida            #+#    #+#             */
/*   Updated: 2024/11/13 20:51:55 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*suc1;
	unsigned char	*suc2;

	suc1 = (unsigned char *)s1;
	suc2 = (unsigned char *)s2;
	i = 0;
	while (n > i)
	{
		if (suc1[i] != suc2[i])
			return ((int)(suc1[i] - suc2[i]));
		i++;
	}
	return (0);
}
