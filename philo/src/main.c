/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:53:58 by cpoulain          #+#    #+#             */
/*   Updated: 2025/01/22 11:02:39 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

// Static prototypes

noreturn static void	help(void);

// Main function

int	main(
	int argc,
	char **argv
)
{
	t_philo_ctx	ctx;

	if (argc < PROG__MIN || argc > PROG__MAX)
		help();
	philo_init_args(&ctx, argc, argv);
	philo_init(&ctx);
	ft_time_ms();
	philo_start(&ctx);
	philo_destroy(&ctx);
	return (RET_OK);
}

// Static implementations

noreturn
static void	help(void)
{
	printf("Usage: ./philo " ARG1 " " ARG2 " " ARG3 " " ARG4 " [" ARG5 "]\n");
	exit(RET_OK);
}
