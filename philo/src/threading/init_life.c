/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_life.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:58:13 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/03 17:56:36 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_life.h"

void	*init_life(void *arg)
{
	t_philo 		*philo;
	int				index;
	struct timeval	time_last_meal;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->write_lock);
	index = philo->index++;
	pthread_mutex_unlock(&philo->write_lock);
	memset(&time_last_meal, 0, sizeof(struct timeval));
	while (philo->is_one_philo_dead == 0)
	{
		if (start_taking_forks(philo, index) != EXIT_SUCCESS)
		   return (NULL);
		gettimeofday(&time_last_meal, NULL);
		if (start_eating(philo, index) != EXIT_SUCCESS)
		   return (NULL);
		if (start_sleeping(philo, index) != EXIT_SUCCESS)
		   return (NULL);
		if (is_philo_dead(philo, index, time_last_meal))
			break ;
		if (start_thinking(philo, index) != EXIT_SUCCESS)
		   return (NULL);
	}
	return (NULL);
}

int start_taking_forks(t_philo *philo, int index)
{
	if (index % 2 != 0)
	{
		if (take_fork(philo, index, index) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
   		if (take_fork(philo, index, (index + 1) % philo->settings->nb_philo) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
	}
	else
	{
		if (take_fork(philo, index, (index + 1) % philo->settings->nb_philo) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		if (take_fork(philo, index, index) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
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

int	is_philo_dead(t_philo *philo, int index, struct timeval time_last_meal)
{
	struct timeval	curr_time;
	long			timediff;

	gettimeofday(&curr_time, NULL);
	timediff = get_time_diff(curr_time, time_last_meal);
	if (timediff > philo->settings->time_to_die)
	{
		if (print_status(philo, index + 1, "died") != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		philo->is_one_philo_dead = 1;
	}
	return (EXIT_SUCCESS);
}
