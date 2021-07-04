/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:47:34 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/04 14:53:06 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int argc, char *argv[])
{
	t_philo *philo;

	if (has_invalid_args(argc, argv))
	{
		printf("Error: invalid arguments\n");
		return (1);
	}
	// init_struct
	philo = get_philo(argc, argv);
	if (!philo)
		return (2);
	if (init_philo(philo) != EXIT_SUCCESS)
		return (3);

	// join all thread
	printf("Finished\n");
	free_memory(philo);
	return (EXIT_SUCCESS);
}

void	free_memory(t_philo *philo)
{
	free(philo->threads);
	free(philo->forks);
	free(philo->settings);
	free(philo);
}
