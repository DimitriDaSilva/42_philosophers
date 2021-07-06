/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_wrapper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:41:10 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/06 12:08:38 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pthread_wrapper.h"

int	init_simul(t_simul *simul)
{
	if (init_simul_mutex_init(simul) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (init_simul_create(simul) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (init_simul_join(simul) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (init_simul_mutex_destroy(simul) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	init_simul_mutex_init(t_simul *simul)
{
	int	i;

	if (pthread_mutex_init(&simul->increment_lock, NULL) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&simul->death_lock, NULL) != EXIT_SUCCESS)
		   return (EXIT_FAILURE);
	if (pthread_mutex_init(&simul->meals_left_lock, NULL) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	i = 0;
	while (i < simul->settings->nb_philo)
	{
		if (pthread_mutex_init(&simul->forks[i], NULL) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	init_simul_create(t_simul *simul)
{
	int	i;

	i = 0;
	while (i < simul->settings->nb_philo)
	{
		if (pthread_create(&simul->threads[i],
				NULL,
				&start_living,
				simul) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	init_simul_join(t_simul *simul)
{
	int	i;

	i = 0;
	while (i < simul->settings->nb_philo)
	{
		if (pthread_join(simul->threads[i], NULL) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	init_simul_mutex_destroy(t_simul *simul)
{
	int	i;

	if (pthread_mutex_destroy(&simul->increment_lock) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (pthread_mutex_destroy(&simul->death_lock) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (pthread_mutex_destroy(&simul->meals_left_lock) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	i = 0;
	while (i < simul->settings->nb_philo)
	{
		if (pthread_mutex_destroy(&simul->forks[i]) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
