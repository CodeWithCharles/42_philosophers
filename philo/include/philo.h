/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:25:07 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/21 17:31:16 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// Defines

# define ERR_ALLOC 1

# define ARG1 "number_of_philosophers"
# define ARG2 "time_to_die"
# define ARG3 "time_to_eat"
# define ARG4 "time_to_sleep"
# define ARG5 "number_of_times_each_philosopher_must_eat"

// Enums

enum e_args
{
	PROG_NAME,
	PROG_PHILO_COUNT,
	PROG_DEATH_TIMER,
	PROG_EAT_TIMER,
	PROG_SLEEP_TIMER,
	PROG_EACHP_TIMER,
	PROG__MIN=PROG_SLEEP_TIMER + 1,
	PROG__MAX=PROG_EACHP_TIMER + 1,
};

enum e_state
{
	STATE_FORK_TAKEN,
	STATE_EATING,
	STATE_SLEEPING,
	STATE_THINKING,
	STATE_DIED,
};

// Structures

struct s_philo
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
};

#endif
