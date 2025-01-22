/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ato.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:13:37 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/22 11:26:20 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

// Header implementation

int	ft_atot(
	const char *str,
	time_t *time_ptr
)
{
	time_t	_time;

	if (*str == '\0')
		return (0);
	_time = 0;
	while (is_digit(*str))
		_time = _time * 10 + (*str++ - '0');
	*time_ptr = _time;
	return (*str == '\0');
}

int	ft_atoui(
	const char *str,
	unsigned int *value_ptr
)
{
	unsigned int	_value;

	if (*str == '\0')
		return (0);
	_value = 0;
	while (is_digit(*str))
		_value = _value * 10 + (*str++ - '0');
	*value_ptr = _value;
	return (*str == '\0');
}
