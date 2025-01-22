/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:36:38 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/22 18:58:58 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Static prototypes

static void	_philo_eat_take_rfork(
				t_philo *philo
				);

static void	_philo_eat_take_lfork(
				t_philo *philo
				);

static void	_philo_eat_take_forks(
				t_philo *philo
				);

// Header implementations

void	philo_eat(
	t_philo *philo
)
{
	_philo_eat_take_forks(philo);
	if (philo->r_fork == philo->l_fork)
	{
		while (philo_is_running(philo->ctx))
			usleep(50);
		pthread_mutex_unlock(philo->l_fork);
		return ;
	}
	pthread_mutex_lock(&philo->mutex_eating);
	philo_log(philo->ctx, philo->id, STATE_EATING);
	philo->last_time_eaten = ft_time_ms();
	pthread_mutex_unlock(&philo->mutex_eating);
	custom_sleep(philo, ((t_philo_ctx *)philo->ctx)->timers.eat);
	pthread_mutex_lock(&philo->mutex_eaten);
	++philo->times_eaten;
	pthread_mutex_unlock(&philo->mutex_eaten);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

// Static implementations

static void	_philo_eat_take_rfork(
	t_philo *philo
)
{
	pthread_mutex_lock(philo->r_fork);
	philo_log(philo->ctx, philo->id, STATE_FORK_TAKEN);
}

static void	_philo_eat_take_lfork(
	t_philo *philo
)
{
	pthread_mutex_lock(philo->l_fork);
	philo_log(philo->ctx, philo->id, STATE_FORK_TAKEN);
}

static void	_philo_eat_take_forks(
	t_philo *philo
)
{
	const int	odd = philo->id % 2;

	if (odd)
		_philo_eat_take_rfork(philo);
	_philo_eat_take_lfork(philo);
	if (!odd && philo->l_fork != philo->r_fork)
		_philo_eat_take_rfork(philo);
}
