/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 01:00:07 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/06 01:33:42 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_take_fork(t_simulation *sim, int philo_num)
{
	long			mili_sec;
	struct timeval	current_time;

	pthread_mutex_lock(&sim->is_print_mutex);
	gettimeofday(&current_time, NULL);
	mili_sec = cal_mili_sec_time(&sim->start_time, &current_time);
	printf("%ld_in_ms %d has taken a fork\n", mili_sec, philo_num);
	usleep(1000);
	pthread_mutex_unlock(&sim->is_print_mutex);
}

void	print_eat(t_simulation *sim, int philo_num)
{
	long			mili_sec;
	struct timeval	current_time;

	pthread_mutex_lock(&sim->is_print_mutex);
	gettimeofday(&current_time, NULL);
	mili_sec = cal_mili_sec_time(&sim->start_time, &current_time);
	printf("%ld_in_ms %d is eating\n", mili_sec, philo_num);
	usleep(1000);
	pthread_mutex_unlock(&sim->is_print_mutex);
}

void	print_sleep(t_simulation *sim, int philo_num)
{
	long			mili_sec;
	struct timeval	current_time;

	pthread_mutex_lock(&sim->is_print_mutex);
	gettimeofday(&current_time, NULL);
	mili_sec = cal_mili_sec_time(&sim->start_time, &current_time);
	printf("%ld_in_ms %d is sleeping\n", mili_sec, philo_num);
	usleep(1000);
	pthread_mutex_unlock(&sim->is_print_mutex);
}

void	print_think(t_simulation *sim, int philo_num)
{
	long			mili_sec;
	struct timeval	current_time;

	pthread_mutex_lock(&sim->is_print_mutex);
	gettimeofday(&current_time, NULL);
	mili_sec = cal_mili_sec_time(&sim->start_time, &current_time);
	printf("%ld_in_ms %d is thinking\n", mili_sec, philo_num);
	usleep(1000);
	pthread_mutex_unlock(&sim->is_print_mutex);
}

void	print_die(t_simulation *sim, int philo_num)
{
	long			mili_sec;
	struct timeval	current_time;

	pthread_mutex_lock(&sim->is_print_mutex);
	gettimeofday(&current_time, NULL);
	mili_sec = cal_mili_sec_time(&sim->start_time, &current_time);
	printf("%ld_in_ms %d died\n", mili_sec, philo_num);
	usleep(1000);
	pthread_mutex_unlock(&sim->is_print_mutex);
}
