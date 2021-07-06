/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_philo_about_to_die.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:28:17 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/06 16:50:02 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	is_philo_about_to_die(t_simul *philo, t_philo *single_philo)
{
	int				index;
	struct timeval	*last_meal;
	int				time_before_death;

	index = single_philo->index;
	last_meal = &single_philo->last_meal;
	if (single_philo->has_had_first_meal == 1
		|| is_first_wave_to_eat(philo, single_philo))
	{
		time_before_death = get_time_before_death(philo, last_meal);
		if (philo->settings->time_to_eat * 2 > \
				time_before_death + philo->settings->time_to_die)
		{
			usleep(time_before_death * 1000);
			if (print_status(philo, index + 1, "died") != EXIT_SUCCESS)
				return (1);
			pthread_mutex_lock(&philo->death_lock);
			philo->has_a_philo_died = 1;
			pthread_mutex_unlock(&philo->death_lock);
			return (1);
		}
	}
	return (0);
}
