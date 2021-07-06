/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_philo_about_to_die.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:28:17 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/06 17:26:09 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	is_philo_about_to_die(t_simul *simul, t_philo *philo)
{
	int				index;
	struct timeval	*last_meal;
	int				time_before_death;

	index = philo->index;
	last_meal = &philo->last_meal;
	if (philo->has_had_first_meal == 1
		|| is_first_wave_to_eat(simul, philo))
	{
		time_before_death = get_time_before_death(simul, last_meal);
		if (simul->settings->time_to_eat * 2 > \
				time_before_death + simul->settings->time_to_die)
		{
			start_dying(simul, index + 1, time_before_death);
			return (1);
		}
	}
	return (0);
}
