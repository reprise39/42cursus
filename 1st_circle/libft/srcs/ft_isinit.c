/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:52:31 by mkuida            #+#    #+#             */
/*   Updated: 2024/11/13 20:52:23 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isinit(char c, char const *str)
{
	size_t	i;
	size_t	str_len;

	i = 0;
	str_len = ft_strlen(str);
	while (i < str_len)
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}
