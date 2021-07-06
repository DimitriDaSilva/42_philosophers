/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_living.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:26:04 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/06 11:17:04 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "start_living.h"

void	*start_living(void *arg)
{
	static int	i = 0;
	t_simul		*simul;
	t_philo		*philo;

	simul = (t_simul *)arg;
	pthread_mutex_lock(&simul->increment_lock);
	philo = &simul->philos[i++];
	pthread_mutex_unlock(&simul->increment_lock);
	while (1)
	{
		if (start_taking_forks(simul, philo) != EXIT_SUCCESS)
			break ;
		if (start_eating(simul, philo) != EXIT_SUCCESS)
			break ;
		if (start_sleeping(simul, philo) != EXIT_SUCCESS)
			break ;
		if (start_thinking(simul, philo) != EXIT_SUCCESS)
			break ;
	}
	return (NULL);
}

int	start_taking_forks(t_simul *philo, t_philo *single_philo)
{
	int				index;
	struct timeval	*last_meal;
	int				time_before_death;
	int				second_fork_index;

	index = single_philo->index;
	last_meal = &single_philo->last_meal;
	if (single_philo->has_had_first_meal == 1)
	{
		time_before_death = get_time_before_death(philo, last_meal);
		if (philo->settings->time_to_eat * 2 > time_before_death + philo->settings->time_to_die)
		{
			usleep(time_before_death * 1000);
			if (print_status(philo, index + 1, "died") != EXIT_SUCCESS)
				return (EXIT_FAILURE);
			pthread_mutex_lock(&philo->death_lock);
			philo->has_a_philo_died = 1;
			pthread_mutex_unlock(&philo->death_lock);
			return (EXIT_FAILURE);
		}
	}
	else if (!is_first_wave_to_eat(philo, single_philo))
	{
		time_before_death = get_time_before_death(philo, last_meal);
		if (philo->settings->time_to_eat > time_before_death)
		{
			usleep(time_before_death * 1000);
			if (print_status(philo, index + 1, "died") != EXIT_SUCCESS)
				return (EXIT_FAILURE);
			pthread_mutex_lock(&philo->death_lock);
			philo->has_a_philo_died = 1;
			pthread_mutex_unlock(&philo->death_lock);
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

int	start_eating(t_simul *simul, t_philo *philo)
{
	int				index;
	struct timeval	*last_meal;

	index = philo->index;
	last_meal = &philo->last_meal;
	gettimeofday(last_meal, NULL);
	if (print_status(simul, index + 1, "is eating") != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	usleep(simul->settings->time_to_eat * 1000);
	pthread_mutex_lock(&simul->meals_left_lock);
	philo->meals_left--;
	pthread_mutex_unlock(&simul->meals_left_lock);
	if (philo->has_had_first_meal == 0)
		philo->has_had_first_meal = 1;
	release_fork(simul, index);
	release_fork(simul, (index + 1) % simul->settings->nb_philo);
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

int	start_sleeping(t_simul *philo, t_philo *single_philo)
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
		pthread_mutex_lock(&philo->death_lock);
		philo->has_a_philo_died = 1;
		pthread_mutex_unlock(&philo->death_lock);
	}
	else
		usleep(philo->settings->time_to_sleep * 1000);
	return (EXIT_SUCCESS);
}

int	start_thinking(t_simul *philo, t_philo *single_philo)
{
	int				index;

	index = single_philo->index;
	if (print_status(philo, index + 1, "is thinking") != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
