/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 09:38:27 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/05 17:56:20 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	print_status(t_simul *philo, int nb_index, char *status)
{
	struct timeval	curr_time;
	char			*timestamp;
	char			str[STATUS_BUFFER];
	char			*index;

	pthread_mutex_lock(&philo->write_lock);
	if (philo->has_a_philo_died == 1 || have_philos_eaten_enough(philo))
	{
		pthread_mutex_unlock(&philo->write_lock);
		return (EXIT_FAILURE);
	}
	if (gettimeofday(&curr_time, NULL) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	timestamp = get_timestamp(&curr_time, &philo->prog_start);
	if (!timestamp)
		return (EXIT_FAILURE);
	index = ft_itoa(nb_index);
	if (!index)
		return (EXIT_FAILURE);
	ft_strlcpy(str, timestamp, STATUS_BUFFER);
	ft_strlcat(str, " ", STATUS_BUFFER);
	ft_strlcat(str, index, STATUS_BUFFER);
	ft_strlcat(str, " ", STATUS_BUFFER);
	ft_strlcat(str, status, STATUS_BUFFER);
	ft_strlcat(str, "\n", STATUS_BUFFER);
	ft_putstr(str);
	free(timestamp);
	free(index);
	pthread_mutex_unlock(&philo->write_lock);
	return (EXIT_SUCCESS);
}
