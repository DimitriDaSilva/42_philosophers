/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_philo_about_to_die.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:28:17 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/07 18:23:02 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
** Function called by start_taking_forks() to check if it's worth waiting for
** one or instead they should just go and die (peacefully ofc)
** @param:	- [t_simul *] base struct of the program
**			- [t_philo *] represents the info specific to this thread's philo
** @return:	[int] true or false
** Line-by-line comments:
** @7		Two type of philos can die before taking forks:
**			- A philo that already has had a first meal because the second wave
**			will hold on to the forks for too long
**			- A philo being part of the lucky first wave to eat because he'll
**			realise that he won't have finished eating that he'll be dead
*/

int	is_philo_about_to_die(t_simul *simul, t_philo *philo)
{
	int				index;
	struct timeval	*last_meal;
	int				time_before_death;

	index = philo->index;
	last_meal = &philo->last_meal;
	if (philo->has_had_first_meal == 1)
	{
		time_before_death = get_time_before_death(simul, last_meal);
		if (simul->settings->time_to_eat * 2 > \
				time_before_death + simul->settings->time_to_die)
		{
			start_dying(simul, index, time_before_death);
			return (1);
		}
	}
	return (0);
}
