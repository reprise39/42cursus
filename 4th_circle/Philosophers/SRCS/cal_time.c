/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 12:47:32 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/05 12:47:32 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosophers.h"

long cal_mili_sec_time(struct timeval *start, struct timeval *end)
{
	long seconds;
	long microseconds;
	long total_sec;

	seconds = end->tv_sec - start->tv_sec;
	microseconds = end->tv_usec - start->tv_usec;

	// マイクロ秒が負の場合は、秒から1を引いて1000000を加算
	if (microseconds < 0)
	{
		seconds--;
		microseconds += 1000000;
	}

	total_sec = (seconds * 1000) + (microseconds / 1000);
	
	// // デバッグ用出力（後で削除）
	// printf("DEBUG: start=%ld.%06ld, end=%ld.%06ld, diff=%ldms\n", 
	// 	   start->tv_sec, start->tv_usec, 
	// 	   end->tv_sec, end->tv_usec, 
	// 	   total_msec);
	
	return (total_sec);
}

long cal_miq_sec_time(struct timeval *start, struct timeval *end)
{
	long seconds;
	long microseconds;
	long total_sec;

	seconds = end->tv_sec - start->tv_sec;
	microseconds = end->tv_usec - start->tv_usec;
	if (microseconds < 0)
	{
		seconds--;
		microseconds += 1000000;
	}

	total_sec = (seconds * 1000000) + (microseconds);
	return (total_sec);
}

bool usleep_with_check(long miq_sec ,t_simulation *sim)
{
	struct timeval start;
	struct timeval current;

	if (gettimeofday(&start, NULL) == -1)
	{
		perror("gettimeofday");
		exit (false);
	}
	while (1)
	{
		if (gettimeofday(&current, NULL) == -1)
		{
			perror("gettimeofday");
			exit (false);
		}
		if (cal_miq_sec_time(&start,&current) >= miq_sec)
			return (true);
		usleep(IN_USLEEP_CHECK_INTERVAL); // 100マイクロ秒ごとにチェック
		if (is_dead(sim))
			return (false);
	}
	return (false);
}
