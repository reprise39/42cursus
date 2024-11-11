/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 23:42:44 by mkuida            #+#    #+#             */
/*   Updated: 2024/11/12 00:13:42 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

char *ft_strchr(const char *s, int c)
{
	size_t i;
	unsigned char uc;

	i = 0;
	uc = (unsigned char)c;
	while(s[i] != '\0')
	{
		if(s[i] == uc)
			return (char *)(s+i);
		i++;
	}
	if(uc == '\0')
		return (char *)(s+i);
	return NULL;
}
