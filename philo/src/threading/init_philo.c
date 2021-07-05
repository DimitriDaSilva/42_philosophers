/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:41:10 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/05 11:02:29 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_philo.h"

int	init_philo(t_philo *philo)
{
	if (pthread_mutex_init(&philo->write_lock, NULL) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (init_philo_mutex_init(philo) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (init_philo_create(philo) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (init_philo_join(philo) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (init_philo_mutex_destroy(philo) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (pthread_mutex_destroy(&philo->write_lock) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	init_philo_mutex_init(t_philo *philo)
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

int	init_philo_create(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->settings->nb_philo)
	{
		if (pthread_create(&philo->threads[i], NULL,
					&init_life, philo) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	init_philo_join(t_philo *philo)
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

int	init_philo_mutex_destroy(t_philo *philo)
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
