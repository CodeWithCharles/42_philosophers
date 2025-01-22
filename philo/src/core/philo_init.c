/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:09:39 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/22 12:04:02 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

// Static prototypes

static void	_philo_init_philos(
				t_philo_ctx	*ctx
				);

static void	_philo_init_forks(
				t_philo_ctx *ctx
				);

// Header implementations

void	philo_init_args(
	t_philo_ctx *ctx,
	int argc,
	char **argv
)
{
	ctx->program_name = argv[PROG_NAME];
	ctx->philos = NULL;
	ctx->is_running = false;
	ctx->forks = NULL;
	if (!ft_atoui(argv[PROG_PHILO_COUNT], &ctx->philo_count))
		error(ctx, ARG1 " " ERR_NAT_INT);
	if (!ft_atot(argv[PROG_DEATH_TIMER], &ctx->timers.death))
		error(ctx, ARG2 " " ERR_NAT_INT);
	if (!ft_atot(argv[PROG_EAT_TIMER], &ctx->timers.eat))
		error(ctx, ARG3 " " ERR_NAT_INT);
	if (!ft_atot(argv[PROG_SLEEP_TIMER], &ctx->timers.sleep))
		error(ctx, ARG4 " " ERR_NAT_INT);
	if (argc == PROG__MAX
		&& !ft_atoui(argv[PROG_EACHP_TIMER], &ctx->timers.each))
		error(ctx, ARG5 " " ERR_NAT_INT);
	if (argc != PROG__MAX)
		*each_ptr = INT_MAX;
	if (ctx->philo_count == 0)
		error(ctx, ARG1 " " ERR_NULL);
	if (pthread_mutex_init(&ctx->mutex_is_running, NULL))
		error(ctx, ERR_MUTEX);
}

void	philo_init(
	t_philo_ctx *ctx
)
{
	ctx->forks = malloc(sizeof(*ctx->forks) * ctx->philo_count);
	if (ctx->forks == NULL)
		error(ctx, ERR_ALLOC);
	_philo_init_forks(ctx);
	ctx->philos = malloc(sizeof(*ctx->philos) * ctx->philo_count);
	if (ctx->philos == NULL)
		error(ctx, ERR_ALLOC);
	_philo_init_philos(ctx);
}

// Static implementations

static void	_philo_init_philos(
	t_philo_ctx *ctx
)
{
	size_t	i;

	i = 0;
	while (i < ctx->philo_count)
	{
		ctx->philos[i].r_fork = &ctx->forks[(i + 1) % ctx->philo_count];
		ctx->philos[i].l_fork = &ctx->forks[i];
		ctx->philos[i].id = i;
		ctx->philos[i].last_time_eaten = 0;
		ctx->philos[i].times_eaten = 0;
		ctx->philos[i].ctx = ctx;
		ctx->philos[i].thread_id = 0;
		if (pthread_mutex_init(&ctx->philos[i].mutex_eating, NULL)
			|| pthread_mutex_init(&ctx->philos[i].mutex_eaten, NULL))
			error(ctx, ERR_MUTEX);
		ctx->philos[i++].is_dead = 0;
	}
}

static void	_philo_init_forks(
	t_philo_ctx *ctx
)
{
	size_t	i;

	i = 0;
	while (i < ctx->philo_count)
		if (pthread_mutex_init(&ctx->forks[i++], NULL))
			break ;
	if (i == ctx->philo_count)
		return ;
	while (i--)
		pthread_mutex_destroy(&ctx->forks[i]);
}
