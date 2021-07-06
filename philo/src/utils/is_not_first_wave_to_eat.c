/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_not_first_wave_to_eat.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 09:40:42 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/06 09:54:22 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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
