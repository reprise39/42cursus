/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 03:09:28 by mkuida            #+#    #+#             */
/*   Updated: 2024/11/13 04:16:20 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

char *str_nreverse(char *str,size_t size)
{
	size_t i;
	char temp;

	i=0;
	while(size/2 > i)
	{
		temp = str[size-1-i];
		str[size-1-i] = str[i];
		str[i] = temp;
		i++;
	}
	return str;
}
size_t cal_strsize(int n)
{
	size_t str_size;

	str_size = 0;
	if(n < 0)
		str_size++;
	while(n != 0)
	{
		str_size++;
		n /= 10;
	}
	return str_size;
}
void mal_pad(char *dest,int n)
{
	size_t i;
	size_t minus_flag;
	
	i = 0;
	minus_flag = 0;
	if(n < 0)
	{
		minus_flag = 1;
		n *= -1;
	}
	dest[i] = '\0';
	while(n != 0)
	{
		dest[i++] = (n % 10) + '0';
		n /= 10;
	}
	if(minus_flag)
		dest[i++] = '-';
}

char *ft_itoa(int n)
{
	char *dest;
	size_t str_size;

	str_size = 0;
	if(n == INT_MIN)
	{
		dest = malloc(12);
		if(dest == NULL)
			return NULL;
		ft_strlcpy(dest,"-2147483648",12);
		return dest;
	}
	str_size = cal_strsize(n);
	dest = malloc(str_size + 1);
	if(dest == NULL)
		return NULL;
	mal_pad(dest,n);
	dest = str_nreverse(dest,str_size+1);
	return dest;
}
