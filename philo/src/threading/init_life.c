/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_life.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:58:13 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/03 16:50:17 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_life.h"

void	*init_life(void *arg)
{
	t_philo *philo;
	int		index;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->write_lock);
	index = philo->index++;
	pthread_mutex_unlock(&philo->write_lock);
	if (start_eating(philo, index) != EXIT_SUCCESS)
		return (NULL);
	if (start_sleeping(philo, index) != EXIT_SUCCESS)
		return (NULL);
	if (start_thinking(philo, index) != EXIT_SUCCESS)
		return (NULL);
	return (NULL);
}

int start_eating(t_philo *philo, int index)
{
	if (index % 2 != 0)
	{
		take_fork(philo, index, index);
   		take_fork(philo, index, (index + 1) % philo->settings->nb_philo);
	}
	else
	{
		take_fork(philo, index, (index + 1) % philo->settings->nb_philo);
		take_fork(philo, index, index);
	}
	if (print_status(philo, index + 1, "is eating") != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	usleep(philo->settings->time_to_eat);
	release_fork(philo, index);
	release_fork(philo, (index + 1) % philo->settings->nb_philo);
	return (EXIT_SUCCESS);
}

int take_fork(t_philo *philo, int philo_index, int fork_index)
{
	if (pthread_mutex_lock(&philo->forks[fork_index]) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (print_status_fork(philo, philo_index + 1, "has taken a fork", fork_index) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int release_fork(t_philo *philo, int fork_index)
{
	if (pthread_mutex_unlock(&philo->forks[fork_index]) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int start_sleeping(t_philo *philo, int index)
{
	if (print_status(philo, index + 1, "is sleeping") != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	usleep(philo->settings->time_to_sleep);
	return (EXIT_SUCCESS);
}

int start_thinking(t_philo *philo, int index)
{
	if (print_status(philo, index + 1, "is thinking") != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
