/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_run_state.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:12:38 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/22 18:58:52 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Header implementations

bool	philo_is_running(
	t_philo_ctx *ctx
)
{
	bool	is_running;

	pthread_mutex_lock(&ctx->mutex_is_running);
	is_running = ctx->is_running;
	pthread_mutex_unlock(&ctx->mutex_is_running);
	return (is_running);
}

void	philo_set_running(
	t_philo_ctx *ctx,
	bool running
)
{
	pthread_mutex_lock(&ctx->mutex_is_running);
	ctx->is_running = running;
	pthread_mutex_unlock(&ctx->mutex_is_running);
}
