/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_living.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 12:26:04 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/20 11:09:56 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "start_living.h"

/*
** Entrypoint for the threads
** @param:	- [void *] passed t_simul *
** @return:	[void *] return value (not used in this program)
** Line-by-line comments:
** @6-8		We increment i so that the philo var points to a different item
**			of the array of philos in each thread
** @9		Infinite loop that is broken if either of the function calls fails.
**			That can happen for 2 reasons: a philo has died or they have reached
** 			the number of meals required. These checks are made before printing
**			anything. We return EXIT_FAILURE from the print_status in that case
*/

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

/*
** Before start_eating, we need to make sure that philo is holding 2 forks. But
** he needs to wait for them to be available
** @param:	- [t_simul *] base struct of the program
**			- [t_philo *] represents the info specific to this thread's philo
** @return:	[int] exit status (SUCCESS or FAILURE)
** Line-by-line comments:
** @line-line	comment
** @7-12	In the case he won't have time to eat before dying we don't bother
** 			try to take forks. We wait for him to die before writing that he's
**			dead (in start_dying())
** @13-24	Setting a thread hierarchy to avoid potential deadlocks
*/

int	start_taking_forks(t_simul *simul, t_philo *philo)
{
	int	time_before_death;
	int	index;
	int	first_fork;
	int	second_fork;

	index = philo->index;
	if (!will_get_forks_on_time(simul, philo))
	{
		time_before_death = get_time_before_death(simul, &philo->last_meal);
		start_dying(simul, index, time_before_death);
		return (EXIT_FAILURE);
	}
	if (!ft_is_even(index))
	{
		first_fork = index;
		second_fork = (index + 1) % simul->settings->nb_philo;
	}
	else
	{
		first_fork = (index + 1) % simul->settings->nb_philo;
		second_fork = index;
	}
	if (take_two_forks(simul, index, first_fork, second_fork))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/*
** Already has the forks at this point. Only needs to make sure he has
** time_to_die > time_to_eat, otherwise we kill him
** @param:	- [t_simul *] base struct of the program
**			- [t_philo *] represents the info specific to this thread's philo
** @return:	[int] exit status (SUCCESS or FAILURE)
** Line-by-line comments:
** @5-6		Save when this meal starts to compute the time before death later
**			because time_to_die is from the moment he starts eating
** @9		If time_to_eat > time_to_die then he doesn't have even time to
**			finish eating that he's already dead
*/

int	start_eating(t_simul *simul, t_philo *philo)
{
	int	second_fork;
	int	time_before_death;

	second_fork = (philo->index + 1) % simul->settings->nb_philo;
	if (gettimeofday(&philo->last_meal, NULL) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (print_status(simul, philo->index + 1, "is eating") != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (simul->settings->time_to_eat > simul->settings->time_to_die)
	{
		time_before_death = get_time_before_death(simul, &philo->last_meal);
		start_dying(simul, philo->index, time_before_death);
		release_two_forks(simul, philo->index, second_fork);
		return (EXIT_FAILURE);
	}
	else
		usleep(simul->settings->time_to_eat * 1000);
	pthread_mutex_lock(&simul->meals_left_lock);
	philo->meals_left--;
	pthread_mutex_unlock(&simul->meals_left_lock);
	philo->has_had_first_meal = 1;
	if (release_two_forks(simul, philo->index, second_fork) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/*
** Sets philo to sleep based on the time he has left to live
** @param:	- [t_simul *] base struct of the program
**			- [t_philo *] represents the info specific to this thread's philo
** @return:	[int] exit status (SUCCESS or FAILURE)
** Line-by-line comments:
** @line-line	comment
** @9-10	Only really sleeps if he knows he has enough time to sleep. If he
**			doesn't he only sleeps for 'time_before_death' time
*/

int	start_sleeping(t_simul *simul, t_philo *philo)
{
	int				index;
	struct timeval	*last_meal;
	int				time_before_death;

	index = philo->index;
	last_meal = &philo->last_meal;
	if (print_status(simul, index + 1, "is sleeping") != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	time_before_death = get_time_before_death(simul, last_meal);
	if (simul->settings->time_to_sleep > time_before_death)
	{
		if (start_dying(simul, index, time_before_death) != EXIT_SUCCESS)
			return (EXIT_FAILURE);
	}
	else
		usleep(simul->settings->time_to_sleep * 1000);
	return (EXIT_SUCCESS);
}

/*
** Nothing special to do here. Thinking isn't a timed activity. He basically
** thinks while there isn't a fork available
** @param:	- [t_simul *] base struct of the program
**			- [t_philo *] represents the info specific to this thread's philo
** @return:	[int] exit status (SUCCESS or FAILURE)
*/

int	start_thinking(t_simul *simul, t_philo *philo)
{
	int	index;

	index = philo->index;
	if (print_status(simul, index + 1, "is thinking") != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
