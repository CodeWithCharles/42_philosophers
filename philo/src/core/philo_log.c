/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_log.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:45:31 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/27 14:57:54 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Header implementations

void	philo_log(
	t_philo_ctx *ctx,
	int id,
	t_state state
)
{
	static const char		*messages[] = {
	[STATE_FORK_TAKEN] = "has taken a fork",
	[STATE_EATING] = "is eating",
	[STATE_SLEEPING] = "is sleeping",
	[STATE_THINKING] = "is thinking",
	[STATE_DIED] = "died",
	};
	static pthread_mutex_t	mut = PTHREAD_MUTEX_INITIALIZER;

	pthread_mutex_lock(&mut);
	if (philo_is_running(ctx) || state == STATE_DIED)
		printf("%8ld ms - Philo %d : %s\n",
			ft_time_ms(), id + 1, messages[state]);
	pthread_mutex_unlock(&mut);
}
