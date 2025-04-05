/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 03:01:09 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/06 05:47:45 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

char *getpath_from_env(char **envp)
{
	int i;
	i = 0;
	while(envp[i] != NULL)
	{
		if(ft_strncmp(envp[i],"PATH=",5) == 0)
			return(envp[i] + 5);
		i++;
	}
	return (NULL);
}

char *ft_strcat_threewords(char *dest,char *one,char *two ,char *three)
{
	char* ptr;
	ptr = dest;
	int i;
	i = 0;
	while(one[i] != '\0')
	{
		ptr[i] = one[i];
		i++;
	}
	ptr += i;
	i=0;
	while(two[i] != '\0')
	{
		ptr[i] = two[i];
		i++;
	}
	ptr += i;
	i=0;
	while(three[i] != '\0')
	{
		ptr[i] = three[i];
		i++;
	}
	ptr[i] = '\0';
	return (dest);
}

void free_ft_split(char **dest)
{
	size_t i;
	i = 0;
	while(dest[i] != NULL)
	{
		free(dest[i]);
		i++;
	}
	free(dest);
}
