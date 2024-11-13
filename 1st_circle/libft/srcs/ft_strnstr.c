/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 02:46:33 by mkuida            #+#    #+#             */
/*   Updated: 2024/11/13 18:25:19 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t little_size;
	size_t big_size;
	size_t compare_size;
	
	i = 0;
	little_size = ft_strlen(little);
	if(little_size == 0) return (char *)(big);
	if(little_size > len) return NULL;
	if(big_size < len)
		compare_size = big_size - little_size;
	else
		compare_size = len - little_size;
	while(i <= compare_size)
	{
		if(ft_strncmp((&big[i]),little,little_size)==0)
			return (char *)(big+i);
		i++;
	}
	return NULL;
}
