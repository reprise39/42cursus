/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:50:31 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/06 19:25:33 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define BUFFER_SIZE 42

# include <fcntl.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>   // memset
# include <sys/time.h> // gettimeofday
# include <unistd.h>

# define SOLO_MONITOR_INTERVAL 200
# define THINK_INTERVAL 200
# define MONITOR_INTERVAL 200
# define IN_USLEEP_CHECK_INTERVAL 100

typedef struct s_thread_manage
{
	int				num_of_philos;
	pthread_t		*thread_id;
	pthread_mutex_t	*forks_mutex;
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
	t_thread_manage	thread_manage;
	t_condition		condition;
	t_philosopher	*philosophers;
	struct timeval	start_time;
	bool			is_dead;
	pthread_mutex_t	is_dead_mutex;
	int				fin_philo_num;
	pthread_mutex_t	fin_philo_num_mutex;
	pthread_mutex_t	is_print_mutex;
}					t_simulation;

// check_input.c
int					check_argc_num(int argc);
int					check_input_is_num(int argc, char **argv);
int					check_input_is_posi_int(int argc, char **argv);

// start_simulation.c
void				start_simulatuon(t_simulation *simulation, int argc,
						char **argv);

// end_simulation.c
void				end_simulation(t_simulation *simulation);

// wait_all_thread.c
void				wait_all_thread(t_simulation *simulation,
						pthread_t *monitor_thread_id);

// ft_is_int.c
int					ft_isdigit_str(const char *str);
int					ft_isposiint_str(const char *str);

// utils.c
int					ft_is_spase(char c);
int					ft_is_digit(const char str);
int					ft_strlen(const char *str);
void				ft_hyper_usleep(useconds_t timer);
int					ft_atoi(const char *str);

// print_info.c
void				print_take_fork(t_simulation *sim, int philo_num);
void				print_eat(t_simulation *sim, int philo_num);
void				print_sleep(t_simulation *sim, int philo_num);
void				print_think(t_simulation *sim, int philo_num);
void				print_die(t_simulation *sim, int philo_num);

// for_debag.c
void				print_condition(t_condition *condition);

// philosophers.c
int					philosophers(t_simulation *simulration);

// philo_behave_utils.c
int					set_left_fork(int i, t_simulation *sim);
int					set_first_fork(int philo_id, int right_fork, int left_fork);
int					set_last_fork(int philo_id, int right_fork, int left_fork);
bool				take_first_fork(t_simulation *sim,
						t_philosopher *philosopher, int first_fork);
bool				take_last_fork(t_simulation *sim,
						t_philosopher *philosopher, int first_fork,
						int last_fork);

// philo_behave_1.c
bool				take_forks(t_simulation *sim, t_philosopher *philosopher);
bool				eating(t_simulation *sim, t_philosopher *philosopher);

// philo_behave_2.c
bool				sleeping(t_simulation *sim, t_philosopher *philosopher);
bool				thinking(t_simulation *sim, t_philosopher *philosopher);
void				check_end_must_eat(t_simulation *sim, int num_of_eat);

// monitoring.c
void				*monitor_thread(void *arg);
bool				is_dead(t_simulation *sim);
void				is_dead_set(t_simulation *sim);

// cal_time.c
long				cal_mili_sec_time_now(struct timeval *start);
long				cal_mili_sec_time(struct timeval *start,
						struct timeval *end);
long				cal_miq_sec_time_now(struct timeval *start);
long				cal_miq_sec_time(struct timeval *start,
						struct timeval *end);
bool				usleep_with_check(long miq_sec, t_simulation *sim);

#endif