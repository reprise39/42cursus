/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 15:01:14 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/02 14:46:04 by mkuida           ###   ########.fr       */
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

static size_t	cal_strsize(long long n,int base_size)
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

static void	mal_pad(char *dest, long long n,const char *base,int base_size)
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


char *ft_itoa_base(int i, const char *base)
{
	const int base_size = ft_strlen(base);
	char *dest;
	long long ilong;
	size_t str_size;

	if(base_size == 0)
		return NULL;
	ilong = (long long)i;
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


int ft_print_lowerx_malloc(va_list args,int words_count)
{
	int d;
	int count_words;
	char *a;
	const char *x = "0123456789abcdef";

	d = va_arg(args, int);
	a = ft_itoa_base(d,x);
	if(a == NULL)
		return (-1);
	count_words = (int)ft_strlen(a);
	ft_putstr_fd(a,STDOUT_FILENO);
	return (words_count + count_words);
}

int ft_printdi_malloc(va_list args,int words_count)
{
	int d;
	int count_words;
	char *a;
	d = va_arg(args, int);
	a = ft_itoa(d);
	if(a == NULL)
		return (-1);
	count_words = (int)ft_strlen(a);
	ft_putstr_fd(a,STDOUT_FILENO);
	free(a);
	return (words_count + count_words);
}

int ft_printp_malloc(va_list args,int words_count)
{
	void *p;
	char *a;
	int count_words;
	const char *x = "0123456789abcdef";
	//uintptr_t
	uintptr_t address;
	p = va_arg(args, void *);
	address = (uintptr_t)p;
	a = ft_itoa_base(address,x);
	if(a == NULL)
		return(-1);
	count_words = (int)ft_strlen(a);
	ft_putstr_fd("0x",STDOUT_FILENO);
	ft_putstr_fd(a,STDOUT_FILENO);
	free(a);
	return (count_words + words_count+ 2);
}

int ft_print_upperx_malloc(va_list args,int words_count)
{
	int d;
	int count_words;
	char *a;
	const char *x = "0123456789ABCDEF";

	d = va_arg(args, int);
	a = ft_itoa_base(d,x);
	if(a == NULL)
		return (-1);
	count_words = (int)ft_strlen(a);
	ft_putstr_fd(a,STDOUT_FILENO);
	return (words_count + count_words);
}