/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:47:34 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/01 18:42:06 by dda-silv         ###   ########.fr       */
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
	(void)philo;
}

int	init_philo(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->settings->nb_philo)
	{
		philo->index = i;
		if (pthread_create(&philo->threads[i], NULL, &init_life, philo) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		i++;
	}
	i = 0;
	while (i < philo->settings->nb_philo)
	{
		if (pthread_join(philo->threads[i], NULL) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

void	*init_life(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	printf("Philosopher %d is about to sleep %.1f seconds\n",
			philo->index, (float)(philo->settings->time_to_sleep / 1000));
	usleep(philo->settings->time_to_sleep);
	printf("Philosopher %d is done sleeping\n", philo->index);
	return (NULL);
}
