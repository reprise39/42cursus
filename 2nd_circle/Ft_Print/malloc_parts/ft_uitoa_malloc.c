/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:06:15 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/02 13:58:32 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

static void	str_nreverse(char *str, size_t str_size)
{
	size_t	i;
	char	temp;

	i = 0;
	while (str_size / 2 > i)
	{
		temp = str[str_size - 1 - i];
		str[str_size - 1 - i] = str[i];
		str[i] = temp;
		i++;
	}
}

static size_t	cal_strsize(unsigned int n)
{
	size_t	str_size;

	str_size = 0;
	while (n != 0)
	{
		str_size++;
		n /= 10;
	}
	return (str_size);
}

static void	mal_pad(char *dest, unsigned int n)
{
	size_t	i;

	i = 0;
	while (n != 0)
	{
		dest[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	dest[i] = '\0';
}

static char	*uitoa_corners(unsigned int n)
{
	char	*dest;

	if (n == 0)
	{
		dest = malloc(2);
		if (dest == NULL)
			return (NULL);
		ft_strlcpy(dest, "0", 2);
		return (dest);
	}
	return (NULL);
}

char	*ft_uitoa_malloc(unsigned int n)
{
	char	*dest;
	size_t	str_size;

	str_size = 0;
	if (n == 0)
	{
		dest = uitoa_corners(n);
		return (dest);
	}
	str_size = cal_strsize(n);
	dest = malloc(str_size + 1);
	if (dest == NULL)
		return (NULL);
	mal_pad(dest, n);
	str_nreverse(dest, str_size);
	return (dest);
}
