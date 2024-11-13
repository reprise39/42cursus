/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:10:34 by mkuida            #+#    #+#             */
/*   Updated: 2024/11/12 20:56:00 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

int ft_isinit(char c,char const* str)
{
	size_t i;
	size_t str_len;

	i = 0;
	str_len = ft_strlen(str);
	while(i < str_len)
	{
		if(c == str[i])
			return 1;
		i++;
	}
	return 0;
}
char *ft_strtrim(char const *s1, char const *set)
{
	size_t start;
	size_t end;
	size_t s1_len;
	char *dest;

	start = 0;
	end = 0;
	s1_len = ft_strlen(s1);
	while(ft_isinit(s1[start],set) == 1)
		start++;
	while(ft_isinit(s1[s1_len -1 -end],set) == 1)
		end++;
	if(start+end >= s1_len)
		return ("");
	dest = ft_substr(s1,start,s1_len-start-end);
	return dest;
}
