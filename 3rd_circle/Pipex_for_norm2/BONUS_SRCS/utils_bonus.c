/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 03:01:09 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/09 05:05:15 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*getpath_from_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*ft_strcat_threewords(char *dest, char *one, char *two, char *three)
{
	char	*ptr;

	ptr = dest;
	while (*one)
		*ptr++ = *one++;
	while (*two)
		*ptr++ = *two++;
	while (*three)
		*ptr++ = *three++;
	*ptr = '\0';
	return (dest);
}

void	free_ft_split(char **dest)
{
	size_t	i;

	i = 0;
	while (dest[i] != NULL)
	{
		free(dest[i]);
		i++;
	}
	free(dest);
}

void	free_cmd_phrase(char ***cmd_phrase)
{
	int	i;

	i = 0;
	while (cmd_phrase[i] != NULL)
	{
		free_ft_split(cmd_phrase[i]);
		i++;
	}
	free(cmd_phrase);
}
