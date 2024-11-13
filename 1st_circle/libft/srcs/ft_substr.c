/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:16:53 by mkuida            #+#    #+#             */
/*   Updated: 2024/11/12 18:50:41 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start,size_t len)
{
	size_t s_size;
	size_t i;
	char *dest;

	s_size = strlen(s);
	i = 0;
	if(s_size == 0)
		return NULL;
	if(start > s_size || len == 0)
		return NULL;
	if(start + len > s_size)
		len =s_size-start;
	dest = malloc((len + 1) * sizeof(char));
	if(dest ==NULL)
		return NULL;
	while(i < len)
	{
		dest[i] = s[start+i];
		i++;
	}
	dest[len] = '\0';
	return dest;
}
