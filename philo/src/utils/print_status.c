/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 09:38:27 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/03 10:43:25 by dda-silv         ###   ########.fr       */
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
	timestamp = ft_itoa(curr_time.tv_sec - philo->program_start.tv_sec);
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
