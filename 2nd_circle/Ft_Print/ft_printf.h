/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:24:44 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/02 15:13:51 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINT_H

# define FT_PRINT_H
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>
# include <limits.h>
# include <unistd.h>

int 	ft_printf(const char *str, ...);
int ft_print_lowerx(va_list args,int words_counted);
int ft_print_upperx(va_list args,int words_counted);
int	ft_printdi(va_list args,int words_counted);
int ft_printu(va_list args,int words_counted);
int ft_printc(va_list args,int words_counted);
int ft_prints(va_list args,int words_counted);
int ft_printp(va_list args,int words_counted);
int ft_printpercent(int words_counted);

#endif