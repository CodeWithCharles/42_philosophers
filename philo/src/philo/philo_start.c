/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_start.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:33:08 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/22 18:59:04 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Static prototypes

static void	_philo_wait_thread(
				t_philo_ctx *ctx
				);

static void	_philo_check_each(
				t_philo_ctx *ctx
				);

static void	_philo_died(
				t_philo_ctx *ctx
				);

// Header implementations

void	philo_start(
	t_philo_ctx *ctx
)
{
	size_t	i;

	philo_set_running(ctx, true);
	i = 0;
	while (i < ctx->philo_count)
	{
		ctx->philos[i].last_time_eaten = ft_time_ms();
		if (pthread_create(&ctx->philos[i].thread_id, NULL,
				philo_life, &ctx->philos[i]))
		{
			philo_set_running(ctx, false);
			_philo_wait_thread(ctx);
			error(ctx, ERR_THREAD_INIT);
		}
		usleep(500);
		++i;
	}
	_philo_died(ctx);
	_philo_wait_thread(ctx);
}

// Static implementations

static void	_philo_wait_thread(
	t_philo_ctx *ctx
)
{
	size_t	i;

	i = 0;
	while (i < ctx->philo_count)
	{
		if (ctx->philos[i].thread_id != 0)
			pthread_join(ctx->philos[i].thread_id, NULL);
		++i;
	}
}

static void	_philo_check_each(
	t_philo_ctx *ctx
)
{
	size_t			i;
	unsigned int	times_eaten;

	i = 0;
	while (i < ctx->philo_count && ctx->timers.each != INT_MAX)
	{
		pthread_mutex_lock(&ctx->philos[i].mutex_eaten);
		times_eaten = ctx->philos[i].times_eaten;
		pthread_mutex_unlock(&ctx->philos[i].mutex_eaten);
		if (times_eaten < (unsigned int)ctx->timers.each)
			break ;
		++i;
	}
	if (i == ctx->philo_count)
		philo_set_running(ctx, false);
}

static void	_philo_died(
	t_philo_ctx *ctx
)
{
	size_t	i;
	time_t	time_since_eaten;

	while (philo_is_running(ctx))
	{
		i = 0;
		while (i < ctx->philo_count)
		{
			pthread_mutex_lock(&ctx->philos[i].mutex_eating);
			time_since_eaten = ft_time_ms() - ctx->philos[i].last_time_eaten;
			if (time_since_eaten >= ctx->timers.death)
			{
				philo_set_running(ctx, false);
				philo_log(ctx, i, STATE_DIED);
				pthread_mutex_unlock(&ctx->philos[i].mutex_eating);
			}
			pthread_mutex_unlock(&ctx->philos[i].mutex_eating);
			++i;
		}
		_philo_check_each(ctx);
	}
}
