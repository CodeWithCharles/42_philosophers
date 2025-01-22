/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:27:41 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/22 18:58:26 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Header implementations

noreturn
void	error(
	t_philo_ctx *ctx,
	const char *message
)
{
	printf("%s%s: %s%s\n", TERM_RED, ctx->program_name, message, TERM_RESET);
	philo_destroy(ctx);
	exit(RET_ERR);
}
