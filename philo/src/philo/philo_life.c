/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:14:54 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/22 18:57:16 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Header implementations

void	*philo_life(
	void *p
)
{
	t_philo *const		philo = p;
	t_philo_ctx *const	ctx = philo->ctx;

	if (philo->id % 2)
		custom_sleep(philo, 4);
	while (philo_is_running(ctx))
	{
		philo_eat(philo);
		if (!philo_is_running(philo->ctx))
			break ;
		philo_log(ctx, philo->id, STATE_SLEEPING);
		custom_sleep(philo, ctx->timers.sleep);
		philo_log(ctx, philo->id, STATE_THINKING);
	}
	return (NULL);
}
