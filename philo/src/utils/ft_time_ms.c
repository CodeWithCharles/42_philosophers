/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_ms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:25:29 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/22 11:26:05 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

// Static prototypes

static time_t	_get_current_time(void);

// Header implementations

time_t	ft_time_ms(void)
{
	static time_t	_initial_time = -1;
	const time_t	current_time = _get_current_time();

	if (_initial_time == -1)
		_initial_time = current_time;
	return (current_time - _initial_time);
}

// Static implementations

static time_t	_get_current_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}
