/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check_input.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:58:55 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/04 23:04:56 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft_added_ftprintf/libft.h"
# include "push_swap.h"

static int check_number_of_digits(char *numstart,int sign_flag)
{
	int i;
	const int numsize = ft_strlen(numstart);
	const char *intmax = "2147483647"; 
	const char *intmin = "2147483648";
	
	i = 0;
	if(numsize > 10)
		return (0);
	else if(numsize == 10 && sign_flag == 1)
	{
		while(numstart[i] != '\0')
		{
			if(intmax[i] < numstart[i])
				return (0);
			i++;
		}
	}
	else if(numsize == 10 && sign_flag == -1)
	{
		while(numstart[i] != '\0')
		{
			if(intmin[i] < numstart[i])
				return (0);
			i++;
		}
	}
	return (1);
}

static int check_isintnumber(char *str)
{
	int sign_flag;
	char *numstart;

	sign_flag = 1;
	while(ft_isspace(*str) == 1)
		str++;
	if(*str == '+')
		str++;
	else if(*str == '-')
	{	
		str++;
		sign_flag = -1;
	}
	numstart = str;
	while(*str != '\0')
	{
		if(ft_isdigit(*str) != 1)
			return (0);
		str++;
	}
	if(check_number_of_digits(numstart,sign_flag) == 1)
		return (1);
	else
		return (0);
}

int check_input(int argc,char **argv)
{
	int i;

	i = 1;
	while(i < argc)
	{
		if(check_isintnumber(argv[i]) != 1)
			return (-1);
		i++;
	}
	return (0);
}

