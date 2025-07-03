/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 08:05:26 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/03 08:05:26 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosophers.h"

int ft_isdigit_str(const char *str)
{
	int i;

	i = 0;
	while (ft_is_spase(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_is_digit((const char)str[i]))
		i++;
	if (str[i] != '\0')
		return (1);
	return (0);
}

static int	check_over_intmanx_corner(const char *str)
{
	int i;
	const char *intmax_str = "2147483647";

	i = 0;
	while(*str != '\0')
	{
		if(str[i] > intmax_str[i])
			return (1);
		else if(str[i] < intmax_str[i])
			return (0);
		else if(str[i] == intmax_str[i])
			i++;
		else
		{
			printf("souteigai\n");
			exit (1);
		}
	}
	return (0);
}


static int check_over_intmax(const char *str)
{
	const int intmax_len = 10;

	if (ft_strlen((const char*)str) > intmax_len)
		return (1);
	else if (ft_strlen(str) < intmax_len)
		return (0);
	else
	{
		if(check_over_intmanx_corner(str) == 1)
			return (1);
		else
			return (0);
	}
}


int ft_isposiint_str(const char *str)
{
	int i;

	i = 0;
	while (ft_is_spase((const char)str[i]))
		i++;
	if (str[i] == '-')
		return (0);	
	if (str[i] == '+')
		i++;
	if(check_over_intmax((const char*)&str[i]) == 1)
		return (0);
	return (1);
}



