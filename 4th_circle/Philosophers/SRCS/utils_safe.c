/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_safe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 19:34:53 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/06 19:34:53 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	gettimeofday_s(struct timeval *tv, struct timezone *tz)
{
	if (gettimeofday(tv,tz) != 0)
	{
		printf ("gettimeofday error");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	pthread_mutex_lock_s(pthread_mutex_t *mutex)
{
	if (pthread_mutex_lock(mutex) != 0)
	{
		printf ("pthread_mutex_lock error");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	pthread_mutex_unlock_s(pthread_mutex_t *mutex)
{
	if (pthread_mutex_unlock(mutex) != 0)
	{
		printf ("pthread_mutex_unlock error");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	pthread_mutex_destroy_s(pthread_mutex_t *mutex)
{
	if (pthread_mutex_destroy(mutex) != 0)
	{
		printf ("pthread_mutex_destory error");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
