/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   have_philos_eaten_enough.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dda-silv <dda-silv@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:47:20 by dda-silv          #+#    #+#             */
/*   Updated: 2021/07/05 16:13:35 by dda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	have_philos_eaten_enough(t_philo *simulation)
{
	int	check;
	int	i;

	if (simulation->settings->nb_times_to_eat == -1)
		return (0);
	check = 1;
	i = 0;
	while (i < simulation->settings->nb_philo)
	{
		if (simulation->philos[i].meals_left > 0)
		{
			check = 0;
			break ;
		}
		i++;
	}
	return (check);
}
