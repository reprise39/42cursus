/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:30:11 by mkuida            #+#    #+#             */
/*   Updated: 2024/11/25 16:04:07 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	if (s == NULL || n == 0)
		return ;
	str = (unsigned char *)s;
	while (n != 0)
	{
		*str = '\0';
		str++;
		n--;
	}
}
