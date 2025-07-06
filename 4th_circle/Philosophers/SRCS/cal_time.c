/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 12:47:32 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/06 19:29:42 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	cal_mili_sec_time_now(struct timeval *start)
{
	long			seconds;
	long			microseconds;
	long			total_sec;
	struct timeval	end;

	if (start->tv_sec == 0 && start->tv_usec == 0)
		return (0);
	gettimeofday(&end, NULL);
	seconds = end.tv_sec - start->tv_sec;
	microseconds = end.tv_usec - start->tv_usec;
	if (microseconds < 0)
	{
		seconds--;
		microseconds += 1000000;
	}
	total_sec = (seconds * 1000) + (microseconds / 1000);
	return (total_sec);
}

long	cal_mili_sec_time(struct timeval *start, struct timeval *end)
{
	long	seconds;
	long	microseconds;
	long	total_sec;

	seconds = end->tv_sec - start->tv_sec;
	microseconds = end->tv_usec - start->tv_usec;
	if (microseconds < 0)
	{
		seconds--;
		microseconds += 1000000;
	}
	total_sec = (seconds * 1000) + (microseconds / 1000);
	return (total_sec);
}

long	cal_miq_sec_time_now(struct timeval *start)
{
	long			seconds;
	long			microseconds;
	long			total_sec;
	struct timeval	end;

	if (start->tv_sec == 0 && start->tv_usec == 0)
		return (0);
	gettimeofday(&end, NULL);
	seconds = (end.tv_sec) - (start->tv_sec);
	microseconds = (end.tv_usec) - (start->tv_usec);
	if (microseconds < 0)
	{
		seconds--;
		microseconds += 1000000;
	}
	total_sec = (seconds * 1000000) + (microseconds);
	return (total_sec);
}

long	cal_miq_sec_time(struct timeval *start, struct timeval *end)
{
	long	seconds;
	long	microseconds;
	long	total_sec;

	seconds = (end->tv_sec) - (start->tv_sec);
	microseconds = (end->tv_usec) - (start->tv_usec);
	if (microseconds < 0)
	{
		seconds--;
		microseconds += 1000000;
	}
	total_sec = (seconds * 1000000) + (microseconds);
	return (total_sec);
}

bool	usleep_with_check(long miq_sec, t_simulation *sim)
{
	struct timeval	start;
	struct timeval	current;

	if (gettimeofday(&start, NULL) == -1)
	{
		perror("gettimeofday");
		exit(false);
	}
	while (1)
	{
		if (gettimeofday(&current, NULL) == -1)
		{
			perror("gettimeofday");
			exit(false);
		}
		if (cal_miq_sec_time(&start, &current) >= miq_sec)
			return (true);
		usleep(IN_USLEEP_CHECK_INTERVAL);
		if (is_dead(sim))
			return (false);
	}
	return (false);
}
