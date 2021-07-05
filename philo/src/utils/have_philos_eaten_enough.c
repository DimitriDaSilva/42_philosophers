/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   have_philos_eaten_enough.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:47:20 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/05 18:12:55 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	have_philos_eaten_enough(t_simul *simul)
{
	int	check;
	int	i;

	if (simul->settings->nb_times_to_eat == -1)
		return (0);
	check = 1;
	i = 0;
	pthread_mutex_lock(&simul->meals_left_lock);
	while (i < simul->settings->nb_philo)
	{
		if (simul->philos[i].meals_left > 0)
		{
			check = 0;
			break ;
		}
		i++;
	}
	pthread_mutex_unlock(&simul->meals_left_lock);
	return (check);
}
