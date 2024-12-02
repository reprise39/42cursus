/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintptoa_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:36:47 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/01 18:38:43 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"
# include "./libft/libft.h"

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

static size_t	cal_strsize(uintptr_t n,int base_size)
{
	size_t	str_size;

	str_size = 0;
	if (n < 0)
		str_size++;
	while (n != 0)
	{
		str_size++;
		n /= base_size;
	}
	return (str_size);
}

static void	mal_pad(char *dest, uintptr_t n,const char *base,int base_size)
{
	size_t	i;
	size_t	minus_flag;

	i = 0;
	minus_flag = 0;
	if (n < 0)
	{
		minus_flag = 1;
		n *= -1;
	}
	while (n != 0)
	{
		dest[i] = base[(n % base_size)];
		n /= base_size;
		i++;
	}
	if (minus_flag)
	{
		dest[i] = '-';
		i++;
	}
	dest[i] = '\0';
}


char *ft_uintptoa_base(uintptr_t i, const char *base)
{
	const int base_size = ft_strlen(base);
	char *dest;
	uintptr_t ilong;
	size_t str_size;

	if(base_size == 0)
		return NULL;
	ilong = (uintptr_t)i;
	if(i == 0)
	{

	}
	str_size = cal_strsize(ilong,base_size);
	dest = malloc(str_size + 1);
	if (dest == NULL)
		return (NULL);
	mal_pad(dest, ilong ,base,base_size);
	str_nreverse(dest, str_size);
	return (dest);	
}
