/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_life.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 19:58:13 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/05 10:35:54 by dda-silv         ###   ########.fr       */
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
	while (1)
	{
		if (start_taking_forks(philo, index, &time_last_meal) != EXIT_SUCCESS)
			break ;
		if (start_eating(philo, index, &time_last_meal) != EXIT_SUCCESS)
			break ;
		if (start_sleeping(philo, index, &time_last_meal) != EXIT_SUCCESS)
			break ;
		if (start_thinking(philo, index) != EXIT_SUCCESS)
			break ;
		/*pthread_mutex_lock(&philo->write_lock);*/
		/*if (philo->is_one_philo_dead == 1)*/
			/*break ;*/
		/*pthread_mutex_unlock(&philo->write_lock);*/
	}
	return (NULL);
}

int start_taking_forks(t_philo *philo, int index, struct timeval *lastmeal)
{
	int	time_before_death;

	if (lastmeal->tv_usec != 0)
	{
		time_before_death = get_time_before_death(philo, lastmeal);
		/*printf("Time_before_death: \"%d\"\n", time_before_death);*/
	   if (philo->settings->time_to_eat > time_before_death)
	   {
		   	usleep(time_before_death * 1000);
			/*printf("Philo %d about to die bruh\n", index + 1);*/
		   	if (print_status(philo, index + 1, "died") != EXIT_SUCCESS)
				return (EXIT_FAILURE);
		   	pthread_mutex_lock(&philo->write_lock);
		   	philo->is_one_philo_dead = 1;
		   	pthread_mutex_unlock(&philo->write_lock);
			/*printf("Finished\n");*/
		   	return (EXIT_FAILURE);
	   }
	}
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


int start_eating(t_philo *philo, int index, struct timeval *lastmeal)
{
	gettimeofday(lastmeal, NULL);
	if (print_status(philo, index + 1, "is eating") != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	usleep(philo->settings->time_to_eat * 1000);
	release_fork(philo, index);
	release_fork(philo, (index + 1) % philo->settings->nb_philo);
	/*if (index + 1 == 2)*/
		/*printf("Philo 2 finished eating\n");*/
	return (EXIT_SUCCESS);
}

int take_fork(t_philo *philo, int philo_index, int fork_index)
{
	if (pthread_mutex_lock(&philo->forks[fork_index]) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (print_status(philo, philo_index + 1, "has taken a fork") != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int release_fork(t_philo *philo, int fork_index)
{
	if (pthread_mutex_unlock(&philo->forks[fork_index]) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int start_sleeping(t_philo *philo, int index, struct timeval *lastmeal)
{
	int	time_before_death;

	if (print_status(philo, index + 1, "is sleeping") != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	time_before_death = get_time_before_death(philo, lastmeal);
	if (philo->settings->time_to_sleep > time_before_death)
	{
		usleep(time_before_death * 1000);
		if (print_status(philo, index + 1, "died") != EXIT_SUCCESS)
			return (EXIT_FAILURE);
		pthread_mutex_lock(&philo->write_lock);
		philo->is_one_philo_dead = 1;
		pthread_mutex_unlock(&philo->write_lock);
	}
	else
		usleep(philo->settings->time_to_sleep * 1000);
	return (EXIT_SUCCESS);
}

int start_thinking(t_philo *philo, int index)
{
	if (print_status(philo, index + 1, "is thinking") != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
