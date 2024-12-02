/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 16:59:13 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/02 13:56:24 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>
# include "ft_printf.h"
int main()
{
	char *str;
	char c;
	int d;
	d = 12345678;
	c = 'a';
	str = "%";
	int i;
	//printf
	i = printf("std_printf        > %d \n",d);
	printf("std_printf_return > %d \n",i-22);
	printf("\n");
	fflush(stdout);
	//ft_printf
	i = ft_printf("ft__printf        > %d \n",d);
	ft_printf("ft__printf_return > %d \n",i-22);
	return 0;
}