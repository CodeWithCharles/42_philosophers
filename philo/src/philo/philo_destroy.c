/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:18:07 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/22 18:58:50 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Header implementations

void	philo_destroy(
	t_philo_ctx *ctx
)
{
	size_t	i;

	pthread_mutex_destroy(&ctx->mutex_is_running);
	if (ctx->forks == NULL)
		return ;
	i = 0;
	while (i < ctx->philo_count)
		pthread_mutex_destroy(&ctx->forks[i++]);
	free(ctx->forks);
	if (ctx->philos == NULL)
		return ;
	i = 0;
	while (i < ctx->philo_count)
	{
		pthread_mutex_destroy(&ctx->philos[i].mutex_eating);
		pthread_mutex_destroy(&ctx->philos[i].mutex_eaten);
		++i;
	}
	free(ctx->philos);
}
