/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:59:13 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/02 16:40:43 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char *str;
	char c;
	int d;
	void *p;
	int i;

	str = 0;
	c = 'a';
	d = -1;
	p = 0;

	// printf
	i = printf("std_printf        > %d \n", d);
	printf("std_printf_return > %d \n", i - 22);
	printf("\n");
	fflush(stdout);
	// ft_printf
	i = ft_printf("ft__printf        > %d \n", d);
	ft_printf("ft__printf_return > %d \n", i - 22);
	return (0);
}