/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 00:15:10 by mkuida            #+#    #+#             */
/*   Updated: 2024/11/12 00:42:28 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strrchr(const char *s, int c)
{
	unsigned char	target;
	size_t			len;

	target = (unsigned int)c;
	len = ft_strlen(s);
	if (target == '\0')
		return (char *)(s + len);
	while (len != 0)
	{
		if (s[len - 1] == target)
			return (char *)(s + len - 1);
		len--;
	}
	return (NULL);
}
