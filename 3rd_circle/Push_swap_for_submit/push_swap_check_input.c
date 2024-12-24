/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check_input.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:58:55 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/24 18:50:37 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_added_ftprintf/libft.h"
#include "push_swap.h"

static int	check_number_of_digits_tendigit(char *numstart, int posi_or_nega)
{
	const char	*intmax = "2147483647";
	const char	*intmin = "2147483648";
	char		*competi;
	int			i;

	i = 0;
	if (posi_or_nega == 1)
		competi = (char *)intmax;
	else if (posi_or_nega == -1)
		competi = (char *)intmin;
	else
		return (-1);
	while (competi[i] != '\0')
	{
		if (competi[i] < numstart[i])
			return (0);
		else if (competi[i] == numstart[i])
			i++;
		else
			return (1);
	}
	return (1);
}

static int	check_number_of_digits(char *numstart, int sign_flag)
{
	int			i;
	const int	numsize = ft_strlen(numstart);

	i = 0;
	if (numsize > 10)
		return (0);
	else if (numsize == 10)
		return (check_number_of_digits_tendigit(numstart, sign_flag));
	return (1);
}

static int	check_isintnumber(char *str)
{
	int		sign_flag;
	char	*numstartptr;

	sign_flag = 1;
	while (ft_isspace(*str) == 1)
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		str++;
		sign_flag = -1;
	}
	numstartptr = str;
	while (*str != '\0')
	{
		if (ft_isdigit(*str) != 1)
			return (0);
		str++;
	}
	if (check_number_of_digits(numstartptr, sign_flag) == 1)
		return (1);
	else
		return (0);
}

int	check_input(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (check_isintnumber(argv[i]) != 1)
			return (-1);
		i++;
	}
	return (0);
}
