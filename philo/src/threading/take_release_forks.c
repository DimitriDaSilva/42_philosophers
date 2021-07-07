/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_release_forks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 11:43:00 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/07 17:00:35 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "take_release_forks.h"

/*
** A philo needs to hold two forks to eat
** @param:	- [t_simul *] base struct of the program
**			- [int] philo index. 0 based index
**			- [int] philo's first fork to grab. 0 based index
**			- [int] philo's second fork to grab. 0 based index
** @return:	[int] exit status (SUCCESS or FAILURE)
** Line-by-line comments:
** @5		If the second take_fork() failed, we need to release the first fork
**			otherwise we get a locked mutex destroyed error message
*/

int	take_two_forks(t_simul *simul,
		int philo_index,
		int first_fork,
		int second_fork)
{
	if (take_fork(simul, philo_index, first_fork) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	if (take_fork(simul, philo_index, second_fork) != EXIT_SUCCESS)
	{
		release_fork(simul, first_fork);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/*
** Take the fork (ie mutex_lock)
** @param:	- [t_simul *] base struct of the program
**			- [int] philo index. 0 based index
**			- [int] philo's fork to grab. 0 based index
** @return:	[int] exit status (SUCCESS or FAILURE)
** Line-by-line comments:
** @6		If print_status() failed (in case a philo has died or enough eaten),
**			we need to release the fork he just grabed
*/

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

/*
** Just need to release the fork. No message to print
** @param:	- [t_simul *] base struct of the program
**			- [int] philo's fork to release. 0 based index
** @return:	[int] exit status (SUCCESS or FAILURE)
*/

int	release_fork(t_simul *simul, int fork_index)
{
	if (pthread_mutex_unlock(&simul->forks[fork_index]) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
