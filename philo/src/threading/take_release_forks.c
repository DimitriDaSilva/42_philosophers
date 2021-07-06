/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_release_forks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 11:43:00 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/06 16:28:45 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "take_release_forks.h"

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
