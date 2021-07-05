/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_wrapper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:41:10 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/05 18:06:21 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pthread_wrapper.h"

int	init_simul(t_simul *philo)
{
	if (pthread_mutex_init(&philo->increment_lock, NULL) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&philo->death_lock, NULL) != EXIT_SUCCESS)
		   return (EXIT_FAILURE);
	if (pthread_mutex_init(&philo->meals_left_lock, NULL) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (init_simul_mutex_init(philo) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (init_simul_create(philo) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (init_simul_join(philo) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (init_simul_mutex_destroy(philo) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (pthread_mutex_destroy(&philo->increment_lock) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (pthread_mutex_destroy(&philo->death_lock) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (pthread_mutex_destroy(&philo->meals_left_lock) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	init_simul_mutex_init(t_simul *philo)
{
	int	i;

	i = -1;
	while (++i < philo->settings->nb_philo)
	{
		if (pthread_mutex_init(&philo->forks[i], NULL) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	init_simul_create(t_simul *philo)
{
	int	i;

	i = -1;
	while (++i < philo->settings->nb_philo)
	{
		if (pthread_create(&philo->threads[i], NULL,
				&start_living, philo) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	init_simul_join(t_simul *philo)
{
	int	i;

	i = -1;
	while (++i < philo->settings->nb_philo)
	{
		if (pthread_join(philo->threads[i], NULL) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	init_simul_mutex_destroy(t_simul *philo)
{
	int	i;

	i = -1;
	while (++i < philo->settings->nb_philo)
	{
		if (pthread_mutex_destroy(&philo->forks[i]) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
