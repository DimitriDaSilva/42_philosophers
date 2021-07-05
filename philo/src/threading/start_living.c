/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_living.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:26:04 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/05 17:48:47 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "start_living.h"

void	*start_living(void *arg)
{
	static int		i = 0;
	t_simul			*philo;
	t_single_philo	*single_philo;

	philo = (t_simul *)arg;
	pthread_mutex_lock(&philo->write_lock);
	single_philo = &philo->philos[i++];
	pthread_mutex_unlock(&philo->write_lock);
	while (1)
	{
		if (start_taking_forks(philo, single_philo) != EXIT_SUCCESS)
			break ;
		if (start_eating(philo, single_philo) != EXIT_SUCCESS)
			break ;
		if (start_sleeping(philo, single_philo) != EXIT_SUCCESS)
			break ;
		if (start_thinking(philo, single_philo) != EXIT_SUCCESS)
			break ;
	}
	return (NULL);
}

int	start_taking_forks(t_simul *philo, t_single_philo *single_philo)
{
	int				index;
	struct timeval	*last_meal;
	int				time_before_death;
	int				second_fork_index;

	index = single_philo->index;
	last_meal = &single_philo->last_meal;
	if (last_meal->tv_usec != 0)
	{
		time_before_death = get_time_before_death(philo, last_meal);
		if (philo->settings->time_to_eat * 2 > time_before_death + philo->settings->time_to_die)
		{
			usleep(time_before_death * 1000);
			if (print_status(philo, index + 1, "died") != EXIT_SUCCESS)
				return (EXIT_FAILURE);
			pthread_mutex_lock(&philo->write_lock);
			philo->has_a_philo_died = 1;
			pthread_mutex_unlock(&philo->write_lock);
			return (EXIT_FAILURE);
		}
	}
	second_fork_index = (index + 1) % philo->settings->nb_philo;
	if (index % 2 != 0)
	{
		if (take_fork(philo, index, index) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		if (take_fork(philo, index, second_fork_index) != EXIT_SUCCESS)
		{
			release_fork(philo, index);
			return (EXIT_FAILURE);
		}
	}
	else
	{
		if (take_fork(philo, index, second_fork_index) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		if (take_fork(philo, index, index) != EXIT_SUCCESS)
		{
			release_fork(philo, second_fork_index);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	start_eating(t_simul *philo, t_single_philo *single_philo)
{
	int				index;
	struct timeval	*last_meal;

	index = single_philo->index;
	last_meal = &single_philo->last_meal;
	gettimeofday(last_meal, NULL);
	if (print_status(philo, index + 1, "is eating") != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	usleep(philo->settings->time_to_eat * 1000);
	pthread_mutex_lock(&philo->write_lock);
	single_philo->meals_left--;
	pthread_mutex_unlock(&philo->write_lock);
	release_fork(philo, index);
	release_fork(philo, (index + 1) % philo->settings->nb_philo);
	return (EXIT_SUCCESS);
}

int	take_fork(t_simul *philo, int philo_index, int fork_index)
{
	if (pthread_mutex_lock(&philo->forks[fork_index]) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (print_status(philo, philo_index + 1, "has taken a fork") != EXIT_SUCCESS)
	{
		release_fork(philo, fork_index);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	release_fork(t_simul *philo, int fork_index)
{
	if (pthread_mutex_unlock(&philo->forks[fork_index]) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	start_sleeping(t_simul *philo, t_single_philo *single_philo)
{
	int				index;
	struct timeval	*last_meal;
	int	time_before_death;

	index = single_philo->index;
	last_meal = &single_philo->last_meal;
	if (print_status(philo, index + 1, "is sleeping") != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	time_before_death = get_time_before_death(philo, last_meal);
	if (philo->settings->time_to_sleep > time_before_death)
	{
		usleep(time_before_death * 1000);
		if (print_status(philo, index + 1, "died") != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		pthread_mutex_lock(&philo->write_lock);
		philo->has_a_philo_died = 1;
		pthread_mutex_unlock(&philo->write_lock);
	}
	else
		usleep(philo->settings->time_to_sleep * 1000);
	return (EXIT_SUCCESS);
}

int	start_thinking(t_simul *philo, t_single_philo *single_philo)
{
	int				index;

	index = single_philo->index;
	if (print_status(philo, index + 1, "is thinking") != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
