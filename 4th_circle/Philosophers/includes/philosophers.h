/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:50:31 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/05 20:35:40 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define BUFFER_SIZE 42

# include <sys/time.h> // gettimeofday
# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h> // memset
# include <unistd.h>
# include <stdbool.h>
# include <pthread.h>

# define THINK_INTERVAL 200
# define MONITOR_INTERVAL 200
# define IN_USLEEP_CHECK_INTERVAL 75

typedef struct s_thread_manage
{
	int				num_of_philos;
	pthread_t		*thread_id;
	pthread_mutex_t	*forks_mutex;
	int				left_forks;
	pthread_mutex_t	left_forks_mutex;
}					t_thread_manage;

typedef struct s_condition
{
	int				num_of_philos;
	suseconds_t		time_to_die;
	suseconds_t		time_to_eat;
	suseconds_t		time_to_sleep;
	int				num_of_eat_times;
	bool			optional_eat_times_flag;
}					t_condition;

typedef struct s_philosopher
{
	int				id;
	int				num_of_eat_times;
	struct timeval	last_eat_time;
	pthread_mutex_t	last_eat_time_mutex;
}					t_philosopher;

typedef struct s_simulation
{
	t_thread_manage	thread_manage;	// スレッド管理構造体
	t_condition		condition;		// 条件構造体
	t_philosopher	*philosophers;	// 哲学者の配列
	struct timeval	start_time;	// シミュレーション開始時間
	bool			is_dead;	// シミュレーションの実行状態
	pthread_mutex_t	is_dead_mutex;	// 死亡状態の保護用ミューテックス
}					t_simulation;

// check_input.c
int					check_argc_num(int argc);
int					check_input_is_num(int argc, char **argv);
int					check_input_is_posi_int(int argc, char **argv);

// start_simulation.c
void start_simulatuon(t_simulation *simulation, int argc, char **argv);

// end_simulation.c
void				end_simulation(t_simulation *simulation);

// wait_all_thread.c
void				wait_all_thread(t_simulation *simulation, pthread_t *monitor_thread_id);

// ft_is_int.c
int					ft_isdigit_str(const char *str);
int					ft_isposiint_str(const char *str);

// utils.c
int					ft_is_spase(char c);
int					ft_is_digit(const char str);
int					ft_strlen(const char *str);
void				ft_hyper_usleep(useconds_t timer);
int 				ft_atoi(const char *str);

// for_debag.c
void				print_condition(t_condition *condition);

// philosophers.c
int					philosophers(t_simulation *simulration);

//philo_behave.c
bool take_forks(t_simulation *sim, t_philosopher *philosopher);
bool eating(t_simulation *sim, t_philosopher *philosopher);
bool sleeping(t_simulation *sim, t_philosopher *philosopher);
bool thinking(t_simulation *sim, t_philosopher *philosopher);

//monitoring.c
void *monitor_thread(void *arg);
bool is_dead(t_simulation *sim);

// cal_time.c
long cal_mili_sec_time(struct timeval *start, struct timeval *end);
long cal_miq_sec_time(struct timeval *start, struct timeval *end);
bool usleep_with_check(long miq_sec ,t_simulation *sim);

#endif