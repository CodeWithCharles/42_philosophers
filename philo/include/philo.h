/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:25:07 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/22 11:50:02 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// Libs

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdnoreturn.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

// Defines

# define RET_ERR_ALLOC	1

# define RET_OK			0
# define RET_ERR		1

# define ARG1 "number_of_philosophers"
# define ARG2 "time_to_die"
# define ARG3 "time_to_eat"
# define ARG4 "time_to_sleep"
# define ARG5 "number_of_times_each_philosopher_must_eat"

# define ERR_NAT_INT	"must be a natural integer"
# define ERR_NULL		"cannot be null"
# define ERR_MUTEX		"mutex initialization error"
# define ERR_ALLOC		"Bad allocation"

# define TERM_RED					"\033[31m"
# define TERM_RESET					"\033[0m"

// Enums

typedef enum e_args
{
	PROG_NAME,
	PROG_PHILO_COUNT,
	PROG_DEATH_TIMER,
	PROG_EAT_TIMER,
	PROG_SLEEP_TIMER,
	PROG_EACHP_TIMER,
	PROG__MIN=PROG_SLEEP_TIMER + 1,
	PROG__MAX=PROG_EACHP_TIMER + 1,
}	t_args;

typedef enum e_state
{
	STATE_FORK_TAKEN,
	STATE_EATING,
	STATE_SLEEPING,
	STATE_THINKING,
	STATE_DIED,
}	t_state;

// Structures

typedef struct s_philo
{
	pthread_t		thread_id;
	int				id;
	bool			is_dead;
	unsigned int	times_eaten;
	time_t			last_time_eaten;
	pthread_mutex_t	mutex_eating;
	pthread_mutex_t	mutex_eaten;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
}	t_philo;

typedef struct s_philo_ctx
{
	char			*program_name;
	unsigned int	philo_count;
	bool			is_running;
	pthread_mutex_t	mutex_is_running;
	struct s_timers
	{
		time_t		death;
		time_t		eat;
		time_t		sleep;
	}				timers;
	t_philo			*philos;
	pthread_mutex_t	*forks;
}	t_philo_ctx;

// Function prototypes

//	Core

//	Philo (All philosophers related functions {life cycle}, except init)

//	Utils

//		ft_ato

int		ft_atot(
			const char *str,
			time_t *time_ptr
			);

int		ft_atoui(
			const char *str,
			time_t *time_ptr
			);

//		ft_time

time_t	ft_time_ms(void);

//		is

int		is_digit(
			char c
			);

#endif
