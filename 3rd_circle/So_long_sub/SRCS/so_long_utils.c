/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 20:54:50 by mkuida            #+#    #+#             */
/*   Updated: 2025/02/12 16:28:45 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_in_charptr(char *ch, const char *charset)
{
	const int	charsetsize = ft_strlen(charset);
	int			i;

	i = 0;
	while (i < charsetsize)
	{
		if (*ch == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_strchr_int(const char *s, int c)
{
	int				i;
	unsigned char	uc;

	if (s == NULL)
		return (0);
	i = 0;
	uc = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == uc)
			return (i);
		i++;
	}
	if (uc == '\0')
		return (i);
	return (0);
}

void	initialize_int_ptr_array(int **ptr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		*ptr[i] = 0;
		i++;
	}
}
