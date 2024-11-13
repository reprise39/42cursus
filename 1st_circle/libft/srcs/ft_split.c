/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:57:06 by mkuida            #+#    #+#             */
/*   Updated: 2024/11/13 15:54:33 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

void free_dest(char **dest,size_t num)
{
	size_t i;

	i = 0;
	while(i <= num)
	{
		free(dest[i]);
	}
}

int dests_pad(char **dest,const char *src,char c)
{
	size_t len;
	size_t count;
	char *target;

	target = (char *)dest;
	count = 0;
	while(*target !='\0')
	{
		while(*target == c)
			target++;
		if(*target != '\0')
		{
			len = 0;
			while(target[len] != c && target[len] != '\0')
				len++;
			dest[count] = ft_strndup(target,len);
			if(dest[count]==NULL)
			{
				free_dest(dest,count);
				return NULL;
			}
			count++;
			target += len;
		} 
	}
	return count;
}

size_t	count_words(const char *src, char c)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	while(src[i]!='\0')
	{
		while(src[i] == c)
			i++;
		if(src[i] != '\0')
		{
			count++;
			while(src[i] != c && src[i] != '\0')
			i++;
		}
	}
	return count;
}

char **ft_split(char const *s, char c)
{
	size_t words;
	char **dest;
	words = count_words(s,c);
	dest = malloc((words+1) * sizeof(char *));
	if(dest == NULL)
		return NULL;
	if(dests_pad(dest,s,c) == 0)
	{
		free(dest);
		return NULL;
	}
	dest[words] = NULL;
	return dest;
}

