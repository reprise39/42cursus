/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 08:41:54 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/03 08:41:54 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int ft_is_spase(const char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int ft_is_digit(const char str)
{
	if (str == '\0')
		return (0);
	if('0' <= str && str <= '9')
		return (1);
	else
		return (0);
}

int	ft_strlen(const char *str)
{
	int len;

	len = 0;
	if(str == NULL)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

void ft_hyper_usleep(useconds_t timer)
{
	struct timeval	start;
	struct timeval	current;

	if (gettimeofday(&start,NULL) == -1 )
	{
		perror("gettimeofday");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		if (gettimeofday(&current, NULL) == -1)
		{
			perror("gettimeofday");
			exit(EXIT_FAILURE);
		}
		if ((current.tv_sec - start.tv_sec) * 1000000 + (current.tv_usec - start.tv_usec) >= timer)
			break ;
		usleep(100);
	}
}

int	ft_atoi(const char	*str)
{
	int i;
	int ans;

	i = 0;
	ans = 0;
	while (ft_is_spase(str[i]) == 1)
		i++;
	if (str[i] == '+')
		i++;
	while(str[i] != '\0')
	{
		ans *= 10;
		ans += (str[i] - '0');
		i++;
	}
	return (ans);
}
