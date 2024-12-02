/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:49:52 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/02 14:53:55 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

static int	print_lowerx_recursive(unsigned int u, int words_counted)
{
	char	printc;
	const char *charset = "0123456789abcdef";

	printc = charset[u % 16];
	if (u >= 16)
	{
		u = u / 16;
		words_counted = print_lowerx_recursive(u, words_counted);
	}
	write(1, &printc, 1);
	return (words_counted + 1);
}


int ft_print_lowerx(va_list args,int words_counted)
{
	int d;
	int count_words;
	char *a;

	count_words = 0;
	d = va_arg(args, int);
	count_words = print_lowerx_recursive(d,count_words);
	ft_putstr_fd(a,STDOUT_FILENO);
	return (words_counted + count_words);
}

static int	print_upperx_recursive(unsigned int u, int words_counted)
{
	char	printc;
	const char *charset = "0123456789ABCDEF";

	printc = charset[u % 16];
	if (u >= 16)
	{
		u = u / 16;
		words_counted = print_lowerx_recursive(u, words_counted);
	}
	write(1, &printc, 1);
	return (words_counted + 1);
}

int ft_print_upperx(va_list args,int words_counted)
{
	int d;
	int count_words;
	char *a;

	count_words = 0;
	d = va_arg(args, int);
	count_words = print_upperx_recursive(d,count_words);
	ft_putstr_fd(a,STDOUT_FILENO);
	return (words_counted + count_words);
}
