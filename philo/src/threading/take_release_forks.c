/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_release_forks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 11:43:00 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/06 12:07:51 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "take_release_forks.h"

int	start_taking_forks(t_simul *philo, t_philo *single_philo)
{
	int				index;
	int				second_fork_index;

	index = single_philo->index;
	if (is_philo_about_to_die(philo, single_philo) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	second_fork_index = (index + 1) % philo->settings->nb_philo;
	if (!ft_is_even(index))
	{
		if (take_two_forks(philo, index, index, second_fork_index))
			return (EXIT_FAILURE);
	}
	else
	{
		if (take_two_forks(philo, index, second_fork_index, index))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	is_philo_about_to_die(t_simul *philo, t_philo *single_philo)
{
	int				index;
	struct timeval	*last_meal;
	int				time_before_death;

	index = single_philo->index;
	last_meal = &single_philo->last_meal;
	if (single_philo->has_had_first_meal == 1
		|| !is_first_wave_to_eat(philo, single_philo))
	{
		time_before_death = get_time_before_death(philo, last_meal);
		if (philo->settings->time_to_eat * 2 > \
				time_before_death + philo->settings->time_to_die)
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
	return (EXIT_SUCCESS);
}

int	take_two_forks(t_simul *philo,
		int philo_index,
		int first_fork,
		int second_fork)
{
	if (take_fork(philo, philo_index, first_fork) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (take_fork(philo, philo_index, second_fork) != EXIT_SUCCESS)
	{
		release_fork(philo, first_fork);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	take_fork(t_simul *simul, int philo_index, int fork_index)
{
	if (pthread_mutex_lock(&simul->forks[fork_index]) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (print_status(simul, philo_index + 1, "has "
			"taken a fork") != EXIT_SUCCESS)
	{
		release_fork(simul, fork_index);
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
