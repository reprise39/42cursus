/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:15:41 by mkuida            #+#    #+#             */
/*   Updated: 2024/11/25 19:52:48 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int ft_printf(const char *str, ...)
{
	va_list args;
	va_start(args,str);
	int words_count;

	if(str == NULL)
		return (-1);

	while(*str != '\0')
	{
		if(*str == "%")
		{
			check_and_call(str);
		}
		else
		{
			write(1,str,1);
			str++;
		}
	}
	va_end(args);
	return (words_count);
}
