/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_sleep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 18:07:50 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/22 18:59:10 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Header implementations

void	custom_sleep(
	t_philo *philo,
	time_t duration
)
{
	time_t	now;

	now = ft_time_ms();
	while (now + duration > ft_time_ms())
	{
		if (!philo_is_running(philo->ctx))
			break ;
		usleep(((t_philo_ctx *)philo->ctx)->philo_count * 2);
	}
}
