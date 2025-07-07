/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 01:00:07 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/07 21:24:07 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_take_fork(t_simulation *sim, int philo_num)
{
	char	buf[PRINT_BUFF_SIZE];
	int		len;
	long	mili_sec;

	len = 0;
	memset(&buf, '\0', PRINT_BUFF_SIZE);
	pthread_mutex_lock(&sim->is_print_mutex);
	mili_sec = cal_mili_sec_time_now(&sim->start_time);
	len += ft_set_ltoa(mili_sec, &buf[0]);
	ft_memcpy(&buf[len], "_in_ms ", 7);
	len += 7;
	len += ft_set_ltoa((long)philo_num, &buf[len]);
	ft_memcpy(&buf[len], " has taken a fork\n", 18);
	len += 18;
	write(STDOUT_FILENO, &buf, len);
	usleep(1000);
	pthread_mutex_unlock(&sim->is_print_mutex);
}

void	print_eat(t_simulation *sim, int philo_num)
{
	char	buf[PRINT_BUFF_SIZE];
	int		len;
	long	mili_sec;

	len = 0;
	memset(&buf, '\0', PRINT_BUFF_SIZE);
	pthread_mutex_lock(&sim->is_print_mutex);
	mili_sec = cal_mili_sec_time_now(&sim->start_time);
	len += ft_set_ltoa(mili_sec, &buf[0]);
	ft_memcpy(&buf[len], "_in_ms ", 7);
	len += 7;
	len += ft_set_ltoa((long)philo_num, &buf[len]);
	ft_memcpy(&buf[len], " is eating\n", 11);
	len += 11;
	write(STDOUT_FILENO, &buf, len);
	usleep(1000);
	pthread_mutex_unlock(&sim->is_print_mutex);
}

void	print_sleep(t_simulation *sim, int philo_num)
{
	char	buf[PRINT_BUFF_SIZE];
	int		len;
	long	mili_sec;

	len = 0;
	memset(&buf, '\0', PRINT_BUFF_SIZE);
	pthread_mutex_lock(&sim->is_print_mutex);
	mili_sec = cal_mili_sec_time_now(&sim->start_time);
	len += ft_set_ltoa(mili_sec, &buf[0]);
	ft_memcpy(&buf[len], "_in_ms ", 7);
	len += 7;
	len += ft_set_ltoa((long)philo_num, &buf[len]);
	ft_memcpy(&buf[len], " is sleeping\n", 13);
	len += 13;
	write(STDOUT_FILENO, &buf, len);
	usleep(1000);
	pthread_mutex_unlock(&sim->is_print_mutex);
}

void	print_think(t_simulation *sim, int philo_num)
{
	char	buf[PRINT_BUFF_SIZE];
	int		len;
	long	mili_sec;

	len = 0;
	memset(&buf, '\0', PRINT_BUFF_SIZE);
	pthread_mutex_lock(&sim->is_print_mutex);
	mili_sec = cal_mili_sec_time_now(&sim->start_time);
	len += ft_set_ltoa(mili_sec, &buf[0]);
	ft_memcpy(&buf[len], "_in_ms ", 7);
	len += 7;
	len += ft_set_ltoa((long)philo_num, &buf[len]);
	ft_memcpy(&buf[len], " is thinking\n", 13);
	len += 13;
	write(STDOUT_FILENO, &buf, len);
	usleep(1000);
	pthread_mutex_unlock(&sim->is_print_mutex);
}

void	print_die(t_simulation *sim, int philo_num)
{
	char	buf[PRINT_BUFF_SIZE];
	int		len;
	long	mili_sec;

	len = 0;
	memset(&buf, '\0', PRINT_BUFF_SIZE);
	pthread_mutex_lock(&sim->is_print_mutex);
	mili_sec = cal_mili_sec_time_now(&sim->start_time);
	len += ft_set_ltoa(mili_sec, &buf[0]);
	ft_memcpy(&buf[len], "_in_ms ", 7);
	len += 7;
	len += ft_set_ltoa((long)philo_num, &buf[len]);
	ft_memcpy(&buf[len], " died\n", 6);
	len += 6;
	write(STDOUT_FILENO, &buf, len);
	usleep(1000);
	pthread_mutex_unlock(&sim->is_print_mutex);
}
