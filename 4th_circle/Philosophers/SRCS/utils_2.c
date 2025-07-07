/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:41:45 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/07 19:41:45 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*cpy;
	unsigned char	*tar;
	size_t			i;

	if (dest == NULL)
		return (NULL);
	if (src == NULL)
		return (dest);
	cpy = (unsigned char *)dest;
	tar = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		cpy[i] = tar[i];
		i++;
	}
	return (dest);
}

int	ft_set_ltoa(long input, char *dest)
{
	int		len;
	int		i;
	char	rev_char[20];

	len = 0;
	if (input == 0)
	{
		dest[0] = '0';
		return (1);
	}
	while (input > 0)
	{
		rev_char[len] = (input % 10) + '0';
		len++;
		input = input / 10;
	}
	i = len;
	while (i != 0)
	{
		dest[i - 1] = rev_char[len - i];
		i--;
	}
	return (len);
}
