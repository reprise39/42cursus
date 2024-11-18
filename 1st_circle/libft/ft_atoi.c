/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 02:30:59 by mkuida            #+#    #+#             */
/*   Updated: 2024/11/18 20:30:40 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	if (ch == '\f' || ch == '\n' || ch == '\r' || ch == '\t' || ch == '\v')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int		ans;
	int		sign;
	char	*ptr;

	ans = 0;
	ptr = (char *)nptr;
	sign = 1;
	if (nptr == NULL)
		return (0);
	while (ft_isspace(*ptr) == 1)
		ptr++;
	if (*ptr == '-')
	{
		sign = -1;
		ptr++;
	}
	else if (*ptr == '+')
		ptr++;
	while (ft_isdigit(*ptr) == 1)
	{
		ans *= 10;
		ans += *ptr - '0';
		ptr++;
	}
	return (ans * sign);
}
