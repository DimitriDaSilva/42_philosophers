/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_first_wave_to_eat.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 09:40:42 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/07 17:27:52 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
** Checks if the philo is part of the first wave of philos to eat. As a rule of
** thumb, odd-indexed philos eat first
** @param:	- [t_simul *] base struct of the program
**			- [t_philo *] represents the info specific to this thread's philo
** @return:	[int] true or false
** Line-by-line comments:
** @8-9		If there is an even number of philos then all odd-indexed philos eat
**			first
** @10-11	Only exception to the rule of thumb is if there is an odd number of
**			philos and he's the last on the bunch. Because he'll try to reach
**			for the first's philo fork but it will be held
** @12-13	All even-indexed philos eat after a first wave. Life is unfair
*/

int	is_first_wave_to_eat(t_simul *simul, t_philo *philo)
{
	int	check;
	int	nb_of_philo;
	int	index_philo;

	check = 1;
	nb_of_philo = simul->settings->nb_philo;
	index_philo = philo->index + 1;
	if (!ft_is_even(index_philo) && ft_is_even(nb_of_philo))
		check = 1;
	else if (!ft_is_even(index_philo) && !ft_is_even(nb_of_philo)
		&& index_philo == nb_of_philo)
		check = 0;
	else if (ft_is_even(index_philo))
		check = 0;
	return (check);
}
