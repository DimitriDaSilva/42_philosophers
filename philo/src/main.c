/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:47:34 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/05 14:50:59 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char *argv[])
{
	t_philo	*philo;

	if (has_invalid_args(argc, argv))
	{
		printf("Error: invalid arguments\n");
		return (1);
	}
	philo = get_philo(argc, argv);
	if (!philo)
	{
		printf("Error: could not get philo\n");
		return (2);
	}
	if (init_philo(philo) != EXIT_SUCCESS)
	{
		printf("Error: pthread function returned exit_failure\n");
		return (3);
	}
	free_memory(philo);
	return (EXIT_SUCCESS);
}
