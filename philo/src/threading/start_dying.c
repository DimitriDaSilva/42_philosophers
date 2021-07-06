/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dying.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:17:49 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/06 17:24:21 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "start_dying.h"

int	start_dying(t_simul *simul, int index, int time_before_death)
{
	usleep(time_before_death * 1000);
	if (print_status(simul, index, "died") != EXIT_SUCCESS)
		return (EXIT_FAILURE);
	pthread_mutex_lock(&simul->death_lock);
	simul->has_a_philo_died = 1;
	pthread_mutex_unlock(&simul->death_lock);
	return (EXIT_SUCCESS);
}
