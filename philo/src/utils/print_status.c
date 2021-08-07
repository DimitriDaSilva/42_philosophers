/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 09:38:27 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/30 11:34:23 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
** Takes arguments to convert into a single string formated status
** @param:	- [t_simul *] base struct of the program
**			- [int] philo index. 1 based index
**			- [char *] life status to write after index
** @return:	[char *] status (to be freed by caller)
*/

static char	*get_status(t_simul *simul, int nb_index, char *life_status)
{
	char	*status;
	char	*timestamp;
	char	*index;

	status = ft_calloc(STATUS_BUFFER, sizeof(char));
	if (!status)
		return (NULL);
	timestamp = get_timestamp(&simul->prog_start);
	if (!timestamp)
		return (NULL);
	index = ft_itoa(nb_index);
	if (!index)
		return (NULL);
	ft_strlcpy(status, timestamp, STATUS_BUFFER);
	free(timestamp);
	ft_strlcat(status, " ", STATUS_BUFFER);
	ft_strlcat(status, index, STATUS_BUFFER);
	free(index);
	ft_strlcat(status, " ", STATUS_BUFFER);
	ft_strlcat(status, life_status, STATUS_BUFFER);
	ft_strlcat(status, "\n", STATUS_BUFFER);
	return (status);
}

/*
** Prints status if simulation still hasn't finished
** @param:	- [t_simul *] base struct of the program
**			- [int] philo index. 1 based index
**			- [char *] life status to write after index
** @return:	[int] exit status (SUCCESS or FAILURE)
** Line-by-line comments:
** @5		Simulation is over if a philo has died or if they have already
**			ate enough (optional argument). The errors that will break the
**			main loop will come from here
** @7-8		We need to make sure to unlock the mutexes so that we don't
**			destroy locked mutexes
*/

int	print_status(t_simul *simul, int philo_index, char *life_status)
{
	char	*status;

	pthread_mutex_lock(&simul->death_lock);
	pthread_mutex_lock(&simul->meals_left_lock);
	if (simul->has_a_philo_died == 1 || have_philos_eaten_enough(simul))
	{
		pthread_mutex_unlock(&simul->death_lock);
		pthread_mutex_unlock(&simul->meals_left_lock);
		return (EXIT_FAILURE);
	}
	status = get_status(simul, philo_index, life_status);
	if (!status)
		return (EXIT_FAILURE);
	ft_putstr(status);
	free(status);
	pthread_mutex_unlock(&simul->death_lock);
	pthread_mutex_unlock(&simul->meals_left_lock);
	return (EXIT_SUCCESS);
}
