/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 09:38:27 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/03 16:58:26 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	print_status(t_philo *philo, int nb_index, char *status)
{
	struct timeval	curr_time;
	char			*timestamp;
	char			str[STATUS_BUFFER];
	char			*index;

	if (gettimeofday(&curr_time, NULL) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	timestamp = get_timestamp(curr_time, philo->program_start);
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
	return (EXIT_SUCCESS);
}

int	print_status_fork(t_philo *philo, int nb_index, char *status, int fork_index)
{
	struct timeval	curr_time;
	char			*timestamp;
	char			str[STATUS_BUFFER];
	char			*index;

	if (gettimeofday(&curr_time, NULL) != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	timestamp = get_timestamp(curr_time, philo->program_start);
	if (!timestamp)
		return (EXIT_FAILURE);
	index = ft_itoa(nb_index);
	if (!index)
		return (EXIT_FAILURE);
	char *fork = ft_itoa(fork_index);
	if (!fork)
		return (EXIT_FAILURE);
	ft_strlcpy(str, timestamp, STATUS_BUFFER);
	ft_strlcat(str, " ", STATUS_BUFFER);
	ft_strlcat(str, index, STATUS_BUFFER);
	ft_strlcat(str, " ", STATUS_BUFFER);
	ft_strlcat(str, status, STATUS_BUFFER);
	ft_strlcat(str, " ", STATUS_BUFFER);
	ft_strlcat(str, fork, STATUS_BUFFER);
	ft_strlcat(str, "\n", STATUS_BUFFER);
	ft_putstr(str);
	free(timestamp);
	free(index);
	free(fork);
	return (EXIT_SUCCESS);
}

char *get_timestamp(struct timeval curr_time, struct timeval program_start)
{
	char	*timestamp_str;
	long	timestamp_microseconds;
	long	timestamp_milliseconds;

	timestamp_microseconds = (long)((
				(curr_time.tv_sec - program_start.tv_sec) * 1000000
				+ (long)curr_time.tv_usec - (long)program_start.tv_usec));
	timestamp_milliseconds = timestamp_microseconds / 1000;
	timestamp_str = ft_itoa(timestamp_milliseconds);
	if (!timestamp_str)
		return (NULL);
	return (timestamp_str);
}
