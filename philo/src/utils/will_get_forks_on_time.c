/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   will_get_forks_on_time.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 20:30:22 by dda-silv          #+#    #+#             */
/*   Updated: 2021/08/06 17:42:26 by dda-silv         ###   ########.fr       */
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
** @5-6		If there is only one philo there is also only one fork, then he
**			won't be able to eat
** @9-10	A philo that already has had a first meal but won't have a second
**			because the second wave will hold on to the forks for too long
*/

int	will_get_forks_on_time(t_simul *simul, t_philo *philo)
{
	int	check;
	int	nb_philo;
	int	time_to_eat;
	int	time_to_die;

	if (simul->settings->nb_philo == 1)
		return (0);
	nb_philo = simul->settings->nb_philo;
	time_to_eat = simul->settings->time_to_eat;
	time_to_die = simul->settings->time_to_die;
	if (philo->has_had_first_meal == 1 && time_to_eat * 2 > time_to_die)
		check = 0;
	else if (philo->has_had_first_meal == 1
		&& nb_philo == 3
		&& time_to_eat * 3 > time_to_die)
		check = 0;
	else
		check = 1;
	return (check);
}
